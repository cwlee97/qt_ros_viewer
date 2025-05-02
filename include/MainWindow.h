#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <QTimer>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsEllipseItem>

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

#include "SensorComponent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ros::NodeHandle nh_;

    QGraphicsView *graphicsView_;
    QMap<QString, QLabel*> sensorIcons_;

    QLabel *label_orientation_;
    QLabel *label_angular_;
    QLabel *label_linear_;

    QLabel *loaderLabel;
    bool isActive = true;

    void setupUI();
    ros::Subscriber imu_sub_;

    void imuCallback(const sensor_msgs::Imu::ConstPtr &msg);
};

#endif // MAINWINDOW_H
