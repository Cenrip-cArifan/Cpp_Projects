#include <iostream>
#include <string>
using namespace std;
#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
 public:
  //Name: Character (Default constructor)
  //Precondition: None
  //Postcondition: Creates a default character with default characteristics
  Character();
  //Name: Character (Overloaded constructor)
  //Precondition: Have values to update constructor
  //Postcondition: Creates a new character with specific characteristics
  Character(string name, int hp, int level);
  //Name: getName
  //Precondition: Must already have a character
  //Postcondition: Returns the character name as a constant
  string getName() const;
  //Name: getHp
  //Precondition: Must already have a character
  //Postcondition: Returns the character's hit points as a constant
  int getHp() const;
  //Name: getLevel
  //Precondition: Must already have a character
  //Postcondition: Returns the character's level as a constant
  int getLevel() const;
  //Name: setName
  //Precondition: Must provide valid string for name
  //Postcondition: Updates character's name
  void setName(string name);
  //Name: setHp
  //Precondition: Must provide a positive number for hit points
  //Postcondition: Updates character's hit points
  void setHp(int hp);
  //Name: setLevel
  //Precondition: Must provide positive number for level
  //Postcondition: Updates character's level
  void setLevel(int level);
  //Name: levelUp
  //Precondition: Must have character
  //Postcondition: Notifies player of level and increments hp by 1 and level by 1
  void levelUp();
 private:
  string m_name;
  int m_hp;
  int m_level;
};
#endif
