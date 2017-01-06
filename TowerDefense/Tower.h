#pragma once
#include "Enemy.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>

class Tower: public QObject, public QGraphicsRectItem
{
	Q_OBJECT
	enum TowerState;

private:
	static const Qt::GlobalColor START_COLOR = Qt::black;
	static const Qt::GlobalColor SECOND_COLOR = Qt::blue;
	TowerState _state = Wall;

public:
	enum TowerState { Wall, Shoot };
	static const int height = 60;
	static const int width = 60;
	static const int rateOfFire = 3000;

	Tower(int x, int y, QGraphicsScene *scene, QObject *parent);

	Enemy* getClosestEnemy();

	TowerState state();

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private slots:
	void fire();
};