#include <cstdio>

#include "rclcpp/rclcpp.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include <chrono>

using namespace std::chrono_literals;


class Learn1Publisher
: public rclcpp::Node
{
  public:
  Learn1Publisher() : Node("learn1") 
  {    
    broadcast_ =  std::make_shared<tf2_ros::TransformBroadcaster>(this);
    // this->create_wall_timer(100ms, std::bind(&Learn1Publisher::transform, this));
    this->transform();
    
  }
  private:
  void transform() {
    geometry_msgs::msg::TransformStamped t;

    t.header.stamp = this->get_clock()->now();
    t.header.frame_id = "map";
    t.child_frame_id = "world";
    t.transform.translation.x = 0.0;
    t.transform.translation.y = 2.0;
    t.transform.translation.z = 0.0;
    t.transform.rotation.x = 0.0;
    t.transform.rotation.y = 0.0;
    t.transform.rotation.z = 0.0;
    t.transform.rotation.w = 1.0;
    broadcast_->sendTransform(t);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  std::shared_ptr<tf2_ros::TransformBroadcaster> broadcast_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Learn1Publisher>());  
  rclcpp::shutdown();
  
  return 0;
}
