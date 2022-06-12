#include "Laser.h"

Laser::Laser(float x, float y)
{
	shape.setPosition(x, y);
	shape.setSize(Vector2f(laserWidth, laserLength));
	shape.setFillColor(Color::Green);
	shape.setOrigin(this->laserWidth, this->laserLength);
}

void Laser::draw(RenderWindow& win)
{
	win.draw(shape);
}

void Laser::update_position()
{
	shape.move(this->velocity);
}

float Laser::getDamage()
{
	return Damage;
}

Shape& Laser::getShape()
{
	return shape;
}
