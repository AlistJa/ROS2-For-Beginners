#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "example_interfaces/srv/set_bool.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class NumberCounterNode : public rclcpp::Node 
{
public:
    NumberCounterNode() : Node("number_counter"), counter_(0) 
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>("number", 10,
            std::bind(&NumberCounterNode::callbackNumber, this, std::placeholders::_1));
        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_counter", 10);

        server_ = this->create_service<example_interfaces::srv::SetBool>("reset_counter", std::bind(&NumberCounterNode::resetNumberCounter, this, _1, _2));

        RCLCPP_INFO(this->get_logger(), "Number Counter has been started.");        
    }

private:
    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        this->counter_ += msg->data;
        this->publishNumberCounter();
    //    RCLCPP_INFO(this->get_logger(), "%ld", this->counter_);
    }

    void publishNumberCounter()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = std::int64_t(this->counter_);
        publisher_->publish(msg);
     //   RCLCPP_INFO(this->get_logger(), "%ld", this->counter_);

    }

    void resetNumberCounter(const example_interfaces::srv::SetBool::Request::SharedPtr request,
        const example_interfaces::srv::SetBool::Response::SharedPtr response)
    {
        if(request->data == true)
        {
            this->counter_ = 0;
            response->success = true;
            response->message = "Succesful reset";
            RCLCPP_INFO(this->get_logger(), "Number counter has been reset");
        }
        else
        {
            response->success = false;
            response->message = "Reset failed";
            RCLCPP_INFO(this->get_logger(), "Number counter reset failed");
        }

    }
    int64_t counter_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr server_;


};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
