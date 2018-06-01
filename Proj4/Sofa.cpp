//File: Sofa.cpp
//Project: CMSC 202 Project 4, Summer 2017
//Author: Gabriel Kilungya
//Date: 07/27/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ implementation of the Child class Sofa.h
//Has one unique variable 'm_pillows' which is designed to hold pillow objects


#include "Sofa.h"

using namespace std;

//Title: Sofa
//Pre: None
//Post: Default constructor

Sofa::Sofa(){

  m_numPillows = 0;

}

//Title: Sofa(int, string)
//Pre: None
//Post: Constructor with container of pillows

Sofa::Sofa(int width, int height, int depth, double price, string material, int numPillows) : Furniture(width, height, depth, price, material),
 
											      m_numPillows(numPillows){}

//Title: Sofa Destructor
//Pre: None
//Post: Default Destructor

Sofa::~Sofa(){

  //does nothing since no new object of Sofa & pillows is created

}

//Title: virtual area
//Pre: Sofa (and pillows)
//Post: A sofa is always rectangular and therefore calculated as lengh*width*depth

int Sofa::Area(){

  int area = GetHeight() * GetWidth() * GetDepth();

  return area;

}

//Title: operator<< (Overloaded << operator)
//Pre: Sofa (and pillows)
//Post: Inserts the stream information about the sofa

ostream& Sofa::operator<<(ostream& out){

  //organizes the output stream relative to Sofa objects that have pillows 

  out << "Sofa W" << GetWidth() << " H" << GetHeight() << " D" << GetDepth() 
      << " Pillows:" << m_numPillows << " $" << GetPrice() << endl;

  return out;  

}
