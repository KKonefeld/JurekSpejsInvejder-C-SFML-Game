#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class BossLaser
{
public:
    BossLaser(float x, float y);
    void draw(RenderWindow& win);
    void update_position(float x, float y);
    Shape& getShape();
    float getDamage();
    float getVelocity();

private:
    CircleShape shape;
    const float laserRadius{ 10.0f };
    const float laserVelocity{ 1.f };
    float Damage{ 2.0f };
};
