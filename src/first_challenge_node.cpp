#include <rclcpp/rclcpp.hpp>
#include "first_challenge/first_challenge.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FirstChallenge>());
  rclcpp::shutdown();

  return 0;
}