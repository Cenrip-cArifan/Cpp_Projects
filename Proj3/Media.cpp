#include "Media.h"

using namespace std;


Media::Media(){

  m_rank = 0;
  m_name = "";
  m_year = 0;
  m_type = "";

}

Media::Media(int rank, string name, int year, string type){

  m_rank = rank;
  m_name = name;
  m_year = year;
  m_type = type;

}

int Media::getRank(){

  return m_rank;

}

string Media::getName(){

  return m_name;

}

int Media::getYear(){

  return m_year;

}


string Media::getType(){

  return m_type;

}


void Media::setRank(int rank){

  m_rank = rank;

}


void Media::setName(string name){

  m_name = name;

}

void Media::setYear(int year){

  m_year = year;

}


void Media::setType(string type){

  m_type = type;

}
  
