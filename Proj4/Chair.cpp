//File: Chair.cpp
//Project: CMSC 202 Project 4, Summer 2017
//Author: Gabriel Kilungya
//Date: 07/27/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++, implementation of Child class Chair.h
//Has one unique member variable 'm_color' that's needed to be able to search on 



#include "Chair.h"

using namespace std;

//Title: Chair
//Pre: None
//Post: Default constructor

Chair::Chair(){

  m_color = "";

}

//Title: Chair(string)
//Pre: None
//Post: Constructor looking for chair color (unique to chairs)

Chair::Chair(int width, int height, int depth, double price, string material, string color) : Furniture(width, height, depth, price, material), m_color(color){}


//Title: GetColor
//Pre: None
//Post: Returns color

string Chair::GetColor(){
   return m_color;
}

//Title: SetColor
//Pre: None
//Post: Sets color

void Chair::SetColor(string color){

  m_color = color;

}

//Title: Area
//Pre: None
//Post: Area for the chair is calculated as width*height*depth*.90

int Chair::Area(){

  int area = GetWidth() * GetHeight() * GetDepth() * .90;
  
  return area;

}

//Title: operator << (Overloaded << operator)
//Pre: None
//Post: Inserts into the stream the chair's information

ostream& Chair::operator<<(ostream& out){

  //organizes output stream relative to Chair objects that have differing colors

  out << "Chair W" << GetWidth() << " H" << GetHeight() << " D" << GetDepth() 
      << " " << m_color << " $" << GetPrice() << endl;

  return out;

}


