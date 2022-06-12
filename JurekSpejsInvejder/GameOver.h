#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class GameOver
{
public:
    GameOver(float width, float height);
    void sendScore(int x);
    ~GameOver();
    void draw(RenderWindow& window);
private:
    Font font;
    Text scoretext[3]; //ilosc itemsow w menu
    Texture tlo;
    RectangleShape background;
    int showScore = 21;
};
