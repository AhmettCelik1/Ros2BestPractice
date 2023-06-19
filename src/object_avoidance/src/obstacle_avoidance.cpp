#include "object_avoidance/obstacle_avoidance.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <memory>

using namespace std::chrono_literals;

namespace obstacle_avoidance {

    using std::placeholders::_1;

    Avoidance::Avoidance() : Node("obstacle_avoidance") {
        vel_pub = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        laser_sub = this->create_subscription<sensor_msgs::msg::LaserScan>("/scan", 1, std::bind(&Avoidance::laser_callback, this, _1));
        timer_ = this->create_wall_timer(500ms, std::bind(&Avoidance::control_cycle, this));
        RCLCPP_INFO(this->get_logger(), "Node is activated");
    }

    void Avoidance::laser_callback(sensor_msgs::msg::LaserScan::UniquePtr msg) {
        distance = std::move(msg);
    }

    void Avoidance::control_cycle() {
        velocity_data.linear.x = std::abs(0.2);

        // Check if the robot senses an object in its front, then send a velocity of 0.0 to stop the robot
        if (distance->ranges[distance->ranges.size() / 2] < 2) {
            double stop_speed = 0.0;
            velocity_data.linear.x = stop_speed;
        }

        vel_pub->publish(velocity_data);
    }
} // end namespace obstacle_avoidance

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<obstacle_avoidance::Avoidance>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
