#pragma once

#include "Item.h"
#include "Player.h"
#include <string>
#include <vector>


using std::string;
using std::vector;
using namespace std;

class Item;
class Player;
class Enemy;
class NPC;

class Backpack {
private:
	u_int size;
	vector<Item> Inside;
	float Money;
	float Owe;

protected:
	int ammoTotal[4];

public:
	Backpack(int BackpackSize, float PlayerMoney, float PlayerOwe, int startingSmallAmmo, int startingMediumAmmo, int startingHeavyAmmo, int startingCannonballs)
	{
		size = BackpackSize;
		Money = PlayerMoney;
		Owe = PlayerOwe;
		ammoTotal[0] = startingSmallAmmo;
		ammoTotal[1] = startingMediumAmmo;
		ammoTotal[2] = startingHeavyAmmo;
		ammoTotal[3] = startingCannonballs;
	}
	bool add(Item);
	bool remove(Item);
	void changeOwe(float);
	void changeMoney(float);
	float getMoney();
	float getOwe();
	void Inventory();
	Item getInside(int);
	int getSize();
	void Shop(Player&);
	void Shop(Player&, NPC);
	void Sell(Player);
	void Sell(Player, NPC);
	void setUp();
	int getAmmo(int);
	bool changeAmmo(int, int);
	void NPCadd(Item);
	void NPCremove(Item);
};