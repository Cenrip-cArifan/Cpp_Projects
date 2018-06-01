//File: Pillow.cpp
//Project: CMSC 202 Project 4, Summer 2017
//Author: Gabriel Kilungya
//Date: 07/27/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ code, implementation of the Pillow.h
//Holds member variable 'm_color' that's either white, black, brown or gray



#include "Pillow.h"

using namespace std;

// Pillow()
// pre:  -
// post: Pillow of a random color (randomly white, black, brown, or gray)

Pillow::Pillow(){

  m_color = "";

}

//  getColor()
// pre:  -
// post: returns own color

string Pillow::GetColor(){

  return m_color;

}
