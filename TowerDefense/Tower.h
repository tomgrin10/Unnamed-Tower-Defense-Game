#pragma once
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

	Tower(int x, int y, QGraphicsScene *scene);

	TowerState state();

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private slots:
	void fire();
};