#include "first_challenge/first_challenge.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  FirstChallenge fchallenge;
  fchallenge.process();
  rclcpp::shutdown();

  return 0;
}