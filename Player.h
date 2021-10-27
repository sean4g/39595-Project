#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"
#include "Map.h"

class Player {
private:
    std::string status;
    std::vector<Item*> inventory;
    Room* currentRoom;
public:
    Player(Map* map); 
    virtual ~Player();
    void setStatus(std::string status);
    void addItem(Item* item);
    void setRoom(Room* room);

    std::string getStatus();
    std::vector<Item*> getInventory();
    Room* getCurrentRoom();
    
    void printInventory(); 
};