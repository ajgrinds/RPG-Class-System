#pragma once

#include "Player.h"
#include <random>

using std::random_device;

class Backpack;

class NPC {
private:
	int Level;
	string Name;
	string names[15] = { "Ryuuji", "Takasu", "Hiname", "Chichi", "Jessica", "Carolyne", "Rin Kun", "Amber", "Sarah", "Gretchen", "Susan", "Jessie", "Samantha", "Sombra", "Bretta" };
	int namesize = 15; //Make sure to change this if you add or remove names or they will not work

public:
	Backpack * pack;
	NPC()
	{
		random_device rd;
		int num = rd() % namesize;
		Name = names[num];
		pack = new Backpack(1, 1000, 0, 0, 0, 0, 0);
		setUP();
	}
	void setUP();
	string getName();
	void Shop(Player);
};
