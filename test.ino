#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int8.h>
#include <ebot_msg/catcher.h>>
#include <Wire.h>
#include <FaBoPWM_PCA9685.h>


FaBoPWM servo;

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
    nh.logerror("UP");
    servo.set_channel_value(0,0);
}

void servoDown() 
{
    nh.logerror("DOWN");
    servo.set_channel_value(0,0);
}

void setup()
{
    nh.initNode();
    nh.advertiseService(server);

    servo.begin();
    servo.set_hz(1526);
}

void loop()
{
    nh.spinOnce();
    delay(10);
}