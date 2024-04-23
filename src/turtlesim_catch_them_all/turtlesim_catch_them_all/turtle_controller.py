#!/usr/bin/env python3
import math
import rclpy
import random
from functools import partial
from rclpy.node import Node

from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from my_robot_interfaces.msg import TurtleArray
from my_robot_interfaces.msg import Turtle
from my_robot_interfaces.srv import TurtleCatch


class TurtleControllerNode(Node): 
    def __init__(self):
        super().__init__("turtle_controller")
        self.declare_parameter("linear_speed_gain", 2.0)
        self.linear_speed_gain_ = self.get_parameter("linear_speed_gain").value
        self.declare_parameter("angular_speed_gain", 6.0)
        self.angular_speed_gain_ = self.get_parameter("angular_speed_gain").value
        self.pose_ = None
        self.turtle_to_catch_ = None
        self.subscriber_turtle_pose_ = self.create_subscription(Pose, "turtle1/pose", self.callback_turtle_pose, 10)
        self.subscriber_alive_turtles_ = self.create_subscription(TurtleArray, "alive_turtles", self.callback_alive_turtles, 10)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.control_loop_timer = self.create_timer(0.01, self.control_loop)

    def callback_turtle_pose(self, msg):
        self.pose_ = msg

    def callback_alive_turtles(self, msg):
        max_len = [0, 0]
        if len(msg.turtles) > 0:
            closest_distance = None
            closest_turtle = None
            for turtle in msg.turtles:
                dist_x = turtle.x - self.pose_.x
                dist_y = turtle.y - self.pose_.y
                distance = math.sqrt(dist_x ** 2 + dist_y ** 2)
                if closest_turtle == None or distance < closest_distance:
                    closest_turtle = turtle
                    closest_distance = distance

            self.turtle_to_catch_ = closest_turtle

    def call_turtle_catch_server(self, turtle_name):
        client_ = self.create_client(TurtleCatch, "turtle_catch")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Turtle Catch")
        request = TurtleCatch.Request()
        request.name = turtle_name

        future = client_.call_async(request)
        future.add_done_callback(partial(self.callback_catch_turtle, turtle_name=turtle_name))
                                 
    def callback_catch_turtle(self, future, turtle_name):
        try:
            response = future.result()
            if not response.success == True:
                self.get_logger().info(f"Error, could not catch {turtle_name} turtle")
        except Exception as e:
            self.get_logger().error(f"Service call failed {(e,)}")

    def control_loop(self):
        if self.pose_ == None or self.turtle_to_catch_ == None:
            return
        dist_x = self.turtle_to_catch_.x - self.pose_.x
        dist_y = self.turtle_to_catch_.y - self.pose_.y
        distance = math.sqrt(dist_x**2 + dist_y**2)

        msg = Twist()

        if distance > 0.5:
            msg.linear.x = self.linear_speed_gain_ * distance
            goal_theta = math.atan2(dist_y, dist_x)
            diff = goal_theta - self.pose_.theta
            if diff > math.pi:
                diff -= 2 * math.pi
            elif diff < -math.pi:
                diff += 2 * math.pi
            msg.angular.z = self.angular_speed_gain_ * diff
        else:
            msg.linear.x = 0.0
            msg.angular.z = 0.0
            self.call_turtle_catch_server(self.turtle_to_catch_.name)
            self.turtle_to_catch_ = None

        self.cmd_vel_publisher_.publish(msg)
#        self.get_logger().info(f"{self.turtle_to_catch_.name}")
      

def main(args=None):
    rclpy.init(args=args)
    node = TurtleControllerNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
