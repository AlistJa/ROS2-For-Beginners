#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from random import randint, random
from functools import partial

from turtlesim.srv import Spawn

from my_robot_interfaces.msg import TurtleSpawned
from my_robot_interfaces.srv import TurtleCoordinates
from my_robot_interfaces.msg import TurtleKilled


class TurleSpawnerNode(Node): 
    def __init__(self):
        super().__init__("turtle_spawner") 
        self.turtle_counter_ = 2
        self.name_ = "turtle" + str(self.turtle_counter_)
#        self.timer_ =  self.create_timer(10, self.spawn_turtle)
        self.turtle_ = {"x": 0, "y": 0, "theta": 0.0}
        self.turtles_ = {}
#        self.server_ = self.create_service(
#            TurtleCoordinates, "turtle_coordinates", self.callback_turtle_coordinates)
#        self.publisher_ = self.create_publisher(TurtlesSpawned, "turtle_spawner", 2)
        self.publisher_ = self.create_publisher(TurtleSpawned, "turtle_spawner", 2)
        self.timer_ = self.create_timer(1.0, self.publish_turtles)
        self.subscriber_ = self.create_subscription(
            TurtleKilled, "turtle_killed", self.callback_turtle_killed, 10)
        self.spawn_turtle()
        self.get_logger().info(f"Turtle Spawner node has been started")

    def callback_turtle_killed(self, msg):
        try:
            self.spawn_turtle()
            self.get_logger().info("Turtle spawned")
        except Exception as e:
            self.get_logger().info(f"Error")

    def callback_turtle_coordinates(self, request, response):
        name = request.name
        self.get_logger().info(f"{self.turtles_.get(name)}")
        if(self.turtles_.get(request.name) != None):
            response.x = self.turtles_.get(request.name).get("x")
            response.y = self.turtles_.get(request.name).get("y")
#        self.publish_turtles()
        return response

    def publish_turtles(self):
        msg = TurtleSpawned()
        msg.turtles = self.turtles_.keys()
        self.publisher_.publish(msg)

    def publish_turtle(self, name):
        msg = TurtleSpawned()
        msg.turtle = name
        self.publisher_.publish(msg)
        self.get_logger().info(f"Turtle {name} spawned")

    def spawn_turtle(self):
        self.turtle_["x"] = float(randint(0, 10))
        self.turtle_["y"] = float(randint(0, 10))
        self.turtle_["theta"] = random() * 360
        client_ = self.create_client(Spawn, "spawn")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Spawn")
        request = Spawn.Request()
        request.x = self.turtle_["x"]
        request.y = self.turtle_["y"]
        request.theta = self.turtle_["theta"]
        request.name = self.name_
        future = client_.call_async(request)
        future.add_done_callback(partial(
            self.callback_spawn_turtle, 
            x=self.turtle_["x"], 
            y=self.turtle_["y"], 
            theta=self.turtle_["theta"],
            name=self.name_))
#        self.turtles_[self.name_] = self.turtle_
#        self.get_logger().info(f'Turtle {self.name_} {self.turtles_[self.name_]} created')
        self.publish_turtle(self.name_)
        self.turtle_counter_ += 1
        self.name_ = "turtle" + str(self.turtle_counter_)
                                 
    def callback_spawn_turtle(self, future, x, y, theta, name):
        try:
            response = future.result()
        except Exception as e:
            self.get_logger().error(f"Service call failed {(e,)}")

def main(args=None):
    rclpy.init(args=args)
    node = TurleSpawnerNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
