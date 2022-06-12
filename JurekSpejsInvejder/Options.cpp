#include "Options.h"
#include <iostream>
using namespace sf;
using namespace std;
Options::Options(float width, float height)
{
	if (!font.loadFromFile("prawiearial.ttf"))
	{
		cout << "Nie laduje sie czcionka" << endl;
	}


	if (!tlo.loadFromFile("backgroundesc.png"))
	{
		cout << "Nie laduje sie tlo" << endl;
	}

	background.setSize(Vector2f(width, height));
	background.setTexture(&tlo);

	difficulty[0].setFillColor(Color::Yellow);
	difficulty[0].setFont(font);
	difficulty[0].setString("Wybierz\npoziom trudnosci");
	difficulty[0].setPosition(50, 150);  //X , Y 
	difficulty[0].setCharacterSize(25);

	difficulty[1].setFillColor(Color::White);
	difficulty[1].setFont(font);
	difficulty[1].setString("BabyMode");
	difficulty[1].setPosition(50, 220);  //X , Y 
	difficulty[1].setCharacterSize(25);

	difficulty[2].setFillColor(Color::White);
	difficulty[2].setFont(font);
	difficulty[2].setString("JurekMode");
	difficulty[2].setPosition(50, 290);  //X , Y 
	difficulty[2].setCharacterSize(25);

	difficulty[3].setFillColor(Color::White);
	difficulty[3].setFont(font);
	difficulty[3].setString("Zdrajkus");
	difficulty[3].setPosition(50, 360);  //X , Y 
	difficulty[3].setCharacterSize(25);

	difficulty[4].setFillColor(Color::White);
	difficulty[4].setFont(font);
	difficulty[4].setString("Wybierz\nswoj nick");
	difficulty[4].setPosition(400, 150);  //X , Y 
	difficulty[4].setCharacterSize(25);

	difficulty[5].setFillColor(Color::White);
	difficulty[5].setFont(font);
	difficulty[5].setString("Zadymiarz");
	difficulty[5].setPosition(400, 220);  //X , Y 
	difficulty[5].setCharacterSize(25);

	difficulty[6].setFillColor(Color::White);
	difficulty[6].setFont(font);
	difficulty[6].setString("ElPrimo");
	difficulty[6].setPosition(400, 290);  //X , Y 
	difficulty[6].setCharacterSize(25);



	difficulty[7].setFillColor(Color::White);
	difficulty[7].setFont(font);
	difficulty[7].setString("QueenOfTheBlack");
	difficulty[7].setPosition(400, 360);  //X , Y 
	difficulty[7].setCharacterSize(25);
	selectedrow = 0;



}

Options::~Options()
{
}

void Options::draw(RenderWindow& window)
{
	window.draw(background);
	for (int i = 0; i < 8; i++)
	{
		window.draw(difficulty[i]);

	}
}

void Options::MoveUpper()
{
	if (selectedrow - 1 >= 0)
	{
		difficulty[selectedrow].setFillColor(Color::White);

		selectedrow--;
		difficulty[selectedrow].setFillColor(Color::Yellow);
	}
	else
	{
		selectedrow = 7;
		difficulty[0].setFillColor(Color::White);
		difficulty[selectedrow].setFillColor(Color::Yellow);
	}

}

void Options::MoveDown()
{
	if (selectedrow + 1 < 8)
	{
		difficulty[selectedrow].setFillColor(Color::White);
		selectedrow++;
		difficulty[selectedrow].setFillColor(Color::Yellow);
	}
	else
	{
		selectedrow = 0;

		difficulty[7].setFillColor(Color::White);
		difficulty[selectedrow].setFillColor(Color::Yellow);
	}


}

void Options::choosenpositions(int dif, int nick)
{
	choosendif = dif;
	choosennick = nick;
	difficulty[choosendif].setFillColor(Color::Green);
	difficulty[choosennick].setFillColor(Color::Green);
	for (int i = 0; i < 8; i++)
	{
		if (i != choosendif && i != selectedrow && i!=choosennick)
		{
			difficulty[i].setFillColor(Color::White);
		}
	}


}
