#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import SetLed
from functools import partial


class BatteryNode(Node): 
    def __init__(self):
        super().__init__("battery")
        self.battery_state = "full"
        self.last_time_battery_state_changed = self.get_current_time_seconds()
        self.battery_timer_ = self.create_timer(0.1, self.check_battery_state)
        self.get_logger().info(f"Battery node has been started")

    def get_current_time_seconds(self):
        secs, nsecs  = self.get_clock().now().seconds_nanoseconds()
        return secs + nsecs / 1e9
    
    def check_battery_state(self):
        time_now = self.get_current_time_seconds()
        if self.battery_state == "full":
            if time_now - self.last_time_battery_state_changed > 4.0:
                self.battery_state = "empty"
                self.get_logger().info("Battery empty, charging battery")
                self.last_time_battery_state_changed = time_now
                self.call_led_panel_server(1, False)
                self.call_led_panel_server(2, False)
                self.call_led_panel_server(3, False)
        else:
            if time_now - self.last_time_battery_state_changed > 6.0:
                self.battery_state = "full"
                self.get_logger().info("Battery full")
                self.last_time_battery_state_changed = time_now
                self.call_led_panel_server(1, True)
                self.call_led_panel_server(2, True)
                self.call_led_panel_server(3, True)

    def call_led_panel_server(self, number, state):
        client_ = self.create_client(SetLed, "set_led")
        while not client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Set Led")
        request = SetLed.Request()
        request.number = number
        request.state = state

        future = client_.call_async(request)
        future.add_done_callback(partial(self.callback_set_led, number=number, state=state))
                                 
    def callback_set_led(self, future, number, state):
        try:
            response = future.result()
            #self.get_logger().info(f"Battery status change result: {response}")
        except Exception as e:
            self.get_logger().error(f"Service call failed {(e,)}")


def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode() 
    rclpy.spin(node)
    rclpy.shutdown()
    
if __name__ == "__main__":
    main()