cmake_minimum_required(VERSION 3.5)
project(object_avoidance)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

######################################################################
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)


add_executable(obstacle_avoidancee src/obstacle_avoidance.cpp)
ament_target_dependencies(obstacle_avoidancee  rclcpp geometry_msgs sensor_msgs)



install(TARGETS
    obstacle_avoidancee 
    DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY launch 
DESTINATION share/${PROJECT_NAME}
)

#######################################################################
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
