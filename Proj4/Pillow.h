#ifndef PILLOW_H
#define PILLOW_H
#include <string>
using namespace std;

class Pillow {
public:  
  // Pillow()
  // pre:  -
  // post: Pillow of a random color (randomly white, black, brown, or gray)
  Pillow();
  
  //  getColor()
  // pre:  -
  // post: returns own color
  string GetColor();
  
 private:
  string m_color;
};

#endif
