#include "Victory.h"
#include <iostream>
using namespace sf;
using namespace std;


Victory::Victory(float width, float height)
{
    if (!tlo.loadFromFile("victory.png"))
    {
        cout << "Nie laduje sie tlo" << endl;
    }
    background.setSize(Vector2f(width, height));
    background.setTexture(&tlo);
}

Victory::~Victory()
{
}

void Victory::draw(RenderWindow& window)
{
    window.draw(background);
}