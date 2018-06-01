#ifndef CATALOG_H
#define CATALOG_H
#include "Furniture.h"
#include "Chair.h"
#include "Sofa.h"
#include "Pillow.h"

class Catalog {
public:
  //Title: Catalog(string) Constructor
  //Pre: Catalog
  //Post: Catalog object with a file of furniture to load
  //Calls addFurniture
  Catalog(string filename);

  //Title: Catalog() Destructor
  //Pre: Catalog
  //Post: Catalog object (and furniture) are destroyed
  ~Catalog();

  //Title: SearchCatalog()
  //Pre: Populated Catalog
  //Can search on width, height, depth, area, price, material, or color
  //Post: Returns a furniture pointer from catalog
  void SearchCatalog();

  //Title: CatalogMenu()
  //Pre: Populated Catalog
  //Post: Calls appropriate function
  void CatalogMenu();

  //Title: ListFurniture()
  //Pre: Populated Catalog
  //Post: Displays entire catalog
  void ListFurniture();

private:
    vector <Furniture*> m_catalog;
};

#endif
