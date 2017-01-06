#include "Bullet.h"
#include "QtUtils.h"
#include "Constants.h"
#include <QTimer>
#include <QList>
#include <qmath.h>
#include <QDebug>

Bullet::Bullet(int x, int y, Enemy *enemy, QGraphicsScene *scene, QObject *parent) : QGraphicsRectItem(x, y, width, height)
{
	// Add to screen and change settings
	this->setTransformOriginPoint(x, y);
	this->setParent(parent);
	this->hide();
	scene->addItem(this);

	// Turn the enemy
	turnToFutureLocation(enemy);

	// Color the bullet
	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(color);
	this->setBrush(brush);

	// Set timer to move
	QTimer *timer = new QTimer;
	connect(timer, SIGNAL(timeout()), this, SLOT(moveForward()));
	timer->start(REFRESH_RATE);

	this->show();
}

void Bullet::turnToFutureLocation(Enemy *enemy)
{
	qreal x = (mapToScene(rect().center()).x() - enemy->mapToScene(enemy->rect().center()).x());
	qreal y = (enemy->mapToScene(enemy->rect().center()).y() - mapToScene(rect().center()).y());
	qreal R = qSqrt(x*x + y*y);

	qreal temp = qAsin((enemy->speed * y) / (speed * R));
	temp = temp - qDegreesToRadians(90.0) - qAtan(x / y);
	temp *= qAbs(y) / -y;

	setRotation(qRadiansToDegrees(temp));
}

void Bullet::moveForward()
{
	QList<QGraphicsItem*> colliding = collidingItems();
	foreach (QGraphicsItem *item, colliding)
	{
		if (typeid(*item) == typeid(Enemy))
		{
			scene()->removeItem(item);
			scene()->removeItem(this);
			delete item;
			delete this;
			return;
		}
	}

	double theta = rotation();
	double dx = speed / 1000.0 * REFRESH_RATE * qCos(qDegreesToRadians(theta));
	double dy = speed / 1000.0 * REFRESH_RATE * qSin(qDegreesToRadians(theta));

	setPos(x() + dx, y() + dy);
}