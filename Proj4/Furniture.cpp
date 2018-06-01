//File: Furniture.cpp
//Project: CMSC 202 Project 4, Summer 2017
//Author: Gabriel Kilungya
//Date: 07/27/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ implementation of Parent class Furniture.h
//Furniture ends up being an abstract class that holds a majority of data
//for each of the Child classes (Chair & Sofa)
//Do not create a furniture object directly!



#include "Furniture.h"

using namespace std;


//Title: Furniture
//Pre: None
//Post: Abstract class (cannot be called)

Furniture::Furniture(){

  m_width = 0;
  m_height = 0;
  m_depth = 0;
  m_price = 0.0;
  m_material = "";

}

//Title: Furniture (Overloaded Constructor)
//Pre: None
//Post: Used to populate parts of furniture (abstract class)

Furniture::Furniture(int width, int height, int depth, double price, string material){

  m_width = width;
  m_height = height;
  m_depth = depth;
  m_price = price;
  m_material = material;

}


// virtual ~Furniture()
// pre:  -
// post: destroys furniture object

Furniture::~Furniture(){ 
  // does nothing
}

//Title: GetWidth
//Pre: None
//Post: returns m_width

int Furniture::GetWidth(){
  return m_width;
}

//Title: GetHeight
//Pre: None
//Post: returns m_height

int Furniture::GetHeight(){
  return m_height;
}

//Title: GetDepth
//Pre: None
//Post: returns m_depth

int Furniture::GetDepth(){
  return m_depth;
}

//Title: GetMaterial
//Pre: None
//Post: returns m_material

string Furniture::GetMaterial(){
  return m_material;
}

//Title: GetPrice
//Pre: None
//Post:: returns m_price

double Furniture::GetPrice(){
  return m_price;
}

//Title: GetColor (Virtual)
//Pre: None
//Post: returns color (chair only)

string Furniture::GetColor(){
  return "color";
}

//Title: SetWidth(int) in inches
//Pre: Must be passed positive value
//Post: m_width is set (check for positive value else 1)

void Furniture::SetWidth(int width){
  if(width > 0){
    m_width = width;
  }
  else{
    m_width = 1;
  }
}

//Title: SetHeight(int) in inches
//Pre: Must be passed positive value
//Post: m_height is set (check for positive value else 1)

void Furniture::SetHeight(int height){
  if(height > 0){
    m_height = height;
  }
  else{
    m_height = 1;
  }
}

//Title: SetDepth(int) in inches
//Pre: Must be passed positive value
//Post: m_depth is set (check for positive value else 1)

void Furniture::SetDepth(int depth){
  if(depth > 0){
    m_depth = depth;
  }
  else{
    m_depth = 1;
  }
}

//Title: SetMaterial(string)
//Pre: None
//Post: m_material is set (must be either cloth, leather, wood, or metal)

void Furniture::SetMaterial(string material){
  if(material == "cloth"){
    m_material = material;
  }
  else if(material == "leather"){
    m_material = material;
  }
  else if(material == "wood"){
    m_material = material;
  }
  else{
    m_material = material;
  }
}

//Title: SetPrice(double)
//Pre: Must be passed positive value
//Post: m_price is set (check for positive value else 1)

void Furniture::SetPrice(double price){
  if(price > 0.0){
    m_price = price;
  }
  else{
    m_price = 1.0;
  }
}



