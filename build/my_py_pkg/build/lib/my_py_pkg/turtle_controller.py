#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from turtlesim.msg import Pose


class TurtleControllerNode(Node): 
    def __init__(self):
        super().__init__("turtle_controller")
        self.subscriber_turtle_pose = self.create_subscription(Pose, "turtle1/pose", self.callback_turtle_pose, 10)


    def callback_turtle_pose(self, msg):
        self.get_logger().info(f"x: {msg.x} y: {msg.y} theta: {msg.theta}")

def main(args=None):
    rclpy.init(args=args)
    node = TurtleControllerNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
