#include "item.h"
#include <iostream>
#include <cstring>

using namespace std;
item::item() {
    description = NULL;
    //initially is null if no name is given
}

item::item (char* newdescription){ // Constructor
    description = newdescription;

}

char* item::getItemDescription(){ //return value
    return description;
}



