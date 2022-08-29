#include "Ros2BestPractice/Ros2BestPractice.hpp"
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    std::string t_node_name{"ros2_best_practice"};

    std::shared_ptr<ros2_cpp_pkg::Ros2BestPractice> first_node{nullptr};

    first_node = std::make_shared<ros2_cpp_pkg::Ros2BestPractice>(t_node_name);

    // std::shared_ptr<ros2_cpp_pkg::Ros2BestPractice> second_node = std::make_shared<ros2_cpp_pkg::Ros2BestPractice>(t_node_name);

    // auto third_node = std::make_shared<ros2_cpp_pkg::Ros2BestPractice>(t_node_name);

    rclcpp::spin(first_node);
    rclcpp::shutdown();
    return 0;
}