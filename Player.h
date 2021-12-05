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
    void addItem(std::string item);
    void dropItem(std::string item);
    void setRoom(Room* room);

    void lookRoom();
    void moveRoom(std::string direction, Map* map);

    void openContainer(std::string container);
    void putContainer(std::string container, std::string item);

    void readItem(std::string item);

    std::string getStatus();
    std::vector<Item*>& getInventory();
    Room* getCurrentRoom();
    void printInventory(); 
};