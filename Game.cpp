#include "Game.h"
#include "Player.h"
#include "stdlib.h"
#include <ctime>



void Game::changeGameState() // changes state of the game to its polar oposite (on/off)
{
	this->gameState = !(this->gameState);
}

bool Game::isGameOn() const //check state of the game (on/off)
{
	return this->gameState;
}

void Game::assingNewWord() // assign a new random word from the list of words
{
	srand((unsigned)time(0));
	currentWord = &listOfWords[(rand() % size)];
}

int Game::getLength() const
{
	return currentWord->length();
}

