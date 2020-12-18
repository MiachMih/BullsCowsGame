#include "Player.h"
#include "Game.h"

bool Player::isAlive() const
{
	return lives>0;
}

void Player::setDead()
{
	lives = 0;
}

void Player::takeHit()
{
	lives--;
}

bool Player::isIsogram() const
{
	for (int i = 0; i < (input.length() + 1); i++) {
		for (int j = i+1; j < input.length(); j++) {
			if (input[i] == input[j]) {
				return false;
			}
		}
	}
	return true;
}

void Player::getInput()
{
	input = "";
	getline(cin,input);
}

unsigned int Player::checkLives()
{
	return lives;
}

