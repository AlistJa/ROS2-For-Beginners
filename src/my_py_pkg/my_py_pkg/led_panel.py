#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import SetLed
from my_robot_interfaces.msg import LedStates

class LedPanelNode(Node): #
    def __init__(self):
        super().__init__("led_panel")
        self.declare_parameter("led_states", [False, False, False])
        self.led_panel = self.get_parameter("led_states").value
        self.publisher_ = self.create_publisher(LedStates, "led_panel_states", 10)
        self.timer_ = self.create_timer(1.0, self.publish_led_panel_state)
        self.server_ = self.create_service(
            SetLed, "set_led", self.callback_set_led)
        self.get_logger().info("Led Panel publisher has been started.")        

    def publish_led_panel_state(self):
        msg = LedStates()
        msg.led = self.led_panel
        self.publisher_.publish(msg)

    def callback_set_led(self, request, response):
        self.led_panel[request.number - 1] = request.state
        response.success = True
        self.publish_led_panel_state()
        return response

def main(args=None):
    rclpy.init(args=args)
    node = LedPanelNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()