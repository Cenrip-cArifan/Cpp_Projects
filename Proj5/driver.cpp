/*Title: driver.cpp
Author: Prof. Dixon
Date: 7/31/2017
Description: This is the driver for project 5 - Pokemon Arena
*/
#include "Game.h"

int main (int argc, char *argv[]) {
  if ( argc != 3 ){
    cout << "This requires two files to be loaded (pokedex and myCollection)." << endl;
    cout << "Usage: ./proj5 proj5_pokedex.txt proj5_myCollection.txt" << endl;
    exit(1);
  }
  string pokeDex = argv[1]; //Loads the PokeDex (encyclopedia of Pokemon)
  string myCollection = argv[2]; //Loads user collection
  Game myGame(pokeDex, myCollection); //Creates new game
  return 0;
}
