#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Bullet : public QGraphicsRectItem
{
public:
	static const int width = 5;
	static const int height = 20;
	static const Qt::GlobalColor color = Qt::green;
	static const int speed = 200;

	Bullet(int x, int y, QGraphicsScene *scene);
};