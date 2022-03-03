#!/usr/bin/env python3
import rospy
from ebot_msg.srv import catcher
from std_msgs.msg import Bool as bobo

b = bobo()
b.data = True
def client(a):
    rospy.wait_for_service("catcher_server")
    try:
        catch = rospy.ServiceProxy("catcher_server", catcher)
        resp = catch(b)
        return resp.Num
    except rospy.ServiceException as e:
        rospy.logerr(f"ERROR {e}")

if __name__ == "__main__":
    rospy.logerr(b.data)
    rospy.logerr(client(b.data))
