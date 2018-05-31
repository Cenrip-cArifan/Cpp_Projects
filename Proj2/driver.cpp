//File: driver.cpp
//Project: CMSC 202 Project 2, Summer 2017
//Author: Gabriel Kilungya
//Date: 06/29/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ code that has implementations of dirver.h file
//This is where the Character, Room, Monster classes are implemented and the
//where the game is compiled & executed



#include "driver.h"
 
int main (int argc, char *argv[]) {
  if ( argc != 2 ){
    cout << endl << "This requires a room file to be loaded." << endl;
    cout << "Usage: ./proj2 map2_data.txt" << endl;
    exit(1);
  }
  srand (time(NULL));
  vector<Room> map1;
  string mapName = argv[1];
  Character newChar;
  newCharacter(newChar);
  int curRoom = 0;
  loadMap(map1, mapName);
  map1[0].printRoom();  
  action(map1, curRoom, newChar);
  return 0;
}


//Name: loadMap
//Precondition: Passes the empty map vector by reference
//Postcondition: Adds rooms to the vector from a file
 
void loadMap(vector<Room> &map1, string mapName){
  ifstream fin(mapName.c_str());
  string id;
  string name;
  string desc;
  string north, south, east, west;
  char deli = '|';
  while(getline(fin, id, deli)){
    getline(fin, name, deli);
    getline(fin, desc, deli);
    getline(fin, north, deli);
    getline(fin, east, deli);
    getline(fin, south, deli);
    getline(fin, west);
    map1.push_back(Room(atoi(id.c_str()),name, desc, atoi(north.c_str()),atoi(east.c_str()),atoi(south.c_str()),atoi(west.c_str())));
  }
  fin.close();
}
 
//**********************Implement the rest of your functions below here**********


//Name: action
//Precondition: Passes the populated map, the current room, and the character
//Postcondition: Repeated asks the user what to do. Manages menu and game. 
 
void action(vector<Room> &map1, int &curRoom, Character &newChar){

  //create a new Monster object
  Monster newMonster;
  newMonster = Monster();
  int choice = 0;
  int i = 0;

  //initialize curRoom, to the room you start with in the beginning of game 
  int prevRoom = curRoom;

  //while user doesn't quit the game, keep playing the game until user 
  //selects 5, then game quits, display a message
  while(choice != 5){
    
    //creat new Room object temp and get ID of curRoom
    Room temp = map1[curRoom];

    //If: not in the first room & next room isn't the first room
    //    get location of room, random monster spawns, could be a skeleton, lich or
    //    giant. Then dusplay what type of monster spawns in the room.

    if(i!=0 && prevRoom!=curRoom)
    {
        temp.printRoom();
        int iMonster = rand()%100+1;
        loadMonster(iMonster,newMonster); 
        cout<<"There is a "<<newMonster.getName()<<" here."<<endl;
    }

    //If: in the first room, then no monster spawns, when you look around in the room
    if(i==0)
    {
        ++i; 
    }
 
    cout << "What would you like to do?" << endl
	 << "1. Look" << endl
	 << "2. Move" << endl
	 << "3. Attack Monster" << endl
	 << "4. Check Stats" << endl
	 << "5. Quit" << endl;
 
    cin >> choice;
 
    //switch statement: Selects 2: prevRoom is current room. calls move() function
    //                                       when valid move is made, character moves to next room
    //                  Selects 3: If there's a monster is in the room, user can attack
    //                                       monster by callin attack() function. Beat monster level up
    //                  Selects 4: Character sees his/her stats updated level & hp (if any)
    //                  Selects 5: Quit game. Display message

    switch(choice){
    case 1:
      break;
    case 2:      
      prevRoom = curRoom;
      move(map1,curRoom);
      break;
    case 3: 
      attack(newChar,newMonster);
      break;
    case 4:
      stats(newChar);
      break;
    case 5:
      cout << "Good bye!" << endl;
      break;
    }   
  }
}

//Name: move
//Precondition: Passes the populated map and the current room
//Postcondition: Validates move and calls check direction. Then moves and calls
 
void move(vector<Room> &map1, int &curRoom){
  char dir;
  Room temp = map1[curRoom];

  //while current room has no exits, keep asking user to enter valid exists
  do{
    cout<<"Which direction? (N E S W)"<<endl;
    cin>>dir;
    cin.ignore(100,'\n');
  }while((curRoom = temp.checkDirection(dir))==-1);
}

//Name: attack
//Precondition: Passes the character and the monster
//Postcondition: Automatically defeats the monster and character gains level 
 
void attack(Character& newChar, Monster &newMonster)
{
 
  //If: monster exists, then after attacking monster
  //    display two messages. Then call Character levelUp() & level up 
  //    Characters stats(hp & level)
  
  if(newMonster.getName()!="")
  {
    cout<<"You have defeated the "<<newMonster.getName()<<"."<<endl;
    cout<<"You went up a level."<<endl;
    newChar.levelUp();
 
  }
}


//Name: stats
//Precondition: Must have character
//Postcondition: Displays character name, hp, and level
 
void stats(const Character& newChar){
 
  cout << "Name: " << newChar.getName() << endl
       << "HP: " <<  newChar.getHp() << endl
       << "Level: " << newChar.getLevel() << endl;
 
}

//Name: newCharacter
//Precondition: Asks user for name of character
//Postcondition: Updates the new character with provided name and hp=1 and level=1
 
void newCharacter(Character & newChar){
 
  string name;
 
  cout << "What would you like your name to be?" << endl;
  cin >> name;
  cout << endl;
 
  newChar = Character(name, 1, 1);
 
}

//Name: loadMonster
//Precondition: Called from move
//If a monster is present, 50% level 1 skeleton, 30% level 3 giant, 20% level 10 lich
//Postcondition: Updates the new character with provided name and hp=1 and level=1
 
void loadMonster(int iMonster, Monster &newMonster)
{
  if(iMonster>=50)
  {
    newMonster.setName("Skeleton");
  }
  else if(iMonster>=30)
  {
    newMonster.setName("Giant");
  }
  else 
  {
    newMonster.setName("Lich");
  }
}
