#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class RoverNode : public rclcpp::Node
{
public:
    RoverNode();

private:
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    int x_;
    int y_;
};