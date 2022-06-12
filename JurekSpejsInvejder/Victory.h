#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Victory
{
public:
    Victory(float width, float height);
    ~Victory();
    void draw(RenderWindow& window);
private:
    Font font;
    Text scoretext[3]; //ilosc itemsow w menu
    Texture tlo;
    RectangleShape background;
};
