#include "ros/ros.h"
#include "exo_bsc_msgs/ExoJointState.h"


/*Callback function*/
void msgCallback(const exo_bsc_msgs::ExoJointState::ConstPtr& msg)
{
  ROS_INFO("State pos: %f ", msg->pos.right_knee);
  ROS_INFO("State vel: %f ", msg->vel.right_knee);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("state", 10, msgCallback);

  ros::spin();
  return 0;
}
