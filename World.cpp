#include "Game.h"
#include "Player.h"
#include "World.h"

void World::begin()
	
	// keep score of the player (+1 if win, +0 if die)
{
	while (isGameOn()) {
		assingNewWord(); 
		Player* player = new Player(getLength()); 

		cout << "Guess an isogram that is  " << getLength() << " characters long" << endl;
		while (player->isAlive()) { // loop will be exited if the player died
			cout << "You've got: "<< player->checkLives() << " lives\n"; // show how many lives the player has

			demandInput(player); // get the correct input

			if (countBC(player) == getLength()) { // check if player guessed correct word, and display the bull/cow count
				score++; // increase player score
				player->setDead(); // escape the loop because player won
				break;
			}
			player->takeHit(); // reduce player health for not getting correct answer
		}
		delete player; // destroy player when player wins or dies to reset life count in the new game
		cout << endl << "Your current score is " << score;

		forceChoose(); // (player has to choose y/Y or n/N) 
		cout << "-------------------New Game-------------------" << endl;
	}
}

void World::demandInput(Player * player)const // persists until user gives a valid input
{
	player->getInput();
	while (!(player->isIsogram()) || (player->input.length() - getLength())) { // get the input from the player until it is a correct input
		cout << "Try again!" << endl;
		player->getInput();
	}
}

unsigned int World::countBC(Player * player) const // counts bulls and cows, displays them and returns amount of bulls
{
	unsigned int bulls(0), cows(0);
	for (int i = 0; i < getLength(); i++) {
		for (int j = 0; j < getLength(); j++) {
			if ((*currentWord)[i] == player->input[j]) { // check if any letters in the guess are correct with the current word
				i == j ? bulls++ : cows++; // add to the correct variable
			}
		}
	}
	cout << "Bulls: " << bulls << " Cows: " << cows << endl;

	return bulls;
}

void World::forceChoose()
{
	unsigned char a;
	while (true) {
		cout << endl << "Do you wish to play again?(y/n) ";
		cin >> a;
		if (!(a - 'y') || !(a - 'Y'))
			break;
		if (!(a - 'n') || !(a - 'N')) {
			changeGameState();
			return;
		}
	}
}
