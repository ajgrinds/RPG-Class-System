#include "Player.h"
#include "stdafx.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string Player::getName()
{
	return Name;
}

void Player::changeMoney(float change)
{
	pack->changeMoney(change);
}

float Player::getMoney()
{
	return pack->getMoney();
}

void Player::day()
{
	levelUp();
	Hunger -= 10;
	Owe = Owe * 1.01;
}



void Player::Stats()
{
	std::cout << "Current Stats: \nMoney: ";
	std::cout << pack->getMoney() << std::endl;
	std::cout << "MoneyOwed: ";
	std::cout << pack->getOwe() << std::endl;
	std::cout << "Health: ";
	std::cout << Health << std::endl;
	std::cout << "Attack: ";
	std::cout << Atk << std::endl;
	std::cout << "Defense: ";
	std::cout << Def << std::endl;
	pack->Inventory();

}
int Player::getAtk()
{
	return Atk;
}

/*int Player::getAcc()
{
return Acc;
}*/

void Player::changeAcc(int change)
{
	//	Acc += change;
}

int Player::getLevel()
{
	return Level;
}

void Player::levelUp()
{
	Level++;
	Atk = Atk * 1.2;
	Def = Def * 1.2;
	//Acc = Acc * 1.05;
	cout << "You are now level: " << Level << endl;
}

void Player::changeHealth(float change)
{
	Health += change;
}

float Player::getHealth()
{
	return Health;
}

int Player::getHunger()
{
	return Hunger;
}

int Player::getThirst()
{
	return Thirst;
}

void Player::changeThirst(int change)
{
	Thirst += change;
	if (Thirst >= 100)
	{
		cout << "You're now taking thirst damage!! Drink water quickly!" << endl;
		Health -= 1;
		cout << "Current health: " << Health << endl;
		thirstDamage = true;
	}
	else if (Thirst >= 50)
	{
		cout << "You're getting thirsty. You might wanna get a drink! " << endl;
	}

}

void Player::changeHunger(int change)
{
	Hunger += change;
	if (Hunger >= 100)
	{
		cout << "You're now starving!! Eat food quickly! " << endl;
		cout << "Current health: " << Health << endl;
		hungerDamage = true;
	}
	else if (Hunger >= 50)
	{
		cout << "You're getting pretty hungry. You might wanna eat something! " << endl;
	}
}



void Player::changeAmmo(int type, int change)
{
	pack->changeAmmo(type, change);
}

int Player::getAmmo(int type)
{
	return pack->getAmmo(type);
}

bool Player::changeEquip(Item item)
{
	for (int i = 0; i < pack->getSize() - 1; i++)
	{
		if (item.getName() == pack->getInside(i).getName())
		{
			equipped = item;
			return true;
		}
	}
	cout << "Error, you cannot equip this item";
	return false;
}

Item Player::getEquip()
{
	return equipped;
}

void Player::attack(Enemy enemy)
{
	getEquip().shoot(*this, enemy);
}