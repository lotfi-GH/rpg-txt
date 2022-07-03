/*
#include <iostream>

int main()
{
	std::cout << "Hello, world!";
	return 0;
}

*/
//#include "main.h"
#include "battle.h"
#include <iostream>
#include<windows.h>
/*
void init() {

	hp = 100;
	enemy = 100;
	items[0] = "potion";
	items[1] = "attack++";
	items[2] = "defense++";
	player_attack = 5;
	enemy_attack = 10;
}

*/

int main()
{	
	 //init();
	int hp = 100;
	int enemy = 100;
	std::string items[3];
	items[0] = "HEALTH++";
	items[1] = "ATTACK++";
	items[2] = "DEFENSE++";
	int player_attack = 5;
	int enemy_attack = 10;
	Sleep(500);
	std::cout << "		   A WILD ENEMY APPEARS!";
	Sleep(500);
	std::cout << R"(


		 ____        _   _   _               _             _   _ 
		|  _ \      | | | | | |             | |           | | | |
		| |_) | __ _| |_| |_| | ___      ___| |_ __ _ _ __| |_| |
		|  _ < / _` | __| __| |/ _ \    / __| __/ _` | '__| __| |
		| |_) | (_| | |_| |_| |  __/    \__ \ || (_| | |  | |_|_|
		|____/ \__,_|\__|\__|_|\___|    |___/\__\__,_|_|   \__(_)
                                                          
                                                          


)" << "\n";
	Sleep(500);
	while (hp > 0 || enemy > 0) {
		//std::cout << hp;
		playerTurn(&hp, &enemy, items, &player_attack, &enemy_attack);
		//std::cout << hp;
		if (enemy <= 0) {
			std::cout << R"(


 __     ______  _    _  __          _______ _   _ _ 
 \ \   / / __ \| |  | | \ \        / /_   _| \ | | |
  \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| | |
   \   /| |  | | |  | |   \ \/  \/ /   | | | . ` | |
    | | | |__| | |__| |    \  /\  /   _| |_| |\  |_|
    |_|  \____/ \____/      \/  \/   |_____|_| \_(_)
                                                    
                                                    



)" << "\n";
			break; 
		}
		enemyTurn(&hp, &enemy, &player_attack, &enemy_attack);
		if (hp <= 0) {
			std::cout << R"(


 __     ______  _    _   _      ____   _____ ______ _ 
 \ \   / / __ \| |  | | | |    / __ \ / ____|  ____| |
  \ \_/ / |  | | |  | | | |   | |  | | (___ | |__  | |
   \   /| |  | | |  | | | |   | |  | |\___ \|  __| | |
    | | | |__| | |__| | | |___| |__| |____) | |____|_|
    |_|  \____/ \____/  |______\____/|_____/|______(_)
                                                      
                                                      
                                
                                     


)" << "\n";

			break;
		}

	}


	Sleep(10000);
	 //battle(hp, enemy, items, player_attack, enemy_attack);
	//playerTurn()
	//enemyTurn()
	//playerTurn(hp,enemy,items,player_attack,enemy_attack);
	//std::cout << hp ;
	//enemyTurn(hp, enemy, player_attack, enemy_attack);
    return 0;
}