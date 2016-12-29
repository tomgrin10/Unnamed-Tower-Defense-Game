#include "Tower.h"
#include "Bullet.h"
#include <QBrush>
#include <QTimer>
#include <QDebug>
#include <QPoint>

Tower::Tower(int x, int y, QGraphicsScene *scene) : QGraphicsRectItem(x, y, width, height)
{
	QBrush brush;	// color it
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(START_COLOR);
	this->setBrush(brush);
	this->setAcceptHoverEvents(true);

	scene->addItem(this);	// add to scene
	qDebug() << scenePos().x();
}

Tower::TowerState Tower::state()
{
	return _state;
}

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && _state == Wall)
	{
		// Switch state to shoot
		QBrush brush;
		brush.setStyle(Qt::SolidPattern);
		brush.setColor(SECOND_COLOR);
		this->setBrush(brush);
		this->_state = Shoot;

		// Set up shoot mechanism
		QTimer *timer = new QTimer;
		connect(timer, SIGNAL(timeout()), this, SLOT(fire()));
		timer->start(2000);
	}
}

void Tower::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	if (_state == Wall)
	{
		// Set color to be brighter
		QBrush brush = this->brush();
		brush.setStyle(Qt::SolidPattern);
		brush.setColor(Qt::darkGray);
		this->setBrush(brush);
	}
}

void Tower::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	if (_state == Wall)
	{
		// Set color back
		QBrush brush = this->brush();
		brush.setStyle(Qt::SolidPattern);
		brush.setColor(START_COLOR);
		this->setBrush(brush);
	}
}

void Tower::fire()
{
	qDebug() << mapToScene(0, 0).x();
	Bullet *bullet = new Bullet(scenePos().x() + width / 2, scenePos().y() + height / 2, scene());
}