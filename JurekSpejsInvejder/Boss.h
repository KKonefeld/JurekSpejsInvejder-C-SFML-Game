#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Boss
{
public:
    Boss(float x, float y);
    Shape& getShape();
    void draw(RenderWindow& win);
    void setHP(float hp);
    float getHP();
    void update_position();
    float getBossVelocityV();
    float getBossVelocityH();
    void revBossVelocityV();
    void revBossVelocityH();
    void move_horizontal(float x, float y);
    void move_vertical(float y);
private:
    RectangleShape shape;
    const float bossLength{ 150.f };
    Vector2f bossSize{ bossLength, bossLength };
    Texture texture;
    float HP{ 20.0f };
    float bossVelocityH{ 0.2f };
    float bossVelocityV{ 0.2f };
    //Vector2f velocityH{ 0 , bossVelocityH };
    //Vector2f velocityV{ bossVelocityV, 0 };
};
