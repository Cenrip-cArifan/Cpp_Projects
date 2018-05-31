/*Title: Room.h
Author: Prof. Dixon
Date: 6/13/2017
Description: This is showing how to code stubs in c++.
We haven't written volume yet but we want to see if our code compiles.
We use this to help test our incremental coding.
*/
#ifndef ROOM_H //Header Guard
#define ROOM_H //Header Guard
#include <iostream>
#include <string>
using namespace std;

class Room {
 public:
  //Name: Room (Overloaded Constructor)
  //Precondition: Must have valid input for each part of a room
  //Postcondition: Creates a new room
  Room(int ID, string name, string desc, int north, int east, int south, int west);
  //Name: getName
  //Precondition: Must have valid room
  //Postcondition: Returns room name as string
  string getName();
  //Name: getID
  //Precondition: Must have valid room
  //Postcondition: Returns room id as int
  int getID();
  //Name: getDesc
  //Precondition: Must have valid room
  //Postcondition: Returns room desc as string
  string getDesc();
  //Name: checkDirection
  //Precondition: Must have valid room
  //You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
  //returns the ID of the room in that direction
  //Postcondition: Returns id of room in that direction if the exit exists
  //If there is no exit in that direction, it stops the character from going that dir
  int checkDirection(char direction);
  //Name: setName
  //Precondition: Must pass valid string
  //Postcondition: Updates the room name with valid string
  void setName(string name);
  //Name: setID
  //Precondition: Must pass valid int
  //Postcondition: Updates the room ID with valid int
  void setID(int ID);
  //Name: setDesc
  //Precondition: Must pass valid string
  //Postcondition: Updates the room desc with valid string
  void setDesc(string desc);
  //Name: printRoom
  //Precondition: Room must be complete
  //Postcondition: Outputs the room name, room desc, then possible exits
  void printRoom();
 private:
  int m_ID; //Unique int for room number
  string m_name; //Name of room
  string m_desc; //Description of room
  int m_direction[4]; //Array holding room to north, east, south, west (-1 if no exit)
};
#endif //Header Guard
