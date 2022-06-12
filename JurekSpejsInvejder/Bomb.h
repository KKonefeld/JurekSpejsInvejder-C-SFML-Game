#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bomb
{
public:
	Bomb(float x, float y);
	void draw(RenderWindow& win);
	void update_position();
	float getDamage();
	Shape& getShape();

private:
	CircleShape shape;
	Texture texture;
	const float bombRadius{ 15.f };
	const float bombVelocity{ 1.f };
	Vector2f velocity{ 0, -bombVelocity };
	float Damage{ 5.0f };
};

