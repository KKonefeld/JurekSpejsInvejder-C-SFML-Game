#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Enemy
{
public:
    Enemy(float x, float y);
    Shape& getShape();
    void draw(RenderWindow& win);
    void setHP(float hp);
    float getHP();
    void update_position();
    float getEnemyVelocity();
    void setEnemyVelocity();
    void move_horizontal(float x);

private:
    RectangleShape shape;
    const float enemyLength{ 80.f };
    Vector2f enemySize{ enemyLength, enemyLength };
    Texture texture;
    float HP{ 10.0f };
    float enemyVelocity{ 0.2f };
    Vector2f velocity{ enemyVelocity , 0 };
};
