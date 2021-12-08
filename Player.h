#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Item.h"
#include "Room.h"
#include "Map.h"
#include "Dungeon.h"

class Player {
private:
    std::string status;
    std::vector<Item*> inventory;
    Room* currentRoom;
    Map* map;
    Dungeon* dungeon;
public:
    Player(Map* map, Dungeon* dungeon); 
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

    void checkTriggers();
    int checkTrigCommand(std::string string);
    int checkCondition(Trigger* trigger);
    void executeAction(std::string action);
    void executeTrigger(Trigger* trigger);
    void updateObject(std::string object, std::string status);
    void turnOnItem(std::string item);


    std::string getStatus();
    std::vector<Item*>& getInventory();
    Room* getCurrentRoom();
    void printInventory(); 
};