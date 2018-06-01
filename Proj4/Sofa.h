//Title: Sofa.h
//Author: Jeremy Dixon
//Date: 7/12/17
//Description: Describes the child class Sofa (parent Furniture)
//FYI: A sofa is a cushioned piece of furniture you sit on (also a couch)

#ifndef SOFA_H
#define SOFA_H
#include "Furniture.h"
#include "Pillow.h"

class Sofa: public Furniture {
public:
  //Title: Sofa
  //Pre: None
  //Post: Default constructor
  Sofa();

  //Title: Sofa(int, string)
  //Pre: None
  //Post: Constructor with container of pillows
  Sofa(int width, int height, int depth, double price, string material, int numPillows);

  //Title: Sofa Destructor
  //Pre: None
  //Post: Default Destructor
  ~Sofa();

  //Title: virtual area
  //Pre: Sofa (and pillows)
  //Post: A sofa is always rectangular and therefore calculated as lengh*width*depth
  virtual int Area();
  
  //Title: operator<< (Overloaded << operator)
  //Pre: Sofa (and pillows)
  //Post: Inserts the stream information about the sofa
  virtual ostream& operator<<(ostream&);
  
 protected:
  int m_numPillows;
  vector <Pillow*> m_pillows;
};

#endif 
