#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <vector>
#include <cstring> 
#include "item.h"  // Include item class to manage items

using namespace std;

class room {
public:


//making methods to use with rooms
    room(char* newDescription);  
    void setExit(char* direction, room* r); 
    room* getExit(char* direction);  
    void addItem(item* newItem); 
    void removeItem(char* itemName); 
    void showRoomInfo(); 
    const char* getDescription() const { return description; }

    const char* description;  //room description
    map<char*, room*> exits;  //exits in different directions
    vector<item*> items;  //items in the room
};

#endif
