cmake_minimum_required(VERSION 3.5)
project(ros2_cpp_pkg)

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

# find dependencies
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3)
find_package(rclpy REQUIRED)


set(dependencies "sensor_msgs" "rclcpp" "geometry_msgs" "std_msgs")

## let cmake know that we want to use the rclcpp cpp_common package
include_directories(include())
#----------------------------------------------------------------------------##
### Ros2BestPractice
## Declare a cpp library
add_library(ros2_best_practice_core
        src/Ros2BestPractice/Ros2BestPractice.cpp
        )
target_compile_features(ros2_best_practice_core INTERFACE cxx_std_11)

## Declare cpp executables
add_executable(ros2_best_practice
        src/Ros2BestPractice/ros2_best_practice_node.cpp
        src/Ros2BestPractice/Ros2BestPractice.cpp
        )
target_compile_features(ros2_best_practice INTERFACE cxx_std_11)

## Add dependencies to exported targets, like ROS msgs or srvs
ament_target_dependencies(ros2_best_practice_core  ${dependencies})

ament_target_dependencies(ros2_best_practice ${dependencies})

## Specify libraries to link executable targets against
target_link_libraries(ros2_best_practice_core
        ${catkin_LIBRARIES}
        )

target_link_libraries(ros2_best_practice
        ros2_best_practice_core
        ${catkin_LIBRARIES}
        )
#----------------------------------------------------------------------------##


install (DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
 
install(TARGETS
  ros2_best_practice
  DESTINATION lib/${PROJECT_NAME})


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
