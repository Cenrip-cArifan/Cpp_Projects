//File: PokeDex.cpp
//Project: CMSC 202 Project 5, Summer 2017
//Author: Gabriel Kilungya
//Date: 08/14/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ implementation of class PokeDex.h
//This is list of all possible Pokemon. It has min & max CP(combat points).
//Currently has 151 Pokemon in the list.
//Uses overloading operator<< ostream& to display info about each object in object  

#include "PokeDex.h"

using namespace std;


//Name: PokeDex (default constructor)
//Precondition: None
//Postcondition: Generic Pokemon (not caught yet) constructor
//Used as the guide for how powerful each Pokemon is

PokeDex::PokeDex(){

  m_num = 0;
  m_name = "";
  m_minCP = 0;
  m_maxCP = 0;
  m_rarity = 0;

}


//Name: PokeDex (overloaded constructor)
//Precondition: None
//Postcondition: Generic Pokemon (not caught yet) constructor

PokeDex::PokeDex(int num, string name, int cpMin, int cpMax, int rarity){

  m_num = num;
  m_name = name;
  m_minCP = cpMin;
  m_maxCP = cpMax;
  m_rarity = rarity;

}

//Name: GetCPMin()
//Precondition: None
//Postcondition: Returns the minimum combat points of the Pokemon

int PokeDex::GetCPMin(){

  return m_minCP;

}

//Name: GetCPMax()
//Precondition: None
//Postcondition: Returns the maximum combat points of the Pokemon

int PokeDex::GetCPMax(){

  return m_maxCP;

}

//Name: GetRarity()
//Precondition: None
//Postcondition: Returns the rarity of the Pokemon

int PokeDex::GetRarity(){

  return m_rarity;

}

//Name: GetName()
//Precondition: None
//Postcondition: Returns the name of the Pokemon

string PokeDex::GetName(){

  return m_name;

}

//Name: GetNum()
//Precondition: None
//Postcondition: Returns the number of the Pokemon

int PokeDex::GetNum(){

  return m_num;

}

//Name: SetRarity()
//Precondition: None
//Postcondition: Sets the rarity of the Pokemon

void PokeDex::SetRarity(int newRarity){

  m_rarity = newRarity;

}

//Name: SetName()
//Precondition: None
//Postcondition: Sets the name of the Pokemon

void PokeDex::SetName(string newName){

  m_name = newName;

}

//Name: SetCP()
//Precondition: None
//Postcondition: Sets the combat points of the Pokemon

void PokeDex::SetCP(int newCP){

  m_minCP = m_minCP + newCP;
  m_maxCP = m_maxCP + newCP;

}

//Name: operator<< (overloaded <<)
//Precondition: Existing Pokemon
//Postcondition: Prints information about the PokeDex object

ostream& PokeDex::operator<<(ostream& os){

  os << " " << setw(6) << left << m_num << m_name << endl;

  return os;
}
