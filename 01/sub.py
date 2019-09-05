#!/usr/bin/python

import numpy as np
import roslib
import rospy
from std_msgs.msg import Float32MultiArray

def cb_sub(msg):
  print len(msg.data)
  print type(msg.data)
  print msg.data[:10]
  return

if __name__ == "__main__":
  rospy.init_node('numsub',anonymous=True)
  rospy.Subscriber("array",Float32MultiArray,cb_sub)
  try:
    rospy.spin()
  except KeyboardInterrupt:
    print "Shutting down"
