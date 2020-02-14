
#pragma once

#include "Player.h"

class Item;
class Player;
class Backpack;
class Enemy;

class Enemy {
private:
	int HP;
	int Atk;
	int Acc;
	string Name;
	Item drop;

public:
	Enemy(string name, int Health, int Attack, int HitChance, Item itemDrop)
	{
		HP = Health;
		Atk = Attack;
		Acc = HitChance;
		Name = name;
		drop = itemDrop;
	}
	void fight(Player);
	void hit();
	void attack();
	void changeHP(int);
	int getHP();
};
