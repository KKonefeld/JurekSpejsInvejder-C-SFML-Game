#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class MainMenu
{
public:
	MainMenu(float width, float height);
	~MainMenu();

	void draw(RenderWindow& window);
	void MoveUpper();
	void MoveDown();
	// to wyzej to od ruszania sie po menu szcza³kami
	int GetPressedItemID() { return selectedItemID; }

private:
	int selectedItemID;
	Font font;
	Text menuItem[5]; //ilosc itemsow w menu
	Texture tlo;
	RectangleShape background;
	Text tittle[1];
	Font tittlef;

};

