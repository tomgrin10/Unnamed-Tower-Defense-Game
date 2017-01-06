#include "Tower.h"
#include "Bullet.h"
#include "QtUtils.h"
#include <QBrush>
#include <QTimer>
#include <QPoint>

Tower::Tower(int x, int y, QGraphicsScene *scene, QObject *parent) : QGraphicsRectItem(x, y, width, height)
{
	this->setParent(parent);

	QBrush brush;	// color it
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(START_COLOR);
	this->setBrush(brush);
	this->setAcceptHoverEvents(true);

	scene->addItem(this);	// add to scene
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
		timer->start(rateOfFire);
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

Enemy* Tower::getClosestEnemy()
{
	int minDistance = 1000;
	Enemy* closest = nullptr;
	foreach(Enemy* enemy, parent()->findChildren<Enemy*>())
	{
		int currDistance = QtUtils::distance(mapToScene(rect().center()), enemy->mapToScene(enemy->rect().center()));
		if (currDistance < minDistance)
		{
			minDistance = currDistance;
			closest = enemy;
		}
	}
	return closest;
}

void Tower::fire()
{
	if (Enemy *enemy = getClosestEnemy())
		new Bullet(mapToScene(rect().center()).x(), mapToScene(rect().center()).y(), enemy, scene(), parent());
}