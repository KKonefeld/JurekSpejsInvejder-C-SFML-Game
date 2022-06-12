#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class Options
{
public:
	Options(float width, float height);
	~Options();

	void draw(RenderWindow& window);
	void MoveUpper();
	void MoveDown();
	void choosenpositions(int dif, int nick);
	// to wyzej to od ruszania sie po menu szcza³kami
	int GetPressedItemID() { return selectedrow; }

private:
	int selectedrow;
	int choosendif, choosennick;
	Font font;
	Text difficulty[8]; //ilosc itemsow w menu
	Texture tlo;
	RectangleShape background;


};


