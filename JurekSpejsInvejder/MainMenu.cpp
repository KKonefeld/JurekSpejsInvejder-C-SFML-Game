#include "MainMenu.h"
#include <iostream>
using namespace sf;
using namespace std;
MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("prawiearial.ttf"))
	{
		cout << "Nie laduje sie czcionka" << endl;
	}
	if (!tittlef.loadFromFile("juras.ttf"))
	{
		cout << "Nie laduje sie czcionka tytulowa" << endl;
	}

	if (!tlo.loadFromFile("background.png"))
	{
		cout << "Nie laduje sie tlo" << endl;
	}
	


	background.setSize(Vector2f(width,height));
	background.setTexture(&tlo);

	tittle[0].setFillColor(Color::Yellow);
	tittle[0].setFont(tittlef);
	tittle[0].setString("JurasInvejder");
	tittle[0].setPosition(40, 50);  //X , Y 
	tittle[0].setCharacterSize(95);

	menuItem[0].setFillColor(Color::Yellow);
	menuItem[0].setFont(font);
	menuItem[0].setString("Graj");
	menuItem[0].setPosition(50,300);  //X , Y 
	menuItem[0].setCharacterSize(80);

	menuItem[1].setFont(font);
	menuItem[1].setString("Opcje");
	menuItem[1].setPosition(50, 400);  //X , Y 
	menuItem[1].setCharacterSize(50);

	menuItem[2].setFont(font);
	menuItem[2].setString("Statek");
	menuItem[2].setPosition(50, 450);  //X , Y 
	menuItem[2].setCharacterSize(35);

	menuItem[3].setFont(font);
	menuItem[3].setString("Jak grac");
	menuItem[3].setPosition(50, 500);  //X , Y 
	menuItem[3].setCharacterSize(35);

	menuItem[4].setFont(font);
	menuItem[4].setString("Wyjscie");
	menuItem[4].setPosition(50, 550);  //X , Y 
	menuItem[4].setCharacterSize(35);

	selectedItemID = 0;

}

MainMenu::~MainMenu()
{
}

void MainMenu::draw(RenderWindow &window)
{
	window.draw(background);
	window.draw(tittle[0]);
	for (int i = 0; i < 5; i++)
	{
		window.draw(menuItem[i]);

	}

}

void MainMenu::MoveUpper()
{
	if ( selectedItemID - 1 >= 0)
	{
		//cout << "Poczatkowy " << selectedItemID << " Zmieniam na " << selectedItemID - 1 << endl;
		menuItem[selectedItemID].setFillColor(Color::White);
		selectedItemID--;
		menuItem[selectedItemID].setFillColor(Color::Yellow);
	}
	else
	{
		selectedItemID = 4;
		menuItem[0].setFillColor(Color::White);
		menuItem[selectedItemID].setFillColor(Color::Yellow);

	}

}

void MainMenu::MoveDown()
{
	if (selectedItemID + 1 < 5)
	{
		//cout << "Poczatkowy " << selectedItemID << " Zmieniam na " << selectedItemID + 1 << endl;
		menuItem[selectedItemID].setFillColor(Color::White);
		selectedItemID++;
		menuItem[selectedItemID].setFillColor(Color::Yellow);
	}
	else
	{
		selectedItemID = 0;
		menuItem[4].setFillColor(Color::White);
		menuItem[selectedItemID].setFillColor(Color::Yellow);
	}


}
