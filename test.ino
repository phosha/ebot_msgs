#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int8.h>
#include <ebot_msg/catcher.h>>

ros::NodeHandle nh;

using ebot_msg::catcher;

void callback(const catcher::Request &req, catcher::Response &res)
{
    switch (req.Catching.data == 0)
    {
    case 1:
        servoUp();
        res.Num = 123;
        break;
    case 0:
        servoDown();
        res.Num = 0;
        break;
    }
}

ros::ServiceServer<catcher::Request, catcher::Response> server("catch_serv", &callback);

void servoUp()
{
}

void servoDown() 
{
}

void setup()
{
    nh.initNode();
    nh.advertiseService(server);
}

void loop()
{
    nh.spinOnce();
    delay(10);
}