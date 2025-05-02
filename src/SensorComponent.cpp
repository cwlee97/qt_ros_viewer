#include "SensorComponent.h"

SensorComponent::SensorComponent(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    setTransformOriginPoint(RADIUS, RADIUS);
}

QRectF SensorComponent::boundingRect() const {
    return QRectF(0, 0, RADIUS*2, RADIUS*2);
}

void SensorComponent::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setRenderHint(QPainter::Antialiasing);

    // 그라데이션 정의 (왼쪽 위 → 오른쪽 아래)
    QLinearGradient gradient(0, 0, RADIUS*2, RADIUS*2);
    gradient.setColorAt(0.0, QColor("#00b2ff"));
    gradient.setColorAt(0.5, QColor("#00ffbb"));
    gradient.setColorAt(1.0, QColor("#6bff6b"));

    painter->setBrush(gradient);
    painter->setPen(Qt::NoPen); // 외곽선 없음
    painter->drawEllipse(boundingRect());
}

qreal SensorComponent::rotationAngle() const {
    return rotation();
}

void SensorComponent::setRotationAngle(qreal angle) {
    setRotation(angle);
}