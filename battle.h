#pragma once
#include <string>

//void init();
void displayChoices(int hp, int enemy);
void displayItems(std::string items[3]);
void playerTurn(int *hp, int *enemy, std::string items[3], int *player_attack, int *enemy_attack);
void enemyTurn(int *hp, int *enemy, int *player_attack, int *enemy_attack);
//void battle(int hp, int enemy, std::string items[3], int player_attack, int enemy_attack);
//std::string attack();
//std::string useItem();

