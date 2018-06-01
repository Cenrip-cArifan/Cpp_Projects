//Title: Furniture.h
//Author: Jeremy Dixon
//Date: 7/12/2017
//Description: Describes the parent class Furniture

#ifndef FURNITURE_H
#define FURNITURE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Furniture {
public:
  //Title: Furniture
  //Pre: None
  //Post: Abstract class (cannot be called)
  Furniture();

  //Title: Furniture (Overloaded Constructor)
  //Pre: None
  //Post: Used to populate parts of furniture (abstract class)
  Furniture(int width, int height, int depth, double price, string material);
  
  // virtual ~Furniture()
  // pre:  -
  // post: destroys furniture object
  virtual ~Furniture();
  
  //Accessors
  
  //Title: GetWidth
  //Pre: None
  //Post: returns m_width
  int GetWidth();
  
  //Title: GetHeight
  //Pre: None
  //Post: returns m_height
  int GetHeight();

  //Title: GetDepth
  //Pre: None
  //Post: returns m_depth
  int GetDepth();

  //Title: GetMaterial
  //Pre: None
  //Post: returns m_material
  string GetMaterial();

  //Title: GetPrice
  //Pre: None
  //Post:: returns m_price
  double GetPrice();

  //Title: GetColor (Virtual)
  //Pre: None
  //Post: returns color (chair only)
  virtual string GetColor();

  //Mutators
  
  //Title: SetWidth(int) in inches
  //Pre: Must be passed positive value
  //Post: m_width is set (check for positive value else 1)
  void SetWidth(int width);
  
  //Title: SetHeight(int) in inches
  //Pre: Must be passed positive value
  //Post: m_height is set (check for positive value else 1)
  void SetHeight(int height);

  //Title: SetDepth(int) in inches
  //Pre: Must be passed positive value
  //Post: m_depth is set (check for positive value else 1)
  void SetDepth(int depth);

  //Title: SetMaterial(string)
  //Pre: None
  //Post: m_material is set (must be either cloth, leather, wood, or metal)
  void SetMaterial(string material);

  //Title: SetPrice(double)
  //Pre: Must be passed positive value
  //Post: m_price is set (check for positive value else 1)
  void SetPrice(double price);  
  
  //Title: Area
  //Pre: Purely Virtual
  //Post: Purely Virtual
  virtual int Area() = 0;
  
  //Title: Area
  //Pre: Purely Virtual
  //Post: Purely Virtual
  virtual ostream& operator<<(ostream& os) = 0;
  
 private:
  int m_width; //Width of Furniture in Inches
  int m_height; //Height of Furniture in Inches
  int m_depth; //Depth of Furniture in Inches
  double m_price; //Price of Furniture
  string m_material; //Material (cloth, wood, leather, or metal)
};


#endif
