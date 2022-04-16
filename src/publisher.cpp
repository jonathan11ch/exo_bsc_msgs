#include "ros/ros.h"
#include "exo_bsc_msgs/ExoJointPos.h"
#include "exo_bsc_msgs/ExoJointVel.h"
#include "exo_bsc_msgs/ExoJointState.h"
#include <sstream>

int main(int argc, char **argv)
{
  //initialize node
  ros::init(argc, argv, "test_publisher");
  ros::NodeHandle n;
  ros::Publisher pub_pos = n.advertise<exo_bsc_msgs::ExoJointPos>("position", 10);
  ros::Publisher pub_vel = n.advertise<exo_bsc_msgs::ExoJointVel>("velocity", 10);
  ros::Publisher pub_state = n.advertise<exo_bsc_msgs::ExoJointState>("state", 10);

  //instantiate the message
  exo_bsc_msgs::ExoJointPos pos_msg;
  exo_bsc_msgs::ExoJointVel vel_msg;
  exo_bsc_msgs::ExoJointState state_msg;

  ros::Rate loop_rate(1);
  int count = 0;
  while(ros::ok())
  {

    //populate message
    pos_msg.header.stamp = ros::Time::now();
    pos_msg.right_knee = count*1;
    pos_msg.right_hip = count*2;
    pos_msg.left_knee = count*3;
    pos_msg.left_hip = count*4;

    vel_msg.header.stamp = ros::Time::now();
    vel_msg.right_knee = count*2;
    vel_msg.right_hip = count*4;
    vel_msg.left_knee = count*6;
    vel_msg.left_hip = count*8;
    count ++;

    state_msg.header.stamp = ros::Time::now();
    state_msg.pos = pos_msg;
    state_msg.vel = vel_msg;

    //publish
    pub_pos.publish(pos_msg);
    pub_vel.publish(vel_msg);
    pub_state.publish(state_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

}
