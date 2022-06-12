#include "Bomb.h"

Bomb::Bomb(float x, float y)
{
	shape.setPosition(x, y);
	shape.setRadius(this -> bombRadius);
	//shape.setFillColor(Color::Red);
	shape.setOrigin(this->bombRadius, this->bombRadius);;
	texture.loadFromFile("bombtest.png");
	shape.setTexture(&texture);
}

void Bomb::draw(RenderWindow& win)
{
	win.draw(shape);
}

void Bomb::update_position()
{
	shape.move(this->velocity);
	shape.rotate(5);
}

float Bomb::getDamage()
{
	return Damage;
}

Shape& Bomb::getShape()
{
	return shape;
}
