/*Title: PokeDex.h
Author: Prof. Dixon
Date: 7/31/2017
Description: This is the class PokeDex that holds information of each generic
Pokemon: it's number, name, cp Min, cp Max, and rarity
*/

#ifndef POKEDEX_H
#define POKEDEX_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class PokeDex{
 public:
  //Name: MyPokemon (default constructor)
  //Precondition: None
  //Postcondition: Generic Pokemon (not caught yet) constructor
  //Used as the guide for how powerful each Pokemon is
  PokeDex();
  //Name: MyPokemon (overloaded constructor)
  //Precondition: None
  //Postcondition: Generic Pokemon (not caught yet) constructor
  PokeDex(int num, string name, int cpMin, int cpMax, int rarity);
  //Name: GetCPMin()
  //Precondition: None
  //Postcondition: Returns the minimum combat points of the Pokemon
  int GetCPMin();
  //Name: GetCPMax()
  //Precondition: None
  //Postcondition: Returns the maximum combat points of the Pokemon
  int GetCPMax();
  //Name: GetRarity()
  //Precondition: None
  //Postcondition: Returns the rarity of the Pokemon
  int GetRarity();
  //Name: GetName()
  //Precondition: None
  //Postcondition: Returns the name of the Pokemon
  string GetName();
  //Name: GetNum()
  //Precondition: None
  //Postcondition: Returns the number of the Pokemon
  int GetNum();

  //Name: SetRarity()
  //Precondition: None
  //Postcondition: Sets the rarity of the Pokemon
  void SetRarity(int newRarity);
  //Name: SetName()
  //Precondition: None
  //Postcondition: Sets the name of the Pokemon
  void SetName(string newName);
  //Name: SetCP()
  //Precondition: None
  //Postcondition: Sets the combat points of the Pokemon
  void SetCP(int newCP);

  //Name: operator<< (overloaded <<)
  //Precondition: Existing Pokemon
  //Postcondition: Prints information about the PokeDex object
  ostream& operator<< (ostream& os);
 private:
  int m_num; //Number of the Pokemon
  string m_name; //Name of the Pokemon
  int m_minCP; //Minimum CP of that Pokemon
  int m_maxCP; //Maximum CP of that Pokemon
  int m_rarity; //Rarity of the Pokemon
};
#endif
