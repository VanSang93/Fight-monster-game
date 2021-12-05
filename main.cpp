#include <iostream>
#include <string>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

void attackMonster(Player &player, Monster &monster)
{
	if (player.isDead())
	{
		return;
	}
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
	monster.reduceHealth(player.getDamage());
	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		std::cout << "You are now level: " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

void attackPlayer(const Monster &monster, Player &player)
{
	if (monster.isDead())
	{
		return;
	}
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

void fightMonster(Player &player)
{
	Monster monster{Monster::getRandomMonster()};
	std::cout << "\nYou have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
	while (!monster.isDead() && !player.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input{};
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return;
			}
			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
				continue;
			}
		}
		if (input == 'F' || input == 'f')
		{
			attackMonster(player, monster);
			attackPlayer(monster, player);
		}
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::rand();

	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;
	Player player{name};
	std::cout << "Welcome, " << player.getName() << '\n';

	while (!player.isDead() && !player.hasWon())
	{
		fightMonster(player);
	}

	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << player.getGold() << " gold!\n";
	}

	return 0;
}