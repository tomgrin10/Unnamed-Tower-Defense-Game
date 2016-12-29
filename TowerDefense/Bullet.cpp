#include "Bullet.h"

Bullet::Bullet(int x, int y, QGraphicsScene *scene) : QGraphicsRectItem(x, y, width, height)
{
	QBrush brush;	// color it
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(color);
	this->setBrush(brush);

	scene->addItem(this);
}
