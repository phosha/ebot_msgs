#!/usr/bin/env python3
import rospy
from ebot_msg.srv import catcher
from std_msgs.msg import Bool as bobo

b = bobo()
b.data = 1
def client(a):
    rospy.wait_for_service("catch_serv")
    try:
        catch = rospy.ServiceProxy("catch_serv", catcher)
        resp = catch(a)
        return resp.Num
    except rospy.ServiceException as e:
        rospy.logerr(f"ERROR {e}")

if __name__ == "__main__":
    rospy.logerr(b.data)
    i = client(b)
    if (i > 0):
        rospy.logwarn(f"TRUE {i=}")
    else:
        rospy.logerr(f"FALSE {i=}")
    #rospy.logerr(client(b.data))
