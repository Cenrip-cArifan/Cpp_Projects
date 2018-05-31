//File: Room.cpp
//Project: CMSC 202 Project 2, Summer 2017
//Author: Gabriel Kilungya
//Date: 06/29/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ code, implementation of Room.h file



#include "Room.h"
using namespace std;


//Name: Room (Overloaded Constructor)
//Precondition: Must have valid input for each part of a room
//Postcondition: Creates a new room

Room::Room(int ID, string name, string desc, int north, int east, int south, int west){


  m_ID = ID;
  m_name = name;
  m_desc = desc;
  m_direction[0] = north;
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;

}


//Name: getName
//Precondition: Must have valid room
//Postcondition: Returns room name as string

string Room::getName(){

  return m_name;

}


//Name: getID
//Precondition: Must have valid room
//Postcondition: Returns room id as int

int Room::getID(){

  return m_ID;

}

//Name: getDesc
//Precondition: Must have valid room
//Postcondition: Returns room desc as string

string Room::getDesc(){

  return m_desc;

}

//Name: checkDirection
//Precondition: Must have valid room
//You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
//returns the ID of the room in that direction
//Postcondition: Returns id of room in that direction if the exit exists
//If there is no exit in that direction, it stops the character from going that 

int Room::checkDirection(char direction){

  switch(direction){
  case 'N':
  case 'n':
    return m_direction[0];
    break;
  case 'E':
  case 'e':
    return m_direction[1];
    break;
  case 'S':
  case 's':
    return m_direction[2];
    break;
  case 'W':
  case 'w':
    return m_direction[3];
    break;
  default:
    return -1;
    break;
  }
  
}

//Name: setName
//Precondition: Must pass valid string
//Postcondition: Updates the room name with valid string

void Room::setName(string name){

  m_name = name;

}

//Name: setID
//Precondition: Must pass valid int
//Postcondition: Updates the room ID with valid int

void Room::setID(int ID){

  m_ID = ID;

}

//Name: setDesc
//Precondition: Must pass valid string
//Postcondition: Updates the room desc with valid string

void Room::setDesc(string desc){

  m_desc = desc;

}

//Name: printRoom
//Precondition: Room must be complete
//Postcondition: Outputs the room name, room desc, then possible exits

void Room::printRoom(){

  cout << m_name << endl
       << m_desc << endl;

  cout << "Possible Exits: ";

  int c = 0;

  //For Loop: for every direction in the room (N,E,S,W)
  //If: there's an exit, display 1st Character of compass directions
  //If: there's no exit (-1) display no possible exits

  for(int i = 0; i < 4; i++){
    if(m_direction[i] != -1){
      if(i == 0){
	cout << "N";
        ++c;
      }
      else if(i == 1){
	cout << "E";
        ++c;
      }
      else if(i == 2){
	cout << "S";
        ++c;
      }
      else if(i == 3){
	cout << "W";
        ++c;
      }
    }
  }
  if(!c){
    cout<<"None"<<endl;
  }
  cout << endl;
}
