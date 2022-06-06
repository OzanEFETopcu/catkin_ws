#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/Num.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::Num>("chatter", 1000);
  ros::Rate loop_rate(1);

  int count = 0;
  while (ros::ok())
  {
    beginner_tutorials::Num msg;

    msg.first_name="Ozan";
    msg.last_name="Topcu";
    msg.counter=count;
    
    std::cout << "Msg #"<<(int)msg.counter<<": FirstName: "<<msg.first_name<<" SecondName: "<< msg.last_name<<"\n";


    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}