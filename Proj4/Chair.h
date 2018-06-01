//Title: Chair.h
//Author: Jeremy Dixon
//Date: 7/13/2017
//Description: Describes the child class Chair (Parent Furniture.h)

#ifndef CHAIR_H
#define CHAIR_H
#include "Furniture.h"
#include "Pillow.h"

class Chair: public Furniture {
public:
  //Title: Chair
  //Pre: None
  //Post: Default constructor
  Chair();

  //Title: Chair(string)
  //Pre: None
  //Post: Constructor looking for chair color (unique to chairs)
  Chair(int width, int height, int depth, double price, string material, string color);

  //Title: GetColor
  //Pre: None
  //Post: Returns color
  string GetColor();

  //Title: SetColor
  //Pre: None
  //Post: Sets color
  void SetColor(string color);

  //Title: Area
  //Pre: None
  //Post: Area for the chair is calculated as width*height*depth*.90  
  virtual int Area();

  //Title: operator << (Overloaded << operator)
  //Pre: None
  //Post: Inserts into the stream the chair's information
  virtual ostream& operator<<(ostream&);

private:
    string m_color;
};

#endif 
