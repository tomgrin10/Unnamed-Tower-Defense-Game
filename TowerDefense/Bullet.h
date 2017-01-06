#pragma once
#include "Enemy.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
private:
	void turnToFutureLocation(Enemy *enemy);

private slots:
	void moveForward();

public:
	static const int width = 20;
	static const int height = 5;
	static const Qt::GlobalColor color = Qt::green;
	static const int speed = 200;

	Bullet(int x, int y, Enemy *enemy, QGraphicsScene *scene, QObject *parent);
};