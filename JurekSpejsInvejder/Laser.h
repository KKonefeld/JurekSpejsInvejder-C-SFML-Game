#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Laser
{
public:
	Laser(float x, float y);
	void draw(RenderWindow &win);
	void update_position();
	Shape& getShape();
	float getDamage();

private:
	RectangleShape shape;
	const float laserWidth{ 5.0f };
	const float laserLength{ 30.0f };
	const float laserVelocity{ 10.0f };
	Vector2f velocity{ 0, -laserVelocity };
	float Damage{ 1.0f };
};

