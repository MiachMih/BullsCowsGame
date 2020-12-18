#pragma once
#include <iostream>
#include "string"
using namespace std;

class Game {
public:
	Game(bool gameState)
	:gameState(gameState){}

	void changeGameState(); // changes state of the game to its polar oposite (on/off)

	bool isGameOn() const; // returns state of the game (on/off)

	void assingNewWord(); // assign a new random word from the list of words

	int getLength() const; // returns length of the current word

	const string* currentWord;

private:
	static const int size = 10;
	const string listOfWords[size] = { "about","black","computer","numerical","wordsmith","microwave","age","lock","block","duck" }; // dont ever change this list
	bool gameState; // check the state of the game (checks if the player wants to retry the game)
};