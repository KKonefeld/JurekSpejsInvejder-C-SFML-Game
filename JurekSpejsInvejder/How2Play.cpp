#include "How2Play.h"
#include <iostream>

using namespace sf;
using namespace std;

How2Play::How2Play(float width, float height)
{


	if (!tlo.loadFromFile("howbackground.png"))
	{
		cout << "Nie laduje sie tlo" << endl;
	}

	background.setSize(Vector2f(width, height));
	background.setTexture(&tlo);




}

void How2Play::draw(RenderWindow& window)
{
	window.draw(background);

}


How2Play::~How2Play()
{
}
