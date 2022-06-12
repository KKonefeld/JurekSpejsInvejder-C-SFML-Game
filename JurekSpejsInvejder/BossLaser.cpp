#include "BossLaser.h"

BossLaser::BossLaser(float x, float y)
{
    shape.setPosition(x, y);
    shape.setRadius(laserRadius);
    shape.setFillColor(Color::Magenta);
    shape.setOrigin(this->laserRadius, this->laserRadius);
}

void BossLaser::draw(RenderWindow& win)
{
    win.draw(shape);
}

void BossLaser::update_position(float x, float y)
{
    shape.move(x, y);
}

float BossLaser::getDamage()
{
    return Damage;
}

float BossLaser::getVelocity()
{
    return laserVelocity;
}

Shape& BossLaser::getShape()
{
    return shape;
}
