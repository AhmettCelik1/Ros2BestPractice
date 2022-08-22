from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_best_practice',
            executable='ros2_best_practice',
            name='ros2_best_practice_1',
            parameters=[
                {'subscriber_topic_lidar': '/lidar_front/points_raw'},
                {'subscriber_topic_image': '/camera_raw'},
                {'publisher_topic_lidar': '/lidar_front/points_raw_filtered'},
                {'publisher_topic_image': '/camera_raw_filtered'},
                {'frame_id': 'velodyne'},
                {'image_width': 1152},
                {'image_height': 720},
            ],
            output='screen',
            emulate_tty=True,

        )
    ])
