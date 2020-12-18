#include <iostream>
#include "Game.h"
#include "World.h"
#include "Player.h"
#include <ctime>



int main()
{
	cout << "Welcome to the game!!!!!!!" << endl;

	World world(true);
	world.begin();

	cout << "Thank you for playing" << endl;


	return 0;
}