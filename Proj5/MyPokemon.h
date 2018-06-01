/*Title: MyPokemon.h
Author: Prof. Dixon
Date: 7/31/2017
Description: This is the class MyPokemon that holds information of the
non-generic Pokemon that are found & caught
Stores it's number, name, cp (combat points), hp (hit points), and rarity

*/

#ifndef MYPOKEMON_H
#define MYPOKEMON_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class MyPokemon{
 public:
  //Name: MyPokemon (default constructor)
  //Precondition: None
  //Postcondition: Creates a caught Pokemon 
  MyPokemon();
  //Name: MyPokemon (Overloaded constructor)
  //Precondition: None
  //Postcondition: Creates a caught Pokemon
  MyPokemon(int num, string name, int cp, int hp, int rarity);
  //Name: GetCP()
  //Precondition: None
  //Postcondition: Returns the combat points of the Pokemon
  int GetCP();
  //Name: GetHP()
  //Precondition: None
  //Postcondition: Returns the hit points of the Pokemon
  int GetHP();
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
  //Name: SetHP()
  //Precondition: None
  //Postcondition: Sets the hit points of the Pokemon
  void SetHP(int newHP);

  //Name: Train()
  //Precondition: Existing Pokemon
  //Postcondition: Increases the CP of the Pokemon by 10
  void Train();
  //Name: operator<< (overloaded <<)
  //Precondition: Existing Pokemon
  //Postcondition: Prints information about the object
  ostream& operator<< (ostream& os);

 private:
  int m_num; //The Pokemon's number
  string m_name; //The Pokemon's name
  int m_CP; //The Pokemon's combat points
  int m_HP; //The Pokemon's hit points
  int m_rarity; //The Pokemon's rarity (1-5)
};
#endif
