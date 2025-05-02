#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    imu_sub_ = nh_.subscribe("/imu/data", 10, &MainWindow::imuCallback, this);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    QWidget *central = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    central->setStyleSheet("background-color: #323840;");

    // 센서 상태 표시
    QHBoxLayout *statusLayout = new QHBoxLayout;
    QStringList sensors = {"Camera", "Lidar", "GPS", "IMU"};

    for (const QString &sensor : sensors) {
        QLabel *label = new QLabel(sensor);
        QLabel *statusIcon = new QLabel;
        statusIcon->setFixedSize(16, 16);
        statusIcon->setStyleSheet("background-color: red; border-radius: 8px;");
        sensorIcons_[sensor] = statusIcon;

        label->setStyleSheet("color: #e6e6e6;");  // 텍스트 색상 변경

        QHBoxLayout *sensorLayout = new QHBoxLayout;
        sensorLayout->addWidget(label);
        sensorLayout->addWidget(statusIcon);
        sensorLayout->setAlignment(Qt::AlignCenter);

        statusLayout->addLayout(sensorLayout);
    }

    QGraphicsView *view = new QGraphicsView;
    QGraphicsScene *scene = new QGraphicsScene(this);
    view->setScene(scene);
    mainLayout->addWidget(view);

    SensorComponent *sensorComponent = new SensorComponent();

    scene->addItem(sensorComponent);

    QPropertyAnimation *rotateAnim = new QPropertyAnimation(sensorComponent, "rotationAngle");
    rotateAnim->setDuration(3000);
    rotateAnim->setStartValue(0);
    rotateAnim->setEndValue(360);
    rotateAnim->setLoopCount(-1);
    rotateAnim->start();

    mainLayout->addLayout(statusLayout);
    central->setLayout(mainLayout);
    setCentralWidget(central);
    setWindowTitle("ROS Sensor Viewer");
}

void MainWindow::imuCallback(const sensor_msgs::Imu::ConstPtr &msg)
{
    // QString orientation = QString("Orientation:\n x: %1\n y: %2\n z: %3\n w: %4")
    //                       .arg(msg->orientation.x)
    //                       .arg(msg->orientation.y)
    //                       .arg(msg->orientation.z)
    //                       .arg(msg->orientation.w);

    // QString angular = QString("Angular Velocity:\n x: %1\n y: %2\n z: %3")
    //                   .arg(msg->angular_velocity.x)
    //                   .arg(msg->angular_velocity.y)
    //                   .arg(msg->angular_velocity.z);

    // QString linear = QString("Linear Acceleration:\n x: %1\n y: %2\n z: %3")
    //                  .arg(msg->linear_acceleration.x)
    //                  .arg(msg->linear_acceleration.y)
    //                  .arg(msg->linear_acceleration.z);

    // ui->label_orientation->setText(orientation);
    // ui->label_angular->setText(angular);
    // ui->label_linear->setText(linear);
}
