#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>

class Game: public QGraphicsView
{
	Q_OBJECT
private:
	static const int NUM_OF_TOWERS = 10;
	static const int SPACE_FOR_ENEMIES = 100;

public:
	Game(QGraphicsScene *scene);

private slots:
	void spawnEnemy(int top, int bottom);
};