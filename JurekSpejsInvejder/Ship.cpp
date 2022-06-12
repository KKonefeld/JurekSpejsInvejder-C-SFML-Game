#include "Ship.h"

Ship::Ship(int id)
{
	shape.setSize(Vector2f(100, 100));



	texture.loadFromFile("test.png");
	shape.setTexture(&texture);
	//shape.setOrigin(Vector2f(50, 50));
}

Shape& Ship::getShape()
{
	return shape;
}

void Ship::set_location(float x , float y)
{
	shape.setPosition(x, y);
}

void Ship::draw(RenderWindow &win)
{
	win.draw(shape);
}

void Ship::changetexture(int idnumber)
{
	shape.setSize(Vector2f(100, 100));
	if (idnumber == 1)
	{
		texture.loadFromFile("statekv2.png");
	}
	else if (idnumber == 2)
	{
		texture.loadFromFile("statekv3.png");
	}
	else
	{
		texture.loadFromFile("test.png");
	}
	shape.setTexture(&texture);
}

void Ship::setHP(int hp)
{
	HP = hp;
}

int Ship::getHP()
{
	return HP;
}

void Ship::setScore(int sc)
{
	Score = 0;
}

void Ship::givePoints()
{
	Score += 100;
}

int Ship::getScore()
{
	return Score;
}
