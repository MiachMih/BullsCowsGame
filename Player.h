#pragma once
#include "Game.h"

class Player {
public:
	Player(const int &lives) 
	:lives(lives){}

	bool isAlive()const;

	void setDead();

	void takeHit();

	bool isIsogram() const; // checks if the input is of correct length and the word is an isogram

	void getInput(); // assigns input to the input string

	unsigned int checkLives();

	string input;

private:
	unsigned int lives;
};