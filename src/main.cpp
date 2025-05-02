#include "MainWindow.h"
#include <QApplication>
#include <ros/ros.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "qt_ros_viewer_node");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [](){ ros::spinOnce(); });
    timer.start(10);  // 10ms마다 ROS 메시지 처리

    return a.exec();
}
