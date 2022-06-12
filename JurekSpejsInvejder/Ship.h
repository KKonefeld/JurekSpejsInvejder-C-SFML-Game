#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Ship
{
public:
	Ship(int id);
	Shape &getShape();
	void set_location(float, float);
	void draw(RenderWindow &win);
	void changetexture(int idnumber);
	void setHP(int hp);
	int getHP();
	void setScore(int sc);
	int getScore();
	void givePoints();
private:
	RectangleShape shape;
	Texture texture;
	int HP = 10;
	int Score = 0;
};

