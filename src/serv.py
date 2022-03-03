#!/usr/bin/env python3
from xml.dom.expatbuilder import theDOMImplementation
import rospy
from ebot_msg.srv import catcher, catcherResponse


def sender(req):
    i = req.Catching.data
    rospy.loginfo(f"{req.Catching.data=}")
    if i == True:
        return catcherResponse(Num = 123)
    if i == False:
        return catcherResponse(Num = 0)

def server():
    rospy.init_node('catch_serv')
    rospy.Service('catcher_server', catcher, sender)
    rospy.spin()

if __name__ == "__main__":
    server()