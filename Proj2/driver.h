#include "Room.h"
#include "Character.h"
#include "Monster.h"

#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
using namespace std;

//Name: loadMap
//Precondition: Passes the empty map vector by reference
//Postcondition: Adds rooms to the vector from a file
void loadMap(vector<Room> &map1, string mapName);
//Name: action
//Precondition: Passes the populated map, the current room, and the character
//Postcondition: Repeated asks the user what to do. Manages menu and game.
void action(vector<Room> &map1, int &curRoom, Character &newChar);
//Name: move
//Precondition: Passes the populated map and the current room
//Postcondition: Validates move and calls check direction. Then moves and calls
//displays the map
//Calculates 50% chance a monster will appear in the destination
void move(vector<Room> &map1, int &curRoom);
//Name: attack
//Precondition: Passes the character and the monster
//Postcondition: Automatically defeats the monster and character gains level
void attack(Character& newChar, Monster &newMonster);
//Name: stats
//Precondition: Must have character
//Postcondition: Displays character name, hp, and level
void stats(const Character& newChar);
//Name: newCharacter
//Precondition: Asks user for name of character
//Postcondition: Updates the new character with provided name and hp=1 and level=1
void newCharacter(Character & newChar);
//Name: loadMonster
//Precondition: Called from move
//If a monster is present, 50% level 1 skeleton, 30% level 3 giant, 20% level 10 lich
//Postcondition: Updates the new character with provided name and hp=1 and level=1
void loadMonster(int iMonster, Monster &newMonster);
