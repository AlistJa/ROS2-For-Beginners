#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import Int64
from example_interfaces.srv import SetBool

class NumberCounterNode(Node):
    def __init__(self):
        super().__init__("number_counter") 

        self.counter_ = 0

        self.subscriber_ = self.create_subscription(
            Int64, "number", self.callback_number, 10)
        self.publisher_ = self.create_publisher(Int64, "number_count", 10)
        self.server_ = self.create_service(
            SetBool, "reset_counter", self.callback_reset_counter)     
        self.get_logger().info("Number Counter has been started.")

    def callback_number(self, msg):
        self.counter_ += msg.data
        self.publish_number_count()
    #    self.get_logger().info(f'{self.counter_}')

    def publish_number_count(self):
        #self.get_logger().info("X")
        msg = Int64()
        msg.data = self.counter_
        self.publisher_.publish(msg)
#        self.get_logger().info(f'{msg.data}')
        
    def callback_reset_counter(self, request, response):
        if (request.data == True):
            self.counter_ = 0
            response.success = True
            response.message = "Successful reset."
            self.get_logger().info("Successful reset of the number counter")
        else:
            response.success = False
            response.message = "Reset not successful"
            self.get_logger().info("Reset of the number counter failed")
        return response



def main(args=None):
    rclpy.init(args=args)
    node = NumberCounterNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
