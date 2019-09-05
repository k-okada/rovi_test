cmake_minimum_required(VERSION 2.8.3)
project(rovi_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs
)

#catkin_python_setup()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pubarray 01/pubarray.cpp)
target_link_libraries(pubarray ${catkin_LIBRARIES})

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest(01/test.launch)
endif()
