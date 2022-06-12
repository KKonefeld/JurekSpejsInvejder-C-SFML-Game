#include "EnemyLaser.h"

EnemyLaser::EnemyLaser(float x, float y)
{
    shape.setPosition(x, y);
    shape.setSize(Vector2f(laserWidth, laserLength));
    shape.setFillColor(Color::Red);
    shape.setOrigin(this->laserWidth, this->laserLength);
}

void EnemyLaser::draw(RenderWindow& win)
{
    win.draw(shape);
}

void EnemyLaser::update_position()
{
    shape.move(this->velocity);
}

float EnemyLaser::getDamage()
{
    return Damage;
}

Shape& EnemyLaser::getShape()
{
    return shape;
}