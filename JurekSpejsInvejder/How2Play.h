#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class How2Play
{
public:
	How2Play(float width, float height);
	void draw(RenderWindow& window);
	~How2Play();


private:

	Texture tlo;
	RectangleShape background;

};