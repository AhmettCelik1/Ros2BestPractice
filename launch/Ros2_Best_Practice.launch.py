from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_best_practice',
            executable='ros2_best_practice',
            name='ros2_best_practice_1',
            parameters=[
                {'subscriber_topic_lidar': '/velodyne_points'},
                {'subscriber_topic_image': '/spinnaker_ros_driver_node/cam_fm_01/image_raw'},
                {'publisher_topic_lidar': '/velodyne_points_filtered'},
                {'publisher_topic_image': '/spinnaker_ros_driver_node/cam_fm_01/image_raw_filtered'},
                {'frame_id': 'velodyne'},
                {'image_width': 1152},
                {'image_height': 720},
            ],
            output='screen',
            emulate_tty=True,

        )
    ])
