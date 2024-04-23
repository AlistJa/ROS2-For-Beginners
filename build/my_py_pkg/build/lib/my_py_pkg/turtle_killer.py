#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial

from turtlesim.srv import Kill
from my_robot_interfaces.msg import TurtleSpawned
from my_robot_interfaces.msg import TurtleKilled

class TurtleKillerNode(Node): 
    def __init__(self):
        super().__init__("turtle_killer") 

        self.subscriber_ = self.create_subscription(
            TurtleSpawned, "turtle_spawner", self.callback_turtle_spawned, 10)
        self.publisher_ = self.create_publisher(TurtleKilled, "turtle_killed", 2)
#        self.timer_ = self.create_timer(1.0, self.publish_turtle_killed)
        self.turtles_ = []
        self.get_logger().info("Turtle Killer has been started.")

    def publish_turtle_killed(self, name):
        msg = TurtleKilled()
        msg.name = self.name
        self.publisher_.publish(msg)
        
    def callback_turtles_spawned(self, msg):
        self.turtles_ = msg.turtles
        try:
            self.call_turtlesim_server(self.turtles_.pop(0))
        except Exception as e:
            self.get_logger().info(f"Tried to kill nonexisting turtle")

    def callback_turtle_spawned(self, msg):
        try:
            self.call_turtlesim_server(msg.turtle)
            self.get_logger().info(f"Turtle {msg.turtle} killed")
        except Exception as e:
            self.get_logger().info(f"Tried to kill nonexisting turtle {(e, )}")

    def call_turtlesim_server(self, turtle):
        client_ = self.create_client(Kill, "kill")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Turtlesim")
        request = Kill.Request()
        request.name = turtle
        future = client_.call_async(request)
        future.add_done_callback(partial(self.callback_kill_turtle, turtle=turtle))
        self.publish_turtle_killed(turtle)

    def callback_kill_turtle(self, future, turtle):
        try:
            response = future.result()
            #self.get_logger().info(f"Battery status change result: {response}")
        except Exception as e:
            self.get_logger().error(f"Service call failed {(e,)}")


def main(args=None):
    rclpy.init(args=args)
    node = TurtleKillerNode() 
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
