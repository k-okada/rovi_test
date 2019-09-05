#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <stdlib.h>
#include <math.h>

ros::NodeHandle *nh;
ros::Publisher *pub;

int maxpnt=500000;
int minpnt=500000;

void callback(const ros::TimerEvent&){
  std_msgs::Float32MultiArray array;
  array.layout.dim.resize(1);
  array.layout.data_offset=0;
  int N=maxpnt;
  if(maxpnt!=minpnt)
    N=minpnt+(long long)(maxpnt-minpnt)*rand()/RAND_MAX;
  array.data.resize(N);
  array.layout.dim[0].size=N;
  array.layout.dim[0].stride=1;
  std::cout<<"points "<<N<<"\n";
  for (int i=0; i<N; i++){
    array.data[i]=0.001*i;
  }
  pub->publish(array);
}
int main(int argc, char **argv){
  if(argc>=2) maxpnt=minpnt=atoi(argv[1]);
  if(argc>=3) minpnt=atoi(argv[2]);
  if(maxpnt<minpnt){ int a=maxpnt;maxpnt=minpnt;minpnt=a;}
  std::cout<<" min "<<minpnt<<" max "<<maxpnt<<"\n";

  ros::init(argc, argv, "pubpc");
  ros::NodeHandle n;
  nh = &n;
  ros::Timer timer = n.createTimer(ros::Duration(1.0), callback);
  ros::Publisher p0=n.advertise<std_msgs::Float32MultiArray>("array",1);
  pub = &p0;
  ros::spin();
  return 0;
}
