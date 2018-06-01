//File: Catalog.cpp
//Project: CMSC 202 Project 4, Summer 2017
//Author: Gabriel Kilungya
//Date: 07/27/17
//Section: 02
//Email: kilgab1@umbc.edu
//This file contains C++ implementation of Catalog.h gile
//Initially populates vector<Furniture*> m_catalog with data from input file
//Manages the menu system, whether want to search details(height, width, depth,
//price, color, material, or area) of furniture, list all furniture or exit



#include "Catalog.h"

using namespace std;

// Title: Catalog(string) Constructor
// Pre: Catalog
// Post: Catalog object with a file of furniture to load

Catalog::Catalog(string filename) {

  ifstream fin(filename.c_str());
  string type, material, color;
  string width, height, depth;
  string numOfPillows;
  string price;
  int numSofas = 0;
  int numChairs = 0;
  int totFurn = 0;

  Sofa *sa;
  Chair *ch;

  //while the type of furniture whether sofa or chair, compare first character
  //of string.
  //if character is S, load in the parameters of the new Sofa object created
  //count how many Sofas are there, then push Sofa objects in vector 'm_catalog'
  //else load in parameters of the new Chair object created
  //count how many Chairs are there, then push Chair objects in m_catalog
  //display how many sofas, chairs and total funriture has been loaded in
  
  //call CatalogMenu() function to run the Catalog
  while (fin >> type) {
    if (type[0] == 'S') {
      fin >> width;
      fin >> height;
      fin >> depth;
      fin >> price;
      fin >> material;
      fin >> numOfPillows;
      sa = new Sofa(atoi(width.c_str()), atoi(height.c_str()),
                    atoi(depth.c_str()), atof(price.c_str()), material,
                    atoi(numOfPillows.c_str()));
      ++numSofas;
      m_catalog.push_back(sa);
    } else {
      fin >> width;
      fin >> height;
      fin >> depth;
      fin >> price;
      fin >> material;
      fin >> color;
      ch = new Chair(atoi(width.c_str()), atoi(height.c_str()),
                     atoi(depth.c_str()), atof(price.c_str()), material, color);
      ++numChairs;
      m_catalog.push_back(ch);
    }
    ++totFurn;
  }
  cout << "Sofas Loaded: " << numSofas << endl;
  cout << "Chairs Loaded: " << numChairs << endl;
  cout << "Total Furniture Loaded: " << totFurn << endl;
  fin.close();

  cout << "True Grit Furniture" << endl;

  CatalogMenu();
}

// Title: Catalog() Destructor
// Pre: Catalog
// Post: Catalog object (and furniture) are destroyed

Catalog::~Catalog() {

  for(size_t i = 0; i < m_catalog.size(); ++i){
    delete m_catalog[i];
  }
}

// Title: SearchCatalog()
// Pre: Populated Catalog
// Can search on width, height, depth, area, price, material, or color
// Post: Returns a furniture pointer from catalog

void Catalog::SearchCatalog() {

  int choice;
  int minVal, maxVal;
  double minPrice, maxPrice;
  string material, color;

  //use do-while loop to create a menu that asks user to select the type of
  //constraints he/she is looking for to get desired type of Furniture
  //whether it's a Sofa or Chair
  //constraints are: (widht, height, depth, area, material, price, or color)

  do {
    cout << "What would you like to search by?" << endl
	 << "1. Width" << endl
         << "2. Height" << endl
         << "3. Depth" << endl
         << "4. Area" << endl
         << "5. Material" << endl
         << "6. Price" << endl
         << "7. Color" << endl;
    cin >> choice;

    int c = 1;

    //when user chooses options 1-4 & 6, user is asked to enter a min * max value
    //this will display the type of furniture that is in between the values
    //excluding the outer bounds with the rest of it's information

    //when user chooses options 5 or 7, user enters type of material for choice 5
    //type of color for choice 6, then it displays the type of furniture that has
    //the given color or material with the rest of it's information
    switch (choice) {
    case 1:
      cout << "What is the minimum value you would like to search for?" << endl;
      cin >> minVal;
      cout << "What is the maximum value you would like to search for?" << endl;
      cin >> maxVal;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->GetWidth() > minVal && m_catalog[i]->GetWidth() < maxVal)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    case 2:
      cout << "What is the minimum value you would like to search for?" << endl;
      cin >> minVal;
      cout << "What is the maximum value you would like to search for?" << endl;
      cin >> maxVal;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->GetHeight() > minVal && m_catalog[i]->GetHeight() < maxVal)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    case 3:
      cout << "What is the minimum value you would like to search for?" << endl;
      cin >> minVal;
      cout << "What is the maximum value you would like to search for?" << endl;
      cin >> maxVal;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->GetDepth() > minVal && m_catalog[i]->GetDepth() < maxVal)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    case 4:
      cout << "What is the minimum value you would like to search for?" << endl;
      cin >> minVal;
      cout << "What is the maximum value you would like to search for?" << endl;
      cin >> maxVal;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->Area() > minVal && m_catalog[i]->Area() < maxVal)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    case 5:
      cout << "What type of material? (cloth, wood, leather, or metal)" << endl;
      cin >> material;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->GetMaterial() == material)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    case 6:
      cout << "What is the minimum value you would like to search for?" << endl;
      cin >> minPrice;
      cout << "What is the maximum value you would like to search for?" << endl;
      cin >> maxPrice;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->GetPrice() > minPrice && m_catalog[i]->GetPrice() < maxPrice)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    case 7:
      cout << "What color? (white, black, brown, green, blue, or gray)" << endl;
      cin >> color;

      for(size_t i = 0; i < m_catalog.size(); ++i)
      {
        if(m_catalog[i]->GetColor() == color)
        {
          cout << c++ << ". ";
          *m_catalog[i] << cout;
        }
      }

      break;
    }
  } while (choice < 1 || choice > 7);
}

// Title: CatalogMenu()
// Pre: Populated Catalog
// Post: Calls appropriate function

void Catalog::CatalogMenu() {

  int choice;

  //do-while loop is used to display main menu of the program: Catalog menu
  //If user selects 1: the function SearchCatalog() is given control and has its
  //own menu of specific search of a type of furniture
  //If user selects 2: the function ListFurniture() is given control and displays
  //all the furniture loaded from the data file
  //If user slects 3: the program exits

  do {
    cout << "What would you like to do?" << endl
         << "1. Search" << endl
         << "2. List All Furniture" << endl
         << "3. Exit" << endl;

    cin >> choice;

    switch (choice) {
    case 1:
      SearchCatalog();
      break;
    case 2:
      ListFurniture();
      break;
    case 3:
      cout << "Thanks for using True Grit Furniture Catalog" << endl
           << "Have a nice day!" << endl;
      break;
    }

  } while (choice != 3);
}

// Title: ListFurniture()
// Pre: Populated Catalog
// Post: Displays entire catalog

void Catalog::ListFurniture() {

  //for loop iterates through the vector, since the vector is of unknown size
  //we make suer we use built-in size() vector function to deal with 
  //out-of-bound errors
  //derfernce vector pointer to get the value stored in vector at given indexes
  //and call ostream& operator<<() from Child classes Sofa.cpp & Chair.cpp
  //to organize output of the data correctly, relative to Funriture type

  int sizeOfVec = m_catalog.size();

  for (int i = 0; i < sizeOfVec; ++i) {
    *m_catalog[i] << cout;
  }
}
