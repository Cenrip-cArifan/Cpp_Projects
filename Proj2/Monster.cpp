//File: Monster.cpp
//Project: CMSC 202 Project 2, Summer 2017
//Author: Gabriel Kilungya
//Date: 06/29/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ code that has implementations of Monster.h file



#include "Monster.h"
using namespace std;


//Name: Monsterer (Default constructor)
//Precondition: None
//Postcondition: Creates a default monster with default characteristics

Monster::Monster(){

  m_name = "";
  m_hp = 0;
  m_level = 0;

}

//Name: Monster (Overloaded constructor)
//Precondition: Have values to update constructor
//Postcondition: Creates a new monster with specific characteristics

Monster::Monster(string name, int hp, int level){
  
  m_name = name;
  m_hp = hp;
  m_level = level;

}

//Name: getName
//Precondition: Must already have a monster
//Postcondition: Returns the monster name as a constant

string Monster::getName() const{

  return m_name;

}

//Name: getHp
//Precondition: Must already have a monster
//Postcondition: Returns the monster's hit points as a constant

int Monster::getHp() const{

  return m_hp;

}

//Name: getLevel
//Precondition: Must already have a monster
//Postcondition: Returns the monster's level as a constant

int Monster::getLevel() const{

  return m_level;

}

//Name: setName
//Precondition: Must provide a valid string for the name
//Postcondition: Updates monster's name

void Monster::setName(string name){

  m_name = name;

}

//Name: setHp
//Precondition: Must provide a positive number for hit points
//Postcondition: Updates monster's hit points

void Monster::setHp(int hp){

  m_hp = hp;

}

//Name: setLevel
//Precondition: Must provide positive number for level
//Postcondition: Updates monster's level

void Monster::setLevel(int level){

  m_level = level;

}

