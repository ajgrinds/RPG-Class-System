// RPGGameClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	NPC bretta;
	Player ajgrinds = Player("ajgrinds");
	while (true)
	{
		bretta.Shop(ajgrinds);
		cout << ajgrinds.pack->getInside(0).getNumber();
		system("pause");
	}
	
	
}

