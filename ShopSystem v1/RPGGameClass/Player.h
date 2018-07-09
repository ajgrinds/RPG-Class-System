#pragma once

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"
#include <cmath>
#include "Item.h"
#include "Backpack.h"
#include "Enemy.h"
#include "NPC.h"
#include "Moves.h"

class Moves;
class Enemy;
class Backpack;
class Item;
class NPC;

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Player {
private:
	string Name;
	int Health;
	string Class;
	//vector<Moves> moves;
	//float Acc;
	int size;
	int Atk = 0;
	int Def = 0;
	bool thirstDamage;
	bool hungerDamage;
	string BackpackName;
	Item equipped;

protected:
	int Level;
	int Thirst;
	int Hunger;
	float Money;
	float Owe;


public:
	Backpack * pack;
	Player(string PlayerName) {
		Name = PlayerName;
		Health = 100;
		//Acc = PlayerAccuracy;
		Level = 1;
		Thirst = 0;
		Hunger = 0;
		BackpackName = PlayerName;
		thirstDamage = false;
		hungerDamage = false;
		pack = new Backpack(20, 1000, 0, 10, 10, 10, 10);
	}
	void day();
	string getName();
	void changeMoney(float);
	float getMoney();
	int getAmmo(int);
	void Stats();
	void changeAmmo(int, int);
	void changeHealth(float);
	void levelUp();
	void changeHunger(int);
	void changeThirst(int);
	void changeAcc(int);
	//int getAcc();
	float getHealth();
	int getLevel();
	int getThirst();
	int getHunger();
	int getDef();
	void changeDef(int);
	int getAtk();
	void changeAtk(int);
	bool changeEquip(Item);
	vector<Moves> getMoves();
	Item getEquip();
	void attack(Enemy);
};
