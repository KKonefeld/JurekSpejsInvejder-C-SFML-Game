#include "SelectShip.h"
#include <iostream>
using namespace sf;
using namespace std;

SelectShip::SelectShip(float width, float height)
{
	if (!font.loadFromFile("prawiearial.ttf"))
	{
		cout << "Nie laduje sie czcionka" << endl;
	}
	if (!tlo.loadFromFile("selectionbackground.png"))
	{
		cout << "Nie laduje sie tlo" << endl;
	}
	background.setSize(Vector2f(width, height));
	background.setTexture(&tlo);


	Item[0].setFont(font);
	Item[0].setString("Statek 1");
	Item[0].setPosition(50, 70);  //X , Y 
	Item[0].setCharacterSize(50);

	Item[1].setFont(font);
	Item[1].setString("Statek 2");
	Item[1].setPosition(50, 220);  //X , Y 
	Item[1].setCharacterSize(50);

	Item[2].setFont(font);
	Item[2].setString("Statek 3");
	Item[2].setPosition(50, 370);  //X , Y 
	Item[2].setCharacterSize(50);
	selectedItemID = 0;
	Item[0].setFillColor(Color::Yellow);
}

SelectShip::~SelectShip()
{
}

void SelectShip::draw(RenderWindow& window)
{
	window.draw(background);
	for (int i = 0; i < 3; i++)
	{
		window.draw(Item[i]);

	}
}

void SelectShip::MoveUpper()
{
	if (selectedItemID - 1 >= 0)
	{
		cout << "Poczatkowy " << selectedItemID << " Zmieniam na " << selectedItemID - 1 << endl;
		Item[selectedItemID].setFillColor(Color::White);
		selectedItemID--;
		Item[selectedItemID].setFillColor(Color::Yellow);
	}
	else
	{
		selectedItemID = 2;
		Item[0].setFillColor(Color::White);
		Item[selectedItemID].setFillColor(Color::Yellow);

	}
}

void SelectShip::MoveDown()
{
	if (selectedItemID + 1 < 3)
	{
		cout << "Poczatkowy " << selectedItemID << " Zmieniam na " << selectedItemID + 1 << endl;
		Item[selectedItemID].setFillColor(Color::White);
		selectedItemID++;
		Item[selectedItemID].setFillColor(Color::Yellow);
	}
	else
	{
		selectedItemID = 0;
		Item[2].setFillColor(Color::White);
		Item[selectedItemID].setFillColor(Color::Yellow);
	}
}
