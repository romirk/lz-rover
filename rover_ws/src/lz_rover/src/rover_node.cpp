#include <cstdio>
#include "lz_rover/rover_node.h"

RoverNode::RoverNode() : Node("lz_rover"), x_(1920 / 2), y_(1080 / 2)
{
  RCLCPP_INFO(this->get_logger(), "RoverNode constructor");
  publisher_ = this->create_publisher<std_msgs::msg::String>("rover", 10);
  timer_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&RoverNode::timer_callback, this));
  RCLCPP_INFO(this->get_logger(), "RoverNode constructor done");
}

void RoverNode::timer_callback()
{
  auto message = std_msgs::msg::String();
  message.data = std::to_string(x_) + "," + std::to_string(y_);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RoverNode>());
  rclcpp::shutdown();
  return 0;
}