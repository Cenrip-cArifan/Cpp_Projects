//File: proj1.cpp
//Project: CMSC 202 Project 1, Summer 2017
//Author: Gabriel Kilungya
//Date: 06/15/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ code that develops a life expectancy calulator
//using real data from the Social Security Administration
//The data will be loaded to a 2D array and data should be stored with double
//precision. We want to calculate the likelihood an individual would live either
//past their life expectancy, live up to max age 120 or die before expected life
//expectancy using random number generator to compare random number with
//the death probability


//imported C libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;


//Constants, constants to store dimension of 2D array & to store data .txt file
const int ROWS = 120;
const int COLS = 7;
const char DATA[16] = "proj1_data.txt";


// Main Menu: Function prototype
int mainMenu(int choice);

//loadTable: Function prototype
void loadTable(double[ROWS][COLS]);

//printTable: Function prototype
void printTable(double[ROWS][COLS]);

//simPer: Function prototype
void simPer(char gender, int age, double a[ROWS][COLS]);

int main(){

  //random number requires a "seed"
  srand(time(NULL));

  //variable of Data type: int, double, char
  //variables of correct Data type of function passed in main
  int userChoice;
  int age;
  double lifeData[ROWS][COLS];
  char gender;
 

  //Initialize userChoice to mainMenu() function passing userChoice as a value
  userChoice = mainMenu(userChoice);

  //call loadTable() function and pass array of Double to load data 
  //file into array
  loadTable(lifeData);

  //While loop: uses while loop to check if condition is true or false
  //if condition is true keep running while loop, otherwise exit loop

  //Switch statement inside of loop has 2 cases.
  //Case 1: calls printTable() function and displays formatted data file
  //Case 2: calls simPer() function and passes 3 arguments: gender, age, array
  //        Simulates individual and sees how long they might live based on
  //        Random number generated for each year they might live
  while(userChoice != 3){
    switch(userChoice){
    case 1:
      printTable(lifeData);
      break;
    case 2:
      simPer(gender, age, lifeData);
      break;
    }
    userChoice = mainMenu(userChoice);
  }
  return 0;
}


//mainMenu() function: Takes in an integer argument
//displays: welcomes user to the calculator
//displays 3 choices a user makes and validates the choice between 1 & 3
//Returns choice user makes

int mainMenu(int choice){
  
  cout << "Welcome to the Life Expectancy Calculator" << endl
       << "What would you like to do?" << endl
       << "1. Print Actuarial Table" << endl
       << "2. Simulate Person" << endl
       << "3. Exit" << endl;

  cin >> choice;

  while(choice < 1 || choice > 3){

    cout << "What would you like to do?" << endl
	 << "1. Print Actuarial Table" << endl
	 << "2. Simulate Person" << endl
	 << "3. Exit" << endl;

    cin >> choice;

  }
  return choice;

}


//loadTable() void function takes in an 2D array as parameter
//Opens and loads a file into a 2D array using nested for loops
//to account for both the rows & cols of data file
//Closes the file for no memory leaks or data corruption

void loadTable(double aTable[ROWS][COLS]){

  ifstream inputFile;
  inputFile.open(DATA);

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      inputFile >> aTable[i][j];
    }
  }
  inputFile.close();
}

//printTable() void function takes in an 2D array as parameter
//Nested for loops used to print rows & cols, so no data is lost
// and data is outputted in correct format


void printTable(double aTable[ROWS][COLS]){

  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      cout << left << setw(11) << setfill(' ') <<  aTable[i][j];
    }
    cout << endl;
  }
  
}

//simPer() void function takes in 3 parameters: gender, age and an array
//Asks user to enter gender of individual (M or F)
//Asks user to enter age of individual from (0 to 119)
//Checks for validity of age

void simPer(char gender, int currAge, double aTable[ROWS][COLS]){

  cout << "Enter sex, 'M' or 'F'." << endl;
  cin >> gender;

  cout << "Enter age." << endl;
  cin >> currAge;

  while(currAge < 0 || currAge > 119){
    cout << "Enter age." << endl;
    cin >> currAge;
  }

  //bool checks to see if person is dead or alive
  //stops when person is dead
  bool isDead = false;

  //current age enter by user of the individual stored in variable i
  int i = currAge;
  
  //calculates expectancy of male & female individual of ages 0 to 119
  //given from current age plus expectancy of either gender given from data file
  //stored in as double for precision

  double maleLifeExp = aTable[i][0] + aTable[i][3];
  double femLifeExp = aTable[i][0] + aTable[i][6];

  //If statemnts: checks to see if gender entered by user is either male or 
  //female when gender is known, displays age and life expectancy of individual

  if(gender == 'M'){
    cout << "Based on your gender, " << gender << ", and your age, "
         << i << ", your life expectancy is " << maleLifeExp << endl;
  }
  else{
    cout << "Based on your gender, " << gender << ", and your age, "
         << i << ", your life expectancy is " << femLifeExp<< endl;
  }

  //While loop: checks while person is not dead and age is not out of range
  //randProb is a random number generated between 0 and RAND_MAX stored as 
  //a double so number generated doesn't round off to 0 if it is not 1
  //initialize male & female death probability to a double for precision in
  //comparison to random number generated

  while(!isDead && i < ROWS){
    
    double randProb = ((double) rand() / (RAND_MAX));

    double maleDeathProb = aTable[i][1];
    double femDeathProb = aTable[i][4];

    //nested If statements: first If, checks for gender of individual
    //2nd If, checks to see if age i obtained is less than maleLifeExp
    //calculated above
    //display when expected individual lives up to
    //display if individual exceeds life span or does not exceed it

    //counter i++ account for each future year after current age entered by
    //user till death then counter stops
    
    if(gender == 'M'){
      if(randProb < maleDeathProb){
        cout << "You lived to age " << aTable[i][0] << endl;
	if(i < maleLifeExp){
	  cout << "You did not exceed your expected life span." << endl;
	}
	else{
	  cout << "You exceeded your expected life span." << endl;
	}
        isDead = true;
      }
    }
    else{
      if(randProb < femDeathProb){
        cout << "You lived to age " << aTable[i][0] << endl;
	if(i < femLifeExp){
          cout << "You did not exceed your expected life span." << endl;
        }
        else{
          cout << "You exceeded your expected life span." << endl;
        }
        isDead = true;
      }
    }
    i++;
  }
  
}
