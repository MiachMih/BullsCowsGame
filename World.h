#pragma once
#include "Game.h"
#include "Player.h"

class World: Game {
public:
	World(bool gameState)
	:Game(gameState){}

	void begin();

	void demandInput(Player* player)const;

	unsigned int countBC(Player * player) const;

	void forceChoose();

private:
	unsigned int score = 0;
};