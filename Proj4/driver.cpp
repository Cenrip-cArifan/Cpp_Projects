/*Title: driver.cpp
Author: Prof. Dixon
Date: 7/13/2017
Description: This is the driver for project 4 - True Grit Furniture
*/

#include "Catalog.h"

int main (int argc, char *argv[]) {
  if ( argc != 2 ){
    cout << "This requires a Furniture file to be loaded." << endl;
    cout << "Usage: ./proj4 proj4_data1.txt" << endl;
    exit(1);
  }
  string fileName = argv[1];
  Catalog myCatalog(fileName);
  return 0;
}
