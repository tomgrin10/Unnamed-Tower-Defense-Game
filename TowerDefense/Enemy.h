#pragma once
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Enemy: public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
	static const int height = 30;
	static const int width = 30;
	static const Qt::GlobalColor color = Qt::red;
	static const int speed = 100;

	Enemy(int x, int y, QGraphicsScene *scene, QObject* parent);
	void mousePressEvent(QGraphicsSceneMouseEvent *event);

private slots:
	void move();
};