/*Title: Game.h
Author: Prof. Dixon
Date: 8/01/2017
Description: This is the class Game that manages the user input, catch,
found, battle, train, and save pokemon caught in the game
*/

#ifndef GAME_H
#define GAME_H

#include "MyPokemon.h"
#include "PokeDex.h"
#include "Tstack.h"
const int NUM_ARENA = 5;

class Game{
 public:
  Game(string f_pokemon, string f_myPokemon); //Constructor for Game
  //Name: getPokeDex
  //Precondition: m_pokemonFile must exist
  //Postcondition: populates the pokeDex (pokemon encyclopedia) from a file
  void getPokeDex();
  //Name: getMyPokemon
  //Precondition: m_myPokemonFile  must exist
  //Postcondition: populates the MyPokemon (My caught Pokemon) from a file
  void getMyPokemon();
  //Name: printMyPokemon
  //Precondition: m_myPokemon must be populated
  //Postcondition: prints all pokemon in m_myPokemon
  void printMyPokemon();
  //Name: printMyPokeDex
  //Precondition: m_myPokeDex must be populated
  //Postcondition: prints all pokemon in m_myPokeDex (all 151)
  void printPokeDex();
  // Name: catchPokemon
  // Pre-condition: Requires vectors to be populated
  // Post-condition: Prompts user for rarity (1-5) user would like to capture
  //          Based on rarity (1=65%, 2=45%, 3=25%, 4=10%, 5=1%) tries to find a random
  //          Pokemon based on that rarity.
  //          If a Pokemon is found, calls foundPokemon
  void catchPokemon();
  // Name: foundPokemon ()
  // Pre-condition: After a Pokemon is found, rarity is passed to this function
  // Post-condition: Using rarity, the pokeDex is randomly searched for
  //                 a matching rarity
  //                 After an appropriate Pokemon is found
  //                 Adds new Pokemon to user's m_myPokemon
  void foundPokemon(int rarity );
  // Name: mainMenu
  // Pre-condition: None
  // Post-condition: Calls a variety of functions based on user
  void mainMenu();
  // Name: battlePokemon
  // Pre-condition: Allows user to choose 5 pokemon to send to arena from myPokemon
  //                Adds user chosen pokemon to the user's Tstack
  //                Has the computer randomly add 5 pokemon to send to arena
  //                from pokeDex. Has to convert to myPokemon format
  // Post-condition: Winner continues to next round. Compare CP. Tstack pops.
  //                 Winner is the one who still has Pokemon left at end.
  void battlePokemon();
  // Name: trainPokemon()
  // Pre-condition: User chooses pokemon from myPokemon to train
  // Post-condition: Calls Train member function that increases CP by 10.
  //   Updates pokemon in m_myPokemon
  void trainPokemon();
  // Name: saveMyPokemon
  // Pre-condition: Uses m_myPokemon
  // Post-condition: Saves a file with each Pokemon with number, name, CP, HP, rarity
  void saveMyPokemon();
  // Name: exitPokemon
  // Pre-condition: From main menu, user selects 6
  // Post-condition: Calls saveMyPokemon and exits application
  void exitPokemon();
 private:
  vector<PokeDex> m_pokeDex; //Vector of all possible Pokemon
  vector<MyPokemon> m_myPokemon; //Vector of all user caught Pokemon
  string m_pokemonFile; //File name for the pokeDex
  string m_myPokemonFile; //File name for my Pokemon collection
};
#endif
