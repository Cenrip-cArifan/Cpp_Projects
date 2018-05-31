#include "System.h"

System::System(){

  m_media = Storage();

}

System::System(string fileName){

  m_media = Storage(fileName);
  mainMenu();
  loadMedia(fileName);

}

void System::mainMenu(){

  int choice = 0;
  bool isBool = true;
  string type;
  do{
    cout << "What would you like to do?" << endl
	 << "1. View All Media Files" << endl
	 << "2. View Media Files By Ranking" << endl
	 << "3. View Media Files By Type" << endl
	 << "4. Rent a Media File By Name" << endl
	 << "5. Add a Media File" << endl
	 << "6. Sort By Ranking" << endl
	 << "7. Exit" << endl;
    cin >> choice;

    switch(choice){
    case 1:
      printStorage(isBool);
      break;
    case 2:
      m_media.printByMedia(type);
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      cout << "Good bye!" << endl;
      break;
    }
  }while(choice != 7);
}


int System::loadMedia(string fileName){


  ifstream fileIn(fileName.c_str());
  string rank, year, name, type;
  int numMed = 0;
  while(getline(fileIn, rank, '\t')){
    getline(fileIn, name, '\t');
    getline(fileIn, year, '\t');
    getline(fileIn, type);

    cout << rank << ". " << name << endl;

    Media newMedia(atoi(rank.c_str()), name, atoi(year.c_str()), type);
    m_media.insertEnd(newMedia);
    numMed++;
  }
  fileIn.close();

  return 1;
    
}


void System::printStorage(bool isNumbered){
  
  isNumbered = false;
  if(isNumbered == true){
    m_media.printStorage(true); //Print data from file numbered
  }
  else{
    m_media.printStorage(false); //Print data from file unnumbered
  }

}


void System::removeMedia(string name){

  cout << "What is the name of the media?" << endl;
  getline(cin, name);

  if(m_media.checkName(name)){
    m_media.removeByName(name);
    cout << "name: " << name << endl
	 << name << " removed" << endl;
  } 
}

void System::insertMedia(){

  string mediaType, mediaName;
  int mediaYear, mediaRank;
  cout << "What type of media is it?" << endl
       << "Enter BLURAY, DVD, PS4, or XBOX:" << endl;
  cin >> mediaType;

  cin.ignore(100, '\n');

  cout << "What is the name?" << endl;
  getline(cin, mediaName);

  cout << "What is the year?" << endl;
  cin >> mediaYear;

  cout << "What is the ranking?" << endl;
  cin >> mediaRank;

}
