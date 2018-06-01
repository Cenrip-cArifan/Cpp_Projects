//File: MyPokemon.cpp
//Project: CMSC 202 Project 5, Summer 2017
//Author: Gabriel Kilungya
//Date: 08/14/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ header & implementation of class Tstack
//Templated stack data structure that uses an underlying dynamic array. 
//This structure that will hold all of the Pokemon used in the Arena


#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tstack {
public:
  //Name: Tstack - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a stack using dynamic array
  Tstack(); //Default Constructor
  //Name: Copy Constructor (Required)
  //Precondition: Existing Tstack
  //Postcondition: Copies an existing Tstack
  Tstack( const Tstack<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tstack
  //Postcondition: Destructs existing Tstack
  ~Tstack(); //Destructor
  //Name: push
  //Precondition: Existing Tstack
  //Postcondition: Adds item to top of stack
  void push(T data); //Adds item to stack (to top)
  //Name: pop
  //Precondition: Existing Tstack
  //Postcondition: Removes item from top of stack
  T pop(); //Removes item from stack (from top)
  //Name: peek
  //Precondition: Existing Tstack
  //Postcondition: Retrieve top of stack (does not remove it)
  T peek();    // Retrieve top (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tstack
  //Postcondition: Returns 1 if stack is empty else 0
  bool isEmpty(); //Returns 1 if stack is empty else 0
  //Name: isFull
  //Precondition: Existing Tstack
  //Postcondition: Returns 1 if stack is full else 0
  int isFull(); //Returns 1 if stack is full else 0
  //Name: Overloaded assignment operator (Required)
  //Precondition: Existing Tstack
  //Postcondition: Sets one Tstack to same as a second Tstack using =
  Tstack<T,N>& operator=( Tstack<T,N> y); //Overloaded assignment operator for stack
  //Name: getSize()
  //Precondition: Existing Tstack
  //Postcondition: Returns m_size of the stack
  int getSize();
  //Name: printStack()
  //Precondition: Existing Tstack
  //Postcondition: Lists each item in the stack (used for debugging)
  void printStack();
private:
  T* m_data; //Data of the stack (Must be dynamically allocated array)
  int m_size; //Size of stack
};

//**** Add class definition below ****

//think of m_size as NUM of pokemon currently owned
//think of N as NUM of pokemon i can have

template <class T, int N>
Tstack<T,N>::Tstack(){


  m_size = NULL; 
  m_data = new T[N];
  
}

template <class T, int N>
Tstack<T,N>::Tstack(const Tstack<T,N>& x){

  m_size = x.m_size;
  m_data = new T[N];
  for(int i = 0; i < N; i++){    
    m_data[i] = x.m_data[i];
  }
}

//TODO
template <class T, int N>
Tstack<T,N>::~Tstack(){

  delete [] m_data;
  m_data = NULL;

}

template <class T, int N>
void Tstack<T,N>::push(T data){
  if(!Tstack<T,N>::isFull()){
    m_data[m_size] = data;
    m_size += 1;
  }
}

template <class T, int N>
T Tstack<T,N>::pop(){

  T item;
  if(!Tstack<T,N>::isEmpty()){
    item = m_data[m_size-1];
    m_size -= 1;
  }
  else{
    cout << "Stack is empty" << endl;
  }
  return item;

}

template <class T, int N>
T Tstack<T,N>::peek(){

  return m_data[m_size-1];

}

template <class T, int N>
bool Tstack<T,N>::isEmpty(){

  if(m_size <= 0){
    return 1;
  }
  else{
    return 0;
  }

}

template <class T, int N>
int Tstack<T,N>::isFull(){

  if(m_size == N){
    return 1;
  }
  else{
    return 0;
  }

}

template <class T, int N>
Tstack<T,N>& Tstack<T,N>::operator=(Tstack<T,N> y){

  if(this == y){
    return *this;
  }
  
  delete[] m_data;

  m_size = y.m_size;
  m_data = new T[N];
  for(int i = 0; i < N; i++){
    m_data[i] = y.m_data[i];
  }

  return *this;
}

template <class T, int N>
int Tstack<T,N>::getSize(){

  return m_size;

}

template <class T, int N>
void Tstack<T,N>::printStack(){

  //N -= 1;
  for(int i = 0; i < N; i++){
    cout << m_data[i];
  }
  cout << endl;

}

#endif
