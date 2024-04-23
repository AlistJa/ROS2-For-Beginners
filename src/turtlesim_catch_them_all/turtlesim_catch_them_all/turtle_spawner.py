#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
import random
from functools import partial

from turtlesim.srv import Spawn
from turtlesim.srv import Kill

from my_robot_interfaces.msg import TurtleArray
from my_robot_interfaces.msg import Turtle
from my_robot_interfaces.msg import TurtleKilled
from my_robot_interfaces.srv import TurtleCoordinates
from my_robot_interfaces.srv import TurtleCatch


class TurleSpawnerNode(Node): 
    def __init__(self):
        super().__init__("turtle_spawner")
        self.declare_parameter("spawn_rate", 1.0)
        self.spawn_rate_ = self.get_parameter("spawn_rate").value
        self.turtle_counter_ = 1
        self.turtle_name_prefix = "turtle"
        self.timer_ =  self.create_timer(self.spawn_rate_, self.spawn_new_turtle)
        self.alive_turtles_ = []
        self.server_ = self.create_service(
            TurtleCatch, "turtle_catch", self.callback_turtle_catch)
        self.publisher_ = self.create_publisher(TurtleArray, "alive_turtles", 10)
#        self.timer_ = self.create_timer(1.0, self.publish_alive_turtles)

        self.get_logger().info(f"Turtle Spawner node has been started")

    def publish_alive_turtles(self):
        msg = TurtleArray()
        msg.turtles = self.alive_turtles_
        self.publisher_.publish(msg)

    def callback_turtle_catch(self, request, response):
        name = request.name
#        self.get_logger().info(f"{self.turtles_.get(name)}")
        if(request.name != None):
            self.call_kill_server(name)
            response.success =  True
        else:
            response.success = False
        return response

    def call_kill_server(self, turtle_name):
        client_ = self.create_client(Kill, "kill")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Kill")
        request = Kill.Request()
        request.name = turtle_name
        future = client_.call_async(request)
        future.add_done_callback(partial(
            self.callback_kill_turtle, 
            turtle_name=turtle_name))
                                 
    def callback_kill_turtle(self, future, turtle_name):
        try:
            response = future.result()
            for (i, turtle) in enumerate(self.alive_turtles_):
                if turtle.name == turtle_name:
                    del self.alive_turtles_[i]
 #           self.alive_turtles_.pop([self.alive_turtles_.index(i) for i in self.alive_turtles_ if i.name == turtle_name][0])
#            self.get_logger().info(f"{[self.alive_turtles_.index(i) for i in self.alive_turtles_ if i.name == turtle_name]}")
            self.publish_alive_turtles()
        except Exception as e:
            self.get_logger().error(f"Service call failed {(e,)}")

    def spawn_new_turtle(self):
        self.turtle_counter_ += 1
        x = random.uniform(0.1, 10.9)
        y = random.uniform(0.1, 10.9)
        theta = random.uniform(0.0, 2 * math.pi)
        name = self.turtle_name_prefix + str(self.turtle_counter_)
        self.call_spawn_server(name, x, y, theta)

    def call_spawn_server(self, turtle_name, x, y, theta):
        client_ = self.create_client(Spawn, "spawn")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Spawn")
        request = Spawn.Request()
        request.x = x
        request.y = y
        request.theta = theta
        request.name = turtle_name
        future = client_.call_async(request)
        future.add_done_callback(partial(
            self.callback_spawn_turtle, 
            turtle_name=turtle_name,
            x=x,
            y=y, 
            theta=theta))
                                 
    def callback_spawn_turtle(self, future, turtle_name, x, y, theta):
        try:
            response = future.result()
            new_turtle = Turtle()
            new_turtle.x = x
            new_turtle.y = y
            new_turtle.theta = theta
            new_turtle.name = turtle_name
            self.alive_turtles_.append(new_turtle)
            self.publish_alive_turtles()
        except Exception as e:
            self.get_logger().error(f"Service call failed {(e,)}")

def main(args=None):
    rclpy.init(args=args)
    node = TurleSpawnerNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
