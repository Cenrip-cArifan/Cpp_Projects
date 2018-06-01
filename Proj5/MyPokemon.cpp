//File: MyPokemon.cpp
//Project: CMSC 202 Project 5, Summer 2017
//Author: Gabriel Kilungya
//Date: 08/14/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ implementation of class MyPokemon.h
//This is user's personal collection of Pokemon that they have caught & trained
//PokeDex is converted from generic Pokemon definition into caught version by
//randomly selecting a CP(combat points) between CPMin & CPMax from PokeDex
//HP(Hit points) are just 10% of calcultaed CP. Rarity is number between 1-5
//Uses overloading operator ostream& to display info about each object in the object


#include "MyPokemon.h"

using namespace std;


//Name: MyPokemon (default constructor)
//Precondition: None
//Postcondition: Creates a caught Pokemon

MyPokemon::MyPokemon(){
  
  m_num = 0;
  m_name = "";
  m_CP = 0;
  m_HP = 0;
  m_rarity = 0;
  
}

//Name: MyPokemon (Overloaded constructor)
//Precondition: None
//Postcondition: Creates a caught Pokemon

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity){

  m_num = num;
  m_name = name;
  m_CP = cp;
  m_HP = hp;
  m_rarity = rarity;

}

//Name: GetCP()
//Precondition: None
//Postcondition: Returns the combat points of the Pokemon

int MyPokemon::GetCP(){

  return m_CP;

}

//Name: GetHP()
//Precondition: None
//Postcondition: Returns the hit points of the Pokemon

int MyPokemon::GetHP(){

  return m_HP;

}

//Name: GetRarity()
//Precondition: None
//Postcondition: Returns the rarity of the Pokemon

int MyPokemon::GetRarity(){

  return m_rarity;

}

//Name: GetName()
//Precondition: None
//Postcondition: Returns the name of the Pokemon

string MyPokemon::GetName(){

  return m_name;

}

//Name: GetNum()
//Precondition: None
//Postcondition: Returns the number of the Pokemon

int MyPokemon::GetNum(){

  return m_num;

}

//Name: SetRarity()
//Precondition: None
//Postcondition: Sets the rarity of the Pokemon

void MyPokemon::SetRarity(int newRarity){

  m_rarity = newRarity;

}

//Name: SetName()
//Precondition: None
//Postcondition: Sets the name of the Pokemon

void MyPokemon::SetName(string newName){

  m_name = newName;

}

//Name: SetCP()
//Precondition: None
//Postcondition: Sets the combat points of the Pokemon

void MyPokemon::SetCP(int newCP){

  m_CP = newCP;

}

//Name: SetHP()
//Precondition: None
//Postcondition: Sets the hit points of the Pokemon

void MyPokemon::SetHP(int newHP){

  m_HP = newHP;

}

//Name: Train()
//Precondition: Existing Pokemon
//Postcondition: Increases the CP of the Pokemon by 10

void MyPokemon::Train(){

  m_CP = m_CP + 10;

}

//Name: operator<< (overloaded <<)
//Precondition: Existing Pokemon
//Postcondition: Prints information about the object

ostream& MyPokemon::operator<<(ostream& os){

  os << "  " << setw(8) << left << m_num << setw(12) << left << m_name 
     << setw(8) << left << m_CP << setw(8) << left << m_HP
     << m_rarity << endl;

  return os;
}
