#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class HardwareStatusPublisher : public rclcpp::Node 
{
public:
    HardwareStatusPublisher() : Node("hardware_status_publisher") 
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_status", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), 
            std::bind(&HardwareStatusPublisher::publishHardwareStatus, this));
        RCLCPP_INFO(this->get_logger(), "Hardware Status Publisher has been started.");        
    }

private:
    void publishHardwareStatus()
    {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temperature = 68;
        msg.are_motors_ready = false;
        msg.debug_message = "Motors not yet ready.";
        publisher_->publish(msg);
        // RCLCPP_INFO(this->get_logger(), "Message sent");

    }
    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisher>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
