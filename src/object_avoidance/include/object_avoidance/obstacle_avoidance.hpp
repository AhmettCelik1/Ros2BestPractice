#pragma once 
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <string>

namespace obstacle_avoidance{
    class Avoidance : public rclcpp ::Node{
        public:
           Avoidance();
           void control_cycle();
           void laser_callback(sensor_msgs::msg::LaserScan::UniquePtr msg);
        private:
           rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_pub;
           rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr laser_sub;
           rclcpp::TimerBase::SharedPtr timer_;
           sensor_msgs::msg::LaserScan::SharedPtr distance;
           geometry_msgs::msg::Twist velocity_data;
           double stop_speed;
    };

}//namespace obstacle avoidance


