#include "room.h"
#include <iostream>
#include <map>
#include <cstring>  

using namespace std;

// Constructor to initialize the room with a description
room::room(char* newDescription) {
    description = newDescription;
}

// set an exit in a specified direction
void room::setExit(char* direction, room* r) {
    exits[direction] = r;
}

//get an exit for a specified direction
room* room::getExit(char* direction) {
    
    //<map> has its own in-built functions and .find finds that direction user specified 
    if (exits.find(direction) != exits.end()) {
        return exits[direction];
    }
    return NULL; //if no exit is found 
}

//add an item to the room
void room::addItem(item* newItem) {
    items.push_back(newItem);
}

//Remove an item from a room 
void room::removeItem(char* itemName) {
    //reference from studentlist 
    for (int i = 0; i < items.size(); ++i) {
        if (strcmp(items[i]->getItemDescription(),itemName)==0) {
            items.erase(items.begin() + i);
            break;
        }
        
        
    }
}


//displaying room info 
void room::showRoomInfo() {
    cout<<"You are in: "<<description<< endl;
    cout<< "exits: ";
    for (auto& exit : exits) {
        cout<<exit.first<< " ";
    }
    
    
    
    
    cout<< endl;

    cout<< "Items in this room: ";
    for (auto& it : items) {
        
        cout<<it->getItemDescription()<< " ";
    }
    cout<< endl;
}
