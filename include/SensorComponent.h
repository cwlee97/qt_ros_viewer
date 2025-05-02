#ifndef SENSOR_COMPONENT_H
#define SENSOR_COMPONENT_H

#include <QGraphicsObject>
#include <QPainter>

#define RADIUS 50

class SensorComponent : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(qreal rotationAngle READ rotationAngle WRITE setRotationAngle)

public:
    explicit SensorComponent(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

    qreal rotationAngle() const;
    void setRotationAngle(qreal angle);
};

#endif // SENSOR_COMPONENT_H
