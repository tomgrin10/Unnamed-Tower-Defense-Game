#include "Game.h"
#include "Enemy.h"
#include "Tower.h"
#include <random>
#include <QTimer>

Game::Game(QGraphicsScene *scene) : QGraphicsView(scene)
{
	// Set window
	scene->setSceneRect(0, 0, Tower::width * NUM_OF_TOWERS, Tower::height*2 + SPACE_FOR_ENEMIES);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setFixedSize(scene->width(), scene->height());

	// Set towers
	for (int i = 0, currY = 0; i < 2; i++)
	{
		for (int j = 0; j < NUM_OF_TOWERS; j++)
		{
			Tower *tower = new Tower(Tower::width * j, currY, scene);
		}
		currY += Tower::height + SPACE_FOR_ENEMIES;
	}

	// Set enemy spawning
	QTimer *timer = new QTimer();
	QObject::connect(timer, &QTimer::timeout, this, [this]{ spawnEnemy(Tower::height, Tower::height + SPACE_FOR_ENEMIES); });
	timer->start(1000);

	this->show();
}

void Game::spawnEnemy(int top, int bottom)
{
	// Generate random number for the y axis
	std::random_device rnd;
	std::mt19937 generator(rnd());
	std::uniform_int_distribution<int> rand(top, bottom - Enemy::height);

	Enemy *enemy = new Enemy(0 - Enemy::width, rand(generator), scene());
}