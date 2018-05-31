#include <iostream>
#include <string>
using namespace std;
#ifndef MONSTER_H
#define MONSTER_H

class Monster{
 public:
  //Name: Monsterer (Default constructor)
  //Precondition: None
  //Postcondition: Creates a default monster with default characteristics
  Monster();
  //Name: Monster (Overloaded constructor)
  //Precondition: Have values to update constructor
  //Postcondition: Creates a new monster with specific characteristics
  Monster(string name, int hp, int level);
  //Name: getName
  //Precondition: Must already have a monster
  //Postcondition: Returns the monster name as a constant
  string getName() const;
  //Name: getHp
  //Precondition: Must already have a monster
  //Postcondition: Returns the monster's hit points as a constant
  int getHp() const;
  //Name: getLevel
  //Precondition: Must already have a monster
  //Postcondition: Returns the monster's level as a constant
  int getLevel() const;
  //Name: setName
  //Precondition: Must provide a valid string for the name
  //Postcondition: Updates monster's name
  void setName(string name);
  //Name: setHp
  //Precondition: Must provide a positive number for hit points
  //Postcondition: Updates monster's hit points
  void setHp(int hp);
  //Name: setLevel
  //Precondition: Must provide positive number for level
  //Postcondition: Updates monster's level
  void setLevel(int level);
 private:
  string m_name;
  int m_hp;
  int m_level;
};
#endif
