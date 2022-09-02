#ifndef _ROS2BESTPRACTICE_H_
#define _ROS2BESTPRACTICE_H_

// C++ System Headers
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <string>
#include <chrono>
#include <functional>
#include <unordered_map>
#include <boost/thread/thread.hpp>

// ROS2 Libraries
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/msg/image.hpp"

#define __APP_NAME__ "ros2-best-practice"

namespace ros2_cpp_pkg
{
    /*!
     * Main class for the node to handle the ROS interfacing.
     */

    class Ros2BestPractice : public rclcpp::Node
    {

        // Inherit Node Constructors
        using rclcpp::Node::Node;

    public:
        /*!
         * Constructor.
         */

        Ros2BestPractice(const std::string &t_node_name);

        /*!
         *  Shallow Copy Constructor.
         */
        Ros2BestPractice(const Ros2BestPractice &source);

        /*!
         *  Overload Copy Constructor and it is assigned to the current object.
         */
        Ros2BestPractice &operator=(const Ros2BestPractice &rhs);

        /*!
         * Destructor.
         */
        ~Ros2BestPractice();

    private:
        /*!
         *  Parameter Initialization.
         */
      inline  void parameterInitilization() const;

        /*!
         *  rclcpp Parameter Reader
         */
      inline  void rclcppParameterReader();

        /*!
         *  Print Parameters.
         */
     inline   void parameterPrinter() const;

        /*!
         * Reads the only std library variables
         * Reads and verifies the ROS parameters.
         * @return true if successful.
         */
        inline bool readParameters();

        /*!
         * Reads and verifies the ROS subscribed to data.
         * @return true if successful.
         */
        inline bool areDataReceived(const bool &is_cloud_received, const bool &is_image_received);

        /*!
         * CounterObjects.
         * @return size of how many object is created  if successful.
         */
        static inline size_t objectCounter();

        /*!
         * DisplayActiveObjects.
         * @return  if successful.
         */
        inline void displayActiveObjects() const;

        /*!
         * ROS topic callback method.
         * @param t_point_cloud the received message.
         */
        inline void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr t_point_cloud);

        /*!
         * ROS topic callback method.
         * @param t_image the received message.
         */
        inline void imageCallback(const sensor_msgs::msg::Image::SharedPtr t_image);

        /*!
         * ROS topic Constructor callback method.
         * @param m_point_cloud @param m_image  the received message.
         */
        inline void contiuousCallback();

        //! rclcpp node variable
        rclcpp::Node::SharedPtr m_node;

        //! ROS pointer sensor_msgs::pointcloud2 .
        sensor_msgs::msg::PointCloud2::SharedPtr m_point_cloud;

        //! ROS pointer sensor_msgs::image.
        sensor_msgs::msg::Image::SharedPtr m_image;

        //! ROS Subscribers for the point cloud.
        std::unordered_map<std::string, rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr> m_subscriptions_point_cloud;

        //! Subscribers  varriable image.
        std::unordered_map<std::string, rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr> m_subscriptions_image;

        //! Publisher varriable point cloud.
        std::unordered_map<std::string, rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr> m_publishers_point_cloud;

        //! Publishers  varriable image.
        std::unordered_map<std::string, rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr> m_publishers_image;

        //! Ros2 Timer variable.
        rclcpp::TimerBase::SharedPtr m_timer;

        //! ROS subscriber topic name .
        std::string m_subscriber_topic_lidar;

        //! ROS publisher topic name.
        std::string m_publisher_topic_lidar;

        //! ROS subscriber topic name .
        std::string m_subscriber_topic_image;

        //! ROS publisher topic name.
        std::string m_publisher_topic_image;

        //! ROS frame id.
        std::string m_frame_id;

        //! Get the number of objects.
        static size_t m_number_objects;

        //! image width.
        int m_image_width;

        //! m_image height.
        int m_image_height;

        //! Flag for receiving point cloud.
        bool m_is_cloud_received{};

        //! Flag for receiving image.
        bool m_is_image_received{};

        //! value of rate for contiuousCallback.
        const double m_rate{};

        //! value of rate waiting for contiuousCallback.
        const double m_rate_waiting{};

        //! parameter of the subscriber topic lidar name.
        rclcpp::Parameter m_parameter_subscriber_topic_lidar;

        //! parameter of the publisher topic lidar  name.
        rclcpp::Parameter m_parameter_publisher_topic_lidar;

        //! parameter of the subscriber topic image name.
        rclcpp::Parameter m_parameter_subscriber_topic_image;

        //! parameter of the publisher topic image name.
        rclcpp::Parameter m_parameter_publisher_topic_image;

        //! parameter of the frame id.
        rclcpp::Parameter m_parameter_frame_id;

        //! parameter of the image width.
        rclcpp::Parameter m_parameter_image_width;

        //! parameter of the image height.
        rclcpp::Parameter m_parameter_image_height;
    };

} // namespace ros2_cpp_pkg

#endif // _ROS2BESTPRACTICE_H_