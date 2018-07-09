#include "stdafx.h"
#include <iostream>
#include <string>
#include "windows.h"
#include "Backpack.h"

bool Backpack::add(Item item)
{
	for (int i = 0; i < Inside.size(); i++)
	{
		if (item.getName() == Inside[i].getName() && item.getNumber() < item.maxStack())
		{
			Inside[i].changeNumber(1);
			cout << Inside[i].getName() << " now has " << Inside[i].getNumber() << " in its stack." << endl;
			return true;
		}
	}
	if (Inside.size() < size)
	{
			Inside.push_back(item);
			cout << item.getName() << " added to your backpack" << endl;
			Inside[Inside.size() - 1].changeNumber(-(Inside[Inside.size() - 1].getNumber() - 1));
			return true;
	}
	else
	{
		cout << "Oh no, your backpack is full!" << endl;
		return false;
	}
}

void Backpack::NPCadd(Item item)
{
	for (int i = 0; i < Inside.size(); i++)
	{
		if (item.getName() == Inside[i].getName() && Inside[i].getNumber() < Inside[i].maxStack())
		{
			Inside[i].changeNumber(1);
			return;
		}
	}
	Inside.push_back(item);
}

Item Backpack::getInside(int i)
{
	return Inside[i];
}

int Backpack::getSize()
{
	return Inside.size();
}

bool Backpack::remove(Item item)
{
	for (u_int i = 0; i < Inside.size(); i++)
	{
		if (Inside[i].getName() == item.getName())
		{
			if (Inside[i].getNumber() > 1)
			{
				cout << "You took a " << item.getName() << " out of your backpack." << endl;
				Inside[i].changeNumber(-1);
				cout << "You now have " << Inside[i].getNumber() << " in your backpack" << endl;
				return true;
			}
			else
			{
				cout << "You took " << item.getName() << " out of your backpack." << endl;
				Inside.erase(Inside.begin() + i);
				return true;
			}
		}
	}
		cout << item.getName() << " is not inside of your backpack! " << endl;
		return false;
}

void Backpack::Inventory()
{
	if (Inside.size() == 0)
	{
		cout << "There is nothing in your backpack." << endl;
	}
	else {
		for (u_int i = 0; i < Inside.size(); i++)
		{
			int index = i + 1;
			cout << index << ". " << Inside[i].getName() << endl;
		}
		cout << "Max size: " << size << endl;
		cout << "Currently using: " << Inside.size() << endl;
		cout << "Space left: " << size - Inside.size() << endl;
	}
}

float Backpack::getMoney()
{
	return Money;
}

void Backpack::changeMoney(float change)
{
	Money += change;
	if (Money < 0)
	{
		changeOwe(-1 * Money);
		Money = 0;
	}
}

void Backpack::changeOwe(float change)
{
	Owe += change;
}

float Backpack::getOwe()
{
	return Owe;
}

void Backpack::Shop(Player &Shopping)
{
	system("cls");
	cout << "You have " << Shopping.getMoney() << " money." << endl;
	cout << "Here's what I have for sale: " << endl;
	Sleep(100);
	for (u_int i = 0; i < Inside.size(); i++)
	{
		if (Inside[i].getNumber() > 1)
		{
			cout << i + 1 << ". " << Inside[i].getName() << "s x" << Inside[i].getNumber() << " " << Inside[i].getCost() << " coins each." << endl;
		}
		else {
			cout << i + 1 << ". " << Inside[i].getName() << " " << Inside[i].getCost() << " coins" << endl;
		}

		Sleep(10);
	}
	cout << "Would you like to buy anything? (Index number if so, 0 if no, " << Inside.size() + 1 << " if you want to sell stuff) " << endl;
	int buy;
	cin >> buy;
	if (buy == Inside.size() + 1)
	{ 
		system("cls");
		Sell(Shopping);
		return;
	}
	buy--;
	if(Inside.size() < buy || buy < 0)
	{
		cout << "Thank you and please come again!" << endl;
		cout << "*You left the shop*" << endl;
		return;
	}
	else if(Inside[buy].getCost() > Shopping.getMoney())
	{
		int another;
		cout << "Silly fool, you don't have money for that!" << endl;
		cout << "Would u like to buy or sell anything else? (1 for yes / 0 for no / 2 for sell)" << endl;
		cin >> another;
		if (another == 1)
		{
			Shop(Shopping);
		}
		else if (another == 2)
		{
			Sell(Shopping);
		}
		else
		{
			return;
		}
	}
	else if (Inside.size() > buy && buy >= 0)
	{
		cout << "You bought " << Inside[buy].getName() << "." << endl;
		Shopping.changeMoney(-Inside[buy].getCost());
		cout << "Your backpack now has " << Shopping.getMoney() << " money." << endl;
		Shopping.pack->add(Inside[buy]);
		NPCremove(Inside[buy]);
		int again;
		cout << "Would you like to buy something else? (1 for yes, 0 for no, 2 for sell) " << endl;
		cin >> again;
		if (again == 1)
		{
			system("cls");
			Shop(Shopping);
		}
		else if (again == 2)
		{
			system("cls");
			Sell(Shopping);
		}
		else
		{
			cout << "Thank you and please come again." << endl;
			cout << "*You left the shop*" << endl;
			Sleep(1000);
			system("cls");
		}
	}
	else
	{
		cout << "Oops something happened" << endl;
	}
}

void Backpack::Shop(Player &Shopping, NPC npc)
{
	system("cls");
	cout << "You have " << Shopping.getMoney() << " money." << endl;
	cout << "Here's what " << npc.getName() << " has for sale: " << endl;
	Sleep(100);
	for (u_int i = 0; i < Inside.size(); i++)
	{
		if (Inside[i].getNumber() > 1)
		{
			cout << i + 1 << ". " << Inside[i].getName() << "s x" << Inside[i].getNumber() << " " << Inside[i].getCost() << " coins each." << endl;
		}
		else {
			cout << i + 1 << ". " << Inside[i].getName() << " " << Inside[i].getCost() << " coins" << endl;
		}

		Sleep(10);
	}
	cout << "Would you like to buy anything? (Index number if so, 0 if no, " << Inside.size() + 1 << " if you want to sell stuff) " << endl;
	int buy;
	cin >> buy;
	if (buy == Inside.size() + 1)
	{
		system("cls");
		Sell(Shopping);
		return;
	}
	buy--;

	if (Inside.size() < buy || buy < 0)
	{
		cout << "Thank you and please come again!" << endl;
		cout << "*You left the shop*" << endl;
		return;
	}
	else if (Inside[buy].getCost() > Shopping.getMoney())
	{
		int another;
		cout << "Silly fool, you don't have money for that!" << endl;
		cout << "Would u like to buy or sell anything else? (1 for yes / 0 for no / 2 for sell)" << endl;
		cin >> another;
		if (another == 1)
		{
			Shop(Shopping);
		}
		else if (another == 2)
		{
			Sell(Shopping);
		}
		else
		{
			return;
		}
	}
	else if (Inside.size() > buy && buy >= 0)
	{
		cout << "You bought " << Inside[buy].getName() << "." << endl;
		Shopping.changeMoney(-Inside[buy].getCost());
		cout << "Your backpack now has " << Shopping.getMoney() << " money." << endl;
		Shopping.pack->add(Inside[buy]);
		NPCremove(Inside[buy]);
		int again;
		cout << "Would you like to buy something else? (1 for yes, 0 for no, 2 for sell) " << endl;
		cin >> again;
		if (again == 1)
		{
			system("cls");
			Shop(Shopping);
		}
		else if (again == 2)
		{
			system("cls");
			Sell(Shopping);
		}
		else
		{
			cout << "Thank you and please come again." << endl;
			cout << "*You left the shop*" << endl;
			Sleep(1000);
			system("cls");
		}
	}
	else
	{
		cout << "Oops something happened" << endl;
	}
}

void Backpack::Sell(Player selling, NPC npc)
{
	Sleep(1000);
	system("cls");
	cout << "You can sell anything." << endl;
	u_int sell = -1;
	bool agai;
	if (selling.pack->Inside.size() == 0)
	{
		cout << "There is nothing to sell, fool." << endl;
		cout << "Would you like to buy anything else from " << npc.getName() << "? (1 if yes, 0 if no)" << endl;
		cin >> agai;
		if (agai)
		{
			Shop(selling, npc);
		}
		else
		{
			cout << "Thanks for stopping by!" << endl;
			cout << "*You left the shop*" << endl;
		}
	}
	else {
		for (int i = 0; i < selling.pack->Inside.size(); i++)
		{
			cout << Inside[i].maxStack();
			if (Inside[i].getNumber() > 1)
			{
				cout << i + 1 << ". " << Inside[i].getName() << "s x" << Inside[i].getNumber() << " " << Inside[i].getCost() * .5 << " coins each." << endl;
			}
			else
			{
				cout << i + 1 << ". " << selling.pack->Inside[i].getName() << " " << selling.pack->Inside[i].getCost() * .5 << " coins" << endl;
				Sleep(10);
			}
		}
		cout << "Would you like to sell anything to " << npc.getName() << "? (Index number if so, 0 if no, " << selling.pack->Inside.size() + 1 << " to buy stuff.)" << endl;
		cin >> sell;
		sell--;
	}
	if (sell > selling.pack->Inside.size() || sell < 0)
	{
		cout << "Thanks for stopping by!" << endl;
		cout << "You left the shop." << endl;	
	}
	else if (sell == selling.pack->Inside.size())
	{
		Shop(selling);
	}
	else if (sell < selling.pack->Inside.size())
	{
		if (selling.pack->Inside[sell].getNumber() > 1)
		{
			cout << "You now have " << selling.pack->Inside[sell].getNumber() -1 << " " << selling.pack->Inside[sell].getName() << "s." << endl;
		}
		selling.changeMoney(selling.pack->Inside[sell].getCost() * .5);
		selling.pack->remove(selling.pack->Inside[sell]);
		NPCadd(Inside[sell]);
		cout << "You now have " << selling.pack->getMoney() << " money." << endl;
		cout << "Would you like to buy or sell anything else? (1 if yes, 0 if no, 2 if buy)" << endl;
		int again;
		cin >> again;
		if (again == 1)
		{
			Sell(selling);
		}
		else if (again == 2)
		{
			Shop(selling);
		}
		else
		{
			cout << "Thanks for stopping by!" << endl;
		}
	}

}

void Backpack::Sell(Player selling)
{
	Sleep(1000);
	system("cls");
	cout << "You can sell anything." << endl;
	u_int sell = -1;
	if (selling.pack->Inside.size() == 0)
	{
		cout << "There is nothing to sell, fool." << endl;
		cout << "Would you like to buy anything else? (1 if yes, 0 if no)" << endl;
		bool again;
		cin >> again;
		if (again)
		{
			Shop(selling);
		}

	}
	else {
		for (int i = 0; i < selling.pack->Inside.size(); i++)
		{
			if (selling.pack->Inside[i].getNumber() > 1)
			{
				cout << i + 1 << ". " << selling.pack->Inside[i].getName() << "s x" << selling.pack->Inside[i].getNumber() << " " << selling.pack->Inside[i].getCost() * .5 << " coins each." << endl;
			}
			else
			{
				cout << i + 1 << ". " << selling.pack->Inside[i].getName() << " " << selling.pack->Inside[i].getCost() * .5 << " coins" << endl;
				Sleep(10);
			}
		}
		cout << "Would you like to sell anything? (Index number if so, 0 if no, " << selling.pack->Inside.size() + 1 << " to buy stuff.)" << endl;
		cin >> sell;
		sell--;
	}
	if (sell > selling.pack->Inside.size() || sell < 0)
	{
		cout << "Thanks for stopping by!" << endl;
		cout << "You left the shop." << endl;
	}
	else if (sell == selling.pack->Inside.size())
	{
		Shop(selling);
	}
	else if (sell < selling.pack->Inside.size())
	{
		selling.changeMoney(selling.pack->Inside[sell].getCost() * .5);
		selling.pack->remove(selling.pack->Inside[sell]);
		NPCadd(Inside[sell]);
		cout << "You now have " << selling.pack->getMoney() << " money." << endl;
		cout << "Would you like to buy or sell anything else? (1 if yes, 0 if no, 2 if buy)" << endl;
		int again;
		cin >> again;
		if (again == 1)
		{
			Sell(selling);
		}
		else if (again == 2)
		{
			Shop(selling);
		}
		else
		{
			cout << "Thanks for stopping by!" << endl;
		}
	}

}

int Backpack::getAmmo(int type)
{
	return ammoTotal[type];
}

bool Backpack::changeAmmo(int type, int amount)
{
	switch (type)
	{
	case 0:
		ammoTotal[type] += amount;
		cout << "You now have " << ammoTotal[type] << " light ammo.";
		return true;
		break;
	case 1:
		ammoTotal[type] += amount;
		cout << "You now have " << ammoTotal[type] << " medium ammo.";
		return true;
		break;
	case 2:
		ammoTotal[type] += amount;
		cout << "You now have " << ammoTotal[type] << " heavy ammo.";
		return true;
		break;
	case 3:
		ammoTotal[type] += amount;
		cout << "You now have " << ammoTotal[type] << " cannonballs.";
		return true;
		break;
	default:
		return false;
		break;
	}
}

void Backpack::setUp() {
	Item EoR = Item("Eye of reach", 45, 150, 2, 3, 1000, 1, NULL, false, 1, 1);
	Item Revolver = Item("Revolver", 10, 100, 1, 6, 40, 2, NULL, false, 1, 1);
	Item Blunderbuss = Item("Blunderbuss", 55, 65, 3, 3, 10, 6, NULL, false, 1, 1);
	Item Cutlass = Item("Cutlass", 20, 30, NULL, 1, 1, 1, NULL, false, 1, 1);
	Item Banana = Item("Banana", NULL, 10, NULL, NULL, 0, 0, 10, true, 10, 10);
	Item Cannonball = Item("Cannonball", 50, 5, 3, 1, 100, 3, NULL, true, 15, 15);
	NPCadd(EoR);
	NPCadd(Revolver);
	NPCadd(Blunderbuss);
	NPCadd(Cutlass);
	NPCadd(Banana);
	NPCadd(Cannonball);
}

void Backpack::NPCremove(Item item)
{
	for (int i = 0; i < Inside.size(); i++)
	{
		if (Inside[i].getName() == item.getName())
		{
			if (Inside[i].getNumber() > 1)
			{
				Inside[i].changeNumber(-1);
				return;
			}
			else
			{
				Inside.erase(Inside.begin() + i);
				return;
			}
		}
	}
}