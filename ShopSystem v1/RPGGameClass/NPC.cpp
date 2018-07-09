#include "NPC.h"
#include "stdafx.h"

void NPC::setUP()
{
	pack->setUp();
}

string NPC::getName()
{
	return Name;
}

void NPC::Shop(Player Shopper)
{
	pack->Shop(Shopper, *this);
}