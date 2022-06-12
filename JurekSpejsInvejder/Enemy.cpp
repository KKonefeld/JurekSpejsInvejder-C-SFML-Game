#include "Enemy.h"
using namespace sf;

Enemy::Enemy(float x, float y)
{
    shape.setPosition(x, y);
    shape.setSize(this->enemySize);
    texture.loadFromFile("enemy.png");
    shape.setTexture(&texture);
    shape.setOrigin((this->enemyLength) / 2, (this->enemyLength) / 2);
}

Shape& Enemy::getShape()
{
    return shape;
}

void Enemy::draw(RenderWindow& win)
{
    win.draw(shape);
}

void Enemy::setHP(float hp)
{
    HP = hp;
}

float Enemy::getHP()
{
    return HP;
}

void Enemy::update_position()
{
    shape.setPosition(shape.getPosition().x, shape.getPosition().y + 80);
}

void Enemy::setEnemyVelocity()
{
    enemyVelocity = -enemyVelocity;
}

float Enemy::getEnemyVelocity()
{
    return enemyVelocity;
}

void Enemy::move_horizontal(float x)
{
    shape.move(x, 0);
}