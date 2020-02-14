#pragma once

#include "stdafx.h"
#include "Item.h"
#include "Backpack.h"
#include <random>

using namespace std;

Item::Item()
{
	Damage = 100000;
	cost = 100000;
	type = 0;
	size = 100000;
	range = 100000;
	spread = 100000;
	name = "Someone didn't do their job";
	health = 0;
	cons = false;
}

void Item::changeNumber(int change)
{
	number += change;
}

Item::Item(string Name, int weaponDamage, int Cost, int ammoType, int maxAmmo, int Range, int Spread, int healthGained, bool consumable, int startingStack, int maxStack)
{
	Damage = weaponDamage;
	cost = Cost;
	type = ammoType;
	size = maxAmmo;
	range = Range;
	spread = Spread;
	name = Name;
	health = healthGained;
	cons = consumable;
	number = startingStack;
	max = maxStack;
}

int Item::getNumber()
{
	return number;
}

int Item::maxStack()
{
	return max;
}

void Item::shoot(Player player, Enemy enemy)
{
	hit();
	if (hit())
	{
		cout << "Your bullet hit!";
		enemy.changeHP(-Damage);
		if (type != 4)
		{
			currentAmmo--;
		}
	}
	else
	{
		cout << "You missed! Rip to you.";
		if (type != 4)
		{
			currentAmmo--;
		}
	}
	if (currentAmmo == 0)
	{
		reload(*player.pack);
	}
}

void Item::reload(Backpack pack)
{
	if (type)
	{
		if (pack.getAmmo(type) >= size)
		{
			pack.changeAmmo(type, -size - currentAmmo);
			currentAmmo = size;
		}
		else if (pack.getAmmo(type) > 0)
		{
			currentAmmo += pack.getAmmo(type);
			pack.changeAmmo(type, -pack.getAmmo(type));
			cout << "You only reloaded " << currentAmmo << " bullets, you need to buy more!";
		}
		else
		{
			cout << "Error, you have no ammo, you need to buy more!";
		}
	}
}

string Item::getName()
{
	return name;
}

int Item::getCost()
{
	return cost;
}

bool Item::hit()
{
	int num;
	random_device rd;
	num = rd() % spread;
	if (num == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}