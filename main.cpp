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
#include "map.h"
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
	int location = 0;
	Sleep(1000);
	displayLocation(location);
	Sleep(2000);
	std::cout << "You arrived to a city.You have been called to help them get rid of a demon \n";
	Sleep(3000);
	std::cout << "You directly went to see the king\n";
	Sleep(3000);
	std::cout << R"(
                    .
                   / \
                  _\ /_
        .     .  (,'v`.)  .     .
        \)   ( )  ,' `.  ( )   (/
         \`. / `-'     `-' \ ,'/
          : '    _______    ' :
          |  _,-'  ,-.  `-._  |
          |,' ( )__`-'__( ) `.|
          (|,-,'-._   _.-`.-.|)
          /  /<( o)> <( o)>\  \
          :  :     | |     :  :
          |  |     ; :     |  |
          |  |    (.-.)    |  |
          |  |  ,' ___ `.  |  |
          ;  |)/ ,'---'. \(|  :
      _,-/   |/\(       )/\|   \-._
_..--'.-(    |   `-'''-'   |    )-.`--.._
         `.  ;`._________,':  ,'
        ,' `/               \'`.
             `------.------'           

)" << "\n";
	Sleep(3000);
	
	std::cout << "KING : Thank you for coming! We were waiting for you!\n";
	Sleep(3000);
	std::cout << "KING : We'll directly get to the essential!\n";
	Sleep(3000);
	std::cout << "KING : The demon was last spot in the forest!\n";
	Sleep(3000);
	std::cout << "KING : Goodluck!\n";
	Sleep(3000);

	displayLocation(location);
	while (location == 0) {
		std::cout << "Where do you want to go now?\n";
		std::cout << "(0)City                      (1) Forest\n";
		std::cout << "Type the number corresponding to your destination!\n";
		std::cin >> location;

		if (location != 1) {
			displayLocation(location);
			location = 0;
		}
	}
	//if (location != 1) { location = 1; }
	
	if(location==1){
	Sleep(2000);
	std::cout << "...\n";
	Sleep(2000);
	std::cout << "You went to the forst\n";
	Sleep(3000);
	std::cout << "...\n";
	displayLocation(location);
	Sleep(3000);
	std::cout << "...\n";
	Sleep(3000);
	std::cout << "You heard a sound\n";
	Sleep(3000);
	std::cout << "...\n";
	Sleep(3000);
	std::cout << R"(
                            ,-.
       ___,---.__          /'|`\          __,---,___
    ,-'    \`    `-.____,-'  |  `-.____,-'    //    `-.
  ,'        |           ~'\     /`~           |        `.
 /      ___//              `. ,'          ,  , \___      \
|    ,-'   `-.__   _         |        ,    __,-'   `-.    |
|   /          /\_  `   .    |    ,      _/\          \   |
\  |           \ \`-.___ \   |   / ___,-'/ /           |  /
 \  \           | `._   `\\  |  //'   _,' |           /  /
  `-.\         /'  _ `---'' , . ``---' _  `\         /,-'
     ``       /     \    ,='/ \`=.    /     \       ''
             |__   /|\_,--.,-.--,--._/|\   __|
             /  `./  \\`\ |  |  | /,//' \,'  \
            /   /     ||--+--|--+-/-|     \   \
           |   |     /'\_\_\ | /_/_/`\     |   |
            \   \__, \_     `~'     _/ .__/   /
             `-._,-'   `-._______,-'   `-._,-'

)" << "\n";
	Sleep(500);
	std::cout << "		   A DEMON APPEARS!";
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