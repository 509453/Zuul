/*Name: Aleena Shaik 
Purpose: Create an adventure based game. (Zuul)
Sources:
GeeksforGeeks
My Sister and Brother 
Diya's item files reference
https://www.udacity.com/blog/2020/03/c-maps-explained.html (how to use maps)
https://www.learncpp.com/cpp-tutorial/pointer-arithmetic-and-subscripting/
*/


#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "item.h"
#include "room.h"

using namespace std;

vector<item*> playerInventory;  // vector for player's inventory
//print inventorty
void printInventory() {
    if (playerInventory.empty()) {
        cout << "Your inventory is empty." << endl;
    } else {
        cout << "Your inventory: ";
        for (vector<item*>::const_iterator it = playerInventory.begin(); it != playerInventory.end(); ++it) {
            cout << (*it)->getItemDescription() << " ";
        }
        cout<< endl;
    }
}

// add item to inventory
void addInventory(item* newItem) {
    playerInventory.push_back(newItem);  // Add item to the inventory
}

// remove item from inventory
void removeInventory(const char* itemName) {
    for (size_t i = 0; i < playerInventory.size(); ++i) {
        if (strcmp(playerInventory[i]->getItemDescription(), itemName) == 0) {
            playerInventory.erase(playerInventory.begin() + i);
            break;
        }
    }
}

//  user commands
void handleCommands(char* input, room*& currentRoom) {
    // Commands
    char goeast[] = "GO EAST";
    char gowest[] = "GO WEST";
    char gonorth[] = "GO NORTH";
    char gosouth[] = "GO SOUTH";
    char getcomputer[] = "GET COMPUTER";
    char getantenna[] = "GET ANTENNA";
    char gettools[] = "GET TOOLS";
    char getwires[] = "GET WIRES";
    char getwheels[] = "GET WHEELS";
    char drop[] = "DROP";
    char inventory[] = "INVENTORY";
    char quit[] = "QUIT";
    char help[] = "HELP";

    if (strcmp(input, goeast) == 0) {
        room* exitRoom = currentRoom->getExit("EAST");
        if (exitRoom) {
            currentRoom = exitRoom;
            cout<< "You moved east to: "<< currentRoom->getDescription() << endl;
        } else {
            cout<< "No exit in that direction. Turn the other way..." << endl;
        }
        
        
        
    } else if (strcmp(input, gowest) == 0) {
        room* exitRoom = currentRoom->getExit("WEST");
        if (exitRoom) {
            currentRoom = exitRoom;
            cout<< "You moved west to: " << currentRoom->getDescription() << endl;
        } else {
            cout <<  "No exit in that direction. Turn the other way..." << endl;
        }
        
        
    } else if (strcmp(input, gonorth) == 0) {
        room* exitRoom = currentRoom->getExit("NORTH");
        if (exitRoom) {
          currentRoom = exitRoom;
            cout << "You moved north to: " << currentRoom->getDescription() << endl;
        } else {
            cout <<  "No exit in that direction. Turn the other way..." << endl;
        }        
        
        
        
    } else if (strcmp(input, gosouth) == 0) {
        room* exitRoom = currentRoom->getExit("SOUTH");
        if (exitRoom) {
            currentRoom = exitRoom;
            cout << "You moved south to: " << currentRoom->getDescription() << endl;
        } else {
            cout <<  "No exit in that direction. Turn the other way..." << endl;
        }
        
        
        
        
        
    } else if (strcmp(input, getantenna) == 0) {
        item* antenna = NULL;
        // Check if the item is in the room
        for (size_t i = 0; i < currentRoom->items.size(); ++i) {
            if (strcmp(currentRoom->items[i]->getItemDescription(), "ANTENNA") == 0) {
                antenna = currentRoom->items[i];
                break;
            }
        }
        if (antenna) {
            addInventory(antenna);  // Add item to inventory
            currentRoom->removeItem("ANTENNA");  // Remove item from room
            cout << "You picked up the ANTENNA!" << endl;
        } else {
            cout << "There is no ANTENNA here!" << endl;
        }
                       
        }else if (strcmp(input, getwires) == 0) {
        item* wires = NULL;
        // Check if the item is in the room
        for (size_t i = 0; i < currentRoom->items.size(); ++i) {
            if (strcmp(currentRoom->items[i]->getItemDescription(), "WIRES") == 0) {
                wires = currentRoom->items[i];
                break;
            }
        }
        if (wires) {
          addInventory(wires);  // Add item to inventory
        currentRoom->removeItem("WIRES");  // Remove item from room
            cout << "You picked up the WIRES!" << endl;
        } else {
            cout << "There are no WIRES here!" << endl;
        }
        
        
        
           
       } else if (strcmp(input, getwheels) == 0) {
        item* wheels = NULL;
        // Check if the item is in the room
       for (size_t i = 0; i < currentRoom->items.size(); ++i) {
            if (strcmp(currentRoom->items[i]->getItemDescription(), "WHEELS") == 0) {
                wheels = currentRoom->items[i];
                break;
            }
        }
        if (wheels) {
            addInventory(wheels);  // Add item to inventory
            currentRoom->removeItem("WHEELS");  // Remove item from room
            cout << "You picked up the WHEELS!" << endl;
        } else {
            cout << "There are no WHEELS here!" << endl;
        }
        
        
        
        
        
       } else if (strcmp(input, gettools) == 0) {
        item* tools = NULL;
        // Check if the item is in the room
        for (size_t i = 0; i < currentRoom->items.size(); ++i) {
            if (strcmp(currentRoom->items[i]->getItemDescription(), "TOOLS") == 0) {
                tools = currentRoom->items[i];
                break;
            }
        }
        if (tools) {
            addInventory(tools);  // Add item to inventory
            currentRoom->removeItem("TOOLS");  // Remove item from room
            cout<< "You picked up the TOOLS!" <<endl;
        } else {
            cout<< "There are no TOOLS here!" <<endl;
        }
        
        
        
              
       } else if (strcmp(input, getcomputer) == 0) {
        item* computer = NULL;
        // Check if the item is in the room
        for (size_t i = 0; i < currentRoom->items.size(); ++i) {
            if (strcmp(currentRoom->items[i]->getItemDescription(), "COMPUTER") == 0) {
                computer = currentRoom->items[i];
                break;
            }
        }
        if (computer) {
            addInventory(computer);  // Add item to inventory
            currentRoom->removeItem("COMPUTER");  // Remove item from room
            cout<< "You picked up the COMPUTER!"<<endl;
        } else {
            cout<< "There is no COMPUTER here!"<<endl;
        }
        
    } else if (strcmp(input, inventory) == 0) {
        printInventory();
    } else if (strcmp(input, drop) == 0) {
        cout<< "Enter the name of the item to drop: ";
        cin.getline(input, 50);
        // Check if the item is in the inventory
	item* dropItem = NULL;
        for (size_t i = 0; i < playerInventory.size(); ++i) {
            if (strcmp(playerInventory[i]->getItemDescription(), input) == 0) {
                dropItem = playerInventory[i];
                break;
            }
        }
        if (dropItem) {
            currentRoom->addItem(dropItem);  // Add item back to the room
            removeInventory(input);  // Remove item from inventory
            cout<< "You dropped the " << input << "..." << endl;
        } else {
            cout<< "You don't have that item in your inventory..." << endl;
        }
    } else if (strcmp(input, quit) == 0) {
        cout<< "You failed to escape the school..."<< endl;
        exit(0);
    } else if (strcmp(input, help) == 0) {
        cout<<"Type the command words: GO (DIRECTION), GET (ITEM), INVENTORY, QUIT, DROP to drop items."<< endl;
    } else {
        cout<< "Invalid command. Try again."<< endl;
    }
}

int main() {
        room* startRoom = new room("Computer Science Room");
	room* physicsRoom = new room("Physics Room");
 room* entranceRoom = new room("Main entrance");
 room* chemistryRoom = new room("Chemistry Room");
 room* biologyRoom = new room("Biology Room");
 room* historyRoom = new room("History Room");
 room* cccRoom = new room("College and Career Center");
 room* principalRoom = new room("Principal's Office");
 room* businessRoom = new room("Business Room");
room*  cafeRoom = new room("Cafeteria");
 room* lectureRoom = new room("Lecture Room");
 room* janitorRoom = new room("Janitor Room");
 room* gymRoom = new room("Gym");
 room* lockerRoom = new room("Locker Room");
 room* adminRoom = new room("Admin's Office");
 room* parkingRoom = new room("Parking lot");

    // Create items
    item* antenna = new item("ANTENNA");
    principalRoom->addItem(antenna);

item* computer = new item("COMPUTER");
    adminRoom->addItem(computer);
item* tools = new item("TOOLS");
    janitorRoom->addItem(tools);
item* wheels = new item("WHEELS");
    parkingRoom->addItem(wheels);
item* wires = new item("WIRES");
    physicsRoom->addItem(wires);




    // Set exits
        startRoom->setExit("EAST", chemistryRoom);
    startRoom->setExit("WEST", historyRoom);
    startRoom->setExit("SOUTH", entranceRoom);
    chemistryRoom->setExit("WEST", startRoom);
    chemistryRoom->setExit("NORTH" , biologyRoom);
    biologyRoom->setExit("SOUTH" , chemistryRoom);
    biologyRoom->setExit("NORTH" , physicsRoom);
    physicsRoom->setExit("SOUTH" , biologyRoom);
    historyRoom->setExit("EAST", startRoom);
    historyRoom->setExit("WEST", cccRoom);
    historyRoom->setExit("SOUTH", cafeRoom);
   cccRoom->setExit("EAST", historyRoom);
    cccRoom->setExit("WEST", principalRoom);
    cccRoom->setExit("SOUTH", businessRoom);
    principalRoom->setExit("EAST", cccRoom);
    businessRoom->setExit("NORTH", cccRoom);
    businessRoom->setExit("EAST", cafeRoom);
    cafeRoom->setExit("EAST", entranceRoom);
    cafeRoom->setExit("WEST", businessRoom);
    cafeRoom->setExit("NORTH", historyRoom);
    entranceRoom->setExit("WEST", cafeRoom );
    entranceRoom->setExit("EAST", lectureRoom);
    entranceRoom->setExit("NORTH" , startRoom);
   entranceRoom->setExit("SOUTH", gymRoom);
    lectureRoom->setExit("EAST", janitorRoom);
   lectureRoom->setExit("WEST", entranceRoom);
    janitorRoom->setExit("WEST", lectureRoom);
    gymRoom->setExit("NORTH", entranceRoom);
    gymRoom->setExit("SOUTH", parkingRoom);
    gymRoom->setExit("EAST", adminRoom);
    gymRoom->setExit("WEST", lockerRoom);
    lockerRoom->setExit("EAST", gymRoom);
    adminRoom->setExit("WEST", gymRoom);
    parkingRoom->setExit("NORTH", gymRoom);


    room* currentRoom = entranceRoom;
       currentRoom->showRoomInfo();
    cout<< "\nType the command words: GO (DIRECTION), GET (ITEM), INVENTORY, QUIT, DROP to interact."<< endl;

    char input[50];
    
    bool stillPlaying = true; 

    while (stillPlaying == true) {
          currentRoom->showRoomInfo();
    
        cout<< "\nWhat do you want to do? ";
        cin.getline(input, 50);
        handleCommands(input, currentRoom);
        
        
        if (playerInventory.size() == 5) {
            cout<< "You obtained all the items to create yourself a robot to break through the school walls."<<endl;
            cout << "You escaped the school."<< endl; 
            cout<< "You win the game..."<<endl; 
            stillPlaying = false; 
        
    }
        
    }

    return 0;
}
