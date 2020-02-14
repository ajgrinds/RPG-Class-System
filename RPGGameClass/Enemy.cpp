#include "Enemy.h"
#include "stdafx.h"

void Enemy::changeHP(int change)
{
	HP -= change;
}

int Enemy::getHP()
{
	return HP;
}

void Enemy::fight(Player player)
{
	cout << "You have encountered " << Name << "." << endl;
	cout << "You can try to run, but will take " << Atk << " damage." << endl;
	cout << "Do you want to run away? (1 for yes, 0 for no)" << endl;
	bool run;
	cin >> run;
	if (run == true)
	{
		player.changeHealth(-Atk);
	}
	else
	{
		bool fighting = true;
		cout << "You have begun to fight.";
		while (fighting = true)
		{
			cout << "Its your move " << player.getName() << "." << endl;
			cout << "What do you choose to do?" << endl;
			//cout << player.getMoves();
		}
	}
}


void Enemy::attack()
{

}