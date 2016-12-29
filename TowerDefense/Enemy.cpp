#include "Enemy.h"
#include "Constants.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include <QBrush>

Enemy::Enemy(int x, int y, QGraphicsScene *scene) : QGraphicsRectItem(x, y, width, height)
{
	QBrush brush;	// set color
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(color);
	this->setBrush(brush);

	// Set up timer for moving
	QTimer *timer = new QTimer();
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(REFRESH_RATE);

	scene->addItem(this);
}

void Enemy::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		scene()->removeItem(this);
		delete this;
		qDebug() << "Enemy deleted.";
	}
}

void Enemy::move()
{
	this->setPos(x() + speed / 1000.0 * REFRESH_RATE, y());
	if (x() > scene()->width() + width)
	{
		scene()->removeItem(this);
		delete this;
		qDebug() << "Enemy deleted.";
	}
}
