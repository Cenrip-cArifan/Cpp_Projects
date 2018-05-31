//File: Character.cpp
//Project: CMSC 202 Project 1, Summer 2017
//Author: Gabriel Kilungya
//Date: 06/15/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ code that has implementations of Character.h file



#include "Character.h"
using namespace std;



//Name: Character (Default constructor)
//Precondition: None
//Postcondition: Creates a default character with default characteristics

Character::Character(){

  m_name = "";
  m_hp = 0;
  m_level = 0;

}


//Name: Character (Overloaded constructor)
//Precondition: Have values to update constructor
//Postcondition: Creates a new character with specific characteristics

Character::Character(string name, int hp, int level){

  m_name = name;
  m_hp = hp;
  m_level = level;

}

//Name: getName
//Precondition: Must already have a character
//Postcondition: Returns the character name as a constant

string Character::getName() const{

  return m_name;

}

//Name: getHp
//Precondition: Must already have a character
//Postcondition: Returns the character's hit points as a constant

int Character::getHp() const{

  return m_hp;

}

//Name: getLevel
//Precondition: Must already have a character
//Postcondition: Returns the character's level as a constant

int Character::getLevel() const{

  return m_level;

}

//Name: setName
//Precondition: Must provide valid string for name
//Postcondition: Updates character's name

void Character::setName(string name){

  m_name = name;

}

//Name: setHp
//Precondition: Must provide a positive number for hit points
//Postcondition: Updates character's hit points

void Character::setHp(int hp){

  m_hp = hp;

}


//Name: setLevel
//Precondition: Must provide positive number for level
//Postcondition: Updates character's level

void Character::setLevel(int level){

  m_level = level;

}

//Name: levelUp
//Precondition: Must have character
//Postcondition: Notifies player of level and increments hp by 1 and level by 1

void Character::levelUp(){

  m_hp += 1;
  m_level += 1;
  
}

