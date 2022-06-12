#include "Boss.h"

using namespace sf;

Boss::Boss(float x, float y)
{
    shape.setPosition(x, y);
    shape.setSize(this->bossSize);
    texture.loadFromFile("boss.png");
    shape.setTexture(&texture);
    shape.setOrigin((this->bossLength) / 2, (this->bossLength) / 2);
}

Shape& Boss::getShape()
{
    return shape;
}

void Boss::draw(RenderWindow& win)
{
    win.draw(shape);
}

void Boss::setHP(float hp)
{
    HP = hp;
}

float Boss::getHP()
{
    return HP;
}

void Boss::update_position()
{
    shape.setPosition(shape.getPosition().x, shape.getPosition().y + 80);
}

//void Boss::setEnemyVelocity()
//{
//    bossVelocity = -bossVelocity;
//}

float Boss::getBossVelocityH()
{
    return bossVelocityH;
}

void Boss::revBossVelocityH()
{
    bossVelocityH = -bossVelocityH;
}

float Boss::getBossVelocityV()
{
    return bossVelocityV;
}

void Boss::revBossVelocityV()
{
    bossVelocityV = -bossVelocityV;
}

void Boss::move_horizontal(float x, float y)
{
    shape.move(x, y);
}

void Boss::move_vertical(float y)
{
    shape.move(0, y);
}