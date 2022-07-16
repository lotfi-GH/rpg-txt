//#include "main.h"
#include "battle.h"
#include "map.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
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

void titleScreen() {

	std::cout << R"(

 ______   _______  _______  _______  _                                    _       _________ _______  _______ 
(  __  \ (  ____ \(       )(  ___  )( (    /|          |\     /||\     /|( (    /|\__   __/(  ____ \(  ____ )
| (  \  )| (    \/| () () || (   ) ||  \  ( |          | )   ( || )   ( ||  \  ( |   ) (   | (    \/| (    )|
| |   ) || (__    | || || || |   | ||   \ | |          | (___) || |   | ||   \ | |   | |   | (__    | (____)|
| |   | ||  __)   | |(_)| || |   | || (\ \) |          |  ___  || |   | || (\ \) |   | |   |  __)   |     __)
| |   ) || (      | |   | || |   | || | \   |          | (   ) || |   | || | \   |   | |   | (      | (\ (   
| (__/  )| (____/\| )   ( || (___) || )  \  |          | )   ( || (___) || )  \  |   | |   | (____/\| ) \ \__
(______/ (_______/|/     \|(_______)|/    )_)          |/     \|(_______)|/    )_)   )_(   (_______/|/   \__/
                                                                                                             



)" << "\n";

	char button;
	std::cout << "Press any key then 'ENTER' to star!";
	std::cin >> button ;
	system("cls");
}
void battle(int hp, int enemy, std::string items[3], int player_attack, int enemy_attack, std::string sprite) {


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
		enemyTurn(&hp, &enemy, &player_attack, &enemy_attack, sprite);
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

struct Player {
	std::string name;
	int hp{};
	int enemy{};
	std::string items[3];
	int player_attack{};
	int location{};
	std::string sprite;
};

struct Enemy {
	int hp{};
	int enemy_attack{};
	std::string sprite;
};

int main()
{	
	titleScreen();
	 //init();
	/*
	int hp = 100;
	int enemy = 100;
	std::string items[3];
	items[0] = "HEALTH++";
	items[1] = "ATTACK++";
	items[2] = "DEFENSE++";
	int player_attack = 5;
	int enemy_attack = 10;
	int location = 0;
	*/
	Player player;
	std::cout <<"What's your name!\n";
	std::cin >> player.name;
	player.hp = 100;
	int enemy = 100;
	player.items[0] = "HEALTH++";
	player.items[1] = "ATTACK++";
	player.items[2] = "DEFENSE++";
	player.player_attack = 5;
	player.location = 0;

	std::string map[10];
	int days=1;
	int death=0;
	int actions=0;

	Enemy demon;
	demon.hp = 100;
	demon.enemy_attack = 10;
	demon.sprite = R"(
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

)";
	//int enemy_attack = 10;
	std::string king = R"(
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

)";

	
	Sleep(1000);
	displayLocation(player.location);
	Sleep(2000);
	std::cout << "You arrived to a city.You have been called to help them get rid of a demon \n";
	Sleep(3000);
	std::cout << "You directly went to see the king\n";
	Sleep(3000);
	std::cout << king << "\n";
	Sleep(3000);
	
	std::cout << "KING : Thank you for coming "<<player.name<<"! We were waiting for you!\n";
	Sleep(3000);
	std::cout << "KING : We'll directly get to the essential!\n";
	Sleep(3000);
	std::cout << "KING : The demon was last spot in the forest!\n";
	Sleep(3000);
	std::cout << "KING : Goodluck!\n";
	Sleep(3000);
	std::cout << "------------------------------------------------\n";
	std::cout << "QUEST : You have to find the demon and kill it.\n";
	std::cout << "------------------------------------------------\n";
	Sleep(3000);
	displayLocation(player.location);
	while (player.location == 0) {
		std::cout << "Where do you want to go now?\n";
		std::cout << "(0)City                      (1) Forest\n";
		std::cout << "Type the number corresponding to your destination!\n";
		std::cin >> player.location;

		if (player.location != 1) {
			displayLocation(player.location);
			player.location = 0;
		}
	}
	//if (location != 1) { location = 1; }
	
	if(player.location==1){
	Sleep(2000);
	std::cout << "...\n";
	Sleep(2000);
	std::cout << "You went to the forst\n";
	Sleep(3000);
	std::cout << "...\n";
	displayLocation(player.location);
	Sleep(3000);
	std::cout << "...\n";
	Sleep(3000);
	std::cout << "You heard a sound\n";
	Sleep(3000);
	std::cout << "...\n";
	Sleep(3000);
	std::cout << demon.sprite << "\n";
	Sleep(500);
	std::cout << "		   A DEMON APPEARS!";
	Sleep(500);
	battle(player.hp, enemy, player.items, player.player_attack, demon.enemy_attack, demon.sprite);
	}
	
	Sleep(10000);
	std::cout << demon.sprite << "\n";

	std::cout << "DEMON : You think it's over but it's just the begining!\n";
	Sleep(3000);
	std::cout << "YOU: What?\n";
	Sleep(3000);
	std::cout << "DEMON : BLURGH!\n";
	Sleep(3000);
	std::cout << "The demon died right before your eyes.\n";
	Sleep(3000);
	std::cout << "You're taking a moment to think about what he just said.\n";
	Sleep(3000);
	std::cout << "------------------------------------------------\n";
	std::cout << "QUEST : you have to go back and inform the king.\n";
	std::cout << "------------------------------------------------\n";
	Sleep(3000);


	displayLocation(player.location);

	while (player.location == 1) {
		std::cout << "Where do you want to go now?\n";
		std::cout << "(0)City                      (1) Forest\n";
		std::cout << "Type the number corresponding to your destination!\n";
		std::cin >> player.location;

		if (player.location != 0) {
			displayLocation(player.location);
			player.location = 1;
		}
	}

	Sleep(2000);
	std::cout << "...\n";
	Sleep(2000);
	std::cout << "You went back to the city\n";
	Sleep(3000);
	displayLocation(player.location);
	Sleep(3000);
	std::cout << "You went right to see the king \n";
	Sleep(3000);
	std::cout << king;
	Sleep(3000);
	std::cout << "You informed him that you killed the demon\n";
	Sleep(3000);
	std::cout << "KING : Thank you very much for your hard work "<<player.name <<"!\n";
	Sleep(3000);
	std::cout << "KING : Here's your reward!\n";
	Sleep(3000);
	std::cout << "The king gave you 10000 gold\n";
	Sleep(3000);
	std::cout << "KING : You can rest in the city as much as you want!\n";
	Sleep(3000);
	std::cout << "KING : You're always welcome here!\n";
	Sleep(3000);




	 //battle(hp, enemy, items, player_attack, enemy_attack);
	//playerTurn()
	//enemyTurn()
	//playerTurn(hp,enemy,items,player_attack,enemy_attack);
	//std::cout << hp ;
	//enemyTurn(hp, enemy, player_attack, enemy_attack);
    return 0;
}