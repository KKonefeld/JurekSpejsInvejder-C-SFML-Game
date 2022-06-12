#include "GameOver.h"
#include "Ship.h"
#include <iostream>
using namespace sf;
using namespace std;


GameOver::GameOver(float width, float height)
{
    if (!font.loadFromFile("prawiearial.ttf"))
    {
        cout << "Nie laduje sie czcionka" << endl;
    }


    if (!tlo.loadFromFile("gameoverbackground.png"))
    {
        cout << "Nie laduje sie tlo" << endl;
    }
    background.setSize(Vector2f(width, height));
    background.setTexture(&tlo);
}

void GameOver::sendScore(int x)
{
    showScore = x;
    string scr;
    scr = to_string(showScore);

    

    scoretext[0].setFillColor(Color::Magenta);
    scoretext[0].setFont(font);
    scoretext[0].setString(scr);

    FloatRect textRect = scoretext[0].getLocalBounds();
    scoretext[0].setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    scoretext[0].setPosition(sf::Vector2f(390, 222));
    
    /*scoretext[0].setOrigin(a/2, 0);
    scoretext[0].setPosition(390, 150);*/  //X , Y 
    scoretext[0].setCharacterSize(70);
}

GameOver::~GameOver()
{
}

void GameOver::draw(RenderWindow& window)
{
    window.draw(background);
    window.draw(scoretext[0]);
}