#include <QApplication>
#include <QGraphicsScene>
#include "Game.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QGraphicsScene *scene = new QGraphicsScene(&app);
	Game *game = new Game(scene);

	return app.exec();
}
