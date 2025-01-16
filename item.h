#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>
#include <map>

using namespace std; 

class item{ 
  public:
  item();
  char* description;//Constructor
  item (char* description);//Method
  char* getItemDescription(); //Pointer to store decription data
  
};

#endif
