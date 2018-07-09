#pragma once

#include "stdafx.h"
#include "Backpack.h"
#include "Player.h"
#include <string>
#include <iostream>

using std::string;

class Backpack;
class Player;
class Enemy;
class NPC;

class Item
{
private:
	string name;
	int Damage;
	int cost;
	int type;
	/* Ammo Types:
	0 - light
	1 - medium
	2 - heavy
	3 - cannonballs
	4 - mellee*/
	int size;
	int range;
	int currentAmmo;
	int spread;
	bool cons;
	int health;
	int number;
	int max;

public: 
	Item(string Name, int weaponDamage, int Cost, int ammoType, int maxAmmo, int Range, int Spread, int healthGained, bool consumable, int startingStack, int maxStack);
	Item();
	int getNumber();
	int maxStack();
	void changeNumber(int);
	void shoot(Player, Enemy);
	void reload(Backpack);
	bool hit();
	string getName();
	int getCost();
};
