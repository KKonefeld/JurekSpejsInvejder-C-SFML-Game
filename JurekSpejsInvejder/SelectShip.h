#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class SelectShip
{
public:
	SelectShip(float width, float height);
	~SelectShip();

	void draw(RenderWindow& window);
	void MoveUpper();
	void MoveDown();
	int GetPressedItemID() { return selectedItemID; }

private:
	int selectedItemID;
	Font font;
	Text Item[3];
	Texture tlo;
	RectangleShape background;

};

