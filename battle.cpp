#include "battle.h"
#include <iostream>
#include<windows.h>
#include <algorithm>
//#include <string>

//int hp, enemy,player_attack,enemy_attack;
//std::string items[3];




void displayChoices(int hp, int enemy) {
	std::cout << R"(
		Your turn!
		Choose one action from the menu by typing "atk" or "items" in the console
		--------------------------------------------------------
		Player HP : )"<<hp <<R"(%                      Enemy HP : )" <<enemy << R"(%
		--------------------------------------------------------
		 -------ACTIONS-----------------------------------------
		|                                                       |	
		|   -------------               ---------------         |
		|  |   ATTACK    |             |     ITEMS     |        |
		|   -------------               ---------------	        |
		|                                                       |
		 -------------------------------------------------------
)" << "\n";
}
void displayItems(std::string items[3]) {
	std::cout << "		Choose one item from list by typing its number in the console!";
	for (int i = 0; i < 3; i++) {
		std::cout <<R"(

				 ---------------------------
				|  ()" << i + 1 << R"()     )"<< items[i] << R"(         |             
				 ---------------------------
)" << "\n";
	}
}


void playerTurn(int *hp, int *enemy, std::string items[3], int *player_attack, int *enemy_attack)
{	
	std::string choice;
	int item;
	displayChoices(*hp, *enemy);
	std::cin >> choice;
	std::transform(choice.begin(), choice.end(), choice.begin(), std::tolower);
	if (choice == "atk"){
		*enemy -= *player_attack;
		Sleep(1000);
		std::cout << "You inflicted "<< *player_attack <<  "% damage to your enemy!  \n";
	}
	else {
		Sleep(1000);
		displayItems(items);
		std::cin >> item;
		switch (item) {
		case 1:
			*hp += 10;
			Sleep(1000);
			std::cout << "You restored " << 10 << "% of HP!  \n";
			break;
		case 2 :
			*player_attack += 10;
			Sleep(1000);
			std::cout << "Your attack got booseted by " << 10 << "%!  \n";
			break;
		case 3 :
			*enemy_attack -= 2;
			Sleep(1000);
			std::cout << "Your defense got booseted by " << 2 << "%!  \n";
			break;
		}
	}
}

void enemyTurn(int *hp, int *enemy, int *player_attack, int *enemy_attack) {
	Sleep(1000);
	std::cout << "		--------------------------------------------------------\n";
	std::cout << "		Player HP : " <<*hp <<"%                      Enemy HP : " << *enemy << "% \n";
	std::cout << "		--------------------------------------------------------\n";
	Sleep(1000);
	std::cout << "Your enemy's turn!\n";
	*hp -= *enemy_attack;
	Sleep(1000);
	std::cout << "Your enemy infilcted " << *enemy_attack << "% damage to you!  \n";
	Sleep(1000);
}
/*
void battle(int hp, int enemy, std::string items[3], int player_attack, int enemy_attack) {

	playerTurn(*hp, *enemy, items, *player_attack, *enemy_attack);
	std::cout << hp;
	enemyTurn(hp, enemy, player_attack, enemy_attack);
}*/