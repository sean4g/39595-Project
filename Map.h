#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"

class Map {
private:
    std::vector<Room*> rooms;
    std::vector<Item*> items;
    std::vector<Container*> containers;
    std::vector<Creature*> creatures;

public:
    std::unordered_map<std::string, Room*> roomMap;
    std::unordered_map<std::string, Item*> itemMap;
    std::unordered_map<std::string, Container*> containerMap;
    std::unordered_map<std::string, Creature*> creatureMap;

    Map();
    virtual ~Map();

    void insertRoom(Room* room);
    void insertItem(Item* item);
    void insertContainer(Container* container);
    void insertCreature(Creature* creature);

    Room* findRoom(std::string name);
    Item* findItem(std::string name);
    Container* findContainer(std::string name);
    Creature* findCreature(std::string name);

    void addRoom(Room* room);
    void addItem(Item* item);
    void addContainer(Container* container);
    void addCreature(Creature* creature);

    std::vector<Room*> getRooms();
    std::vector<Item*> getItems();
    std::vector<Container*> getContainers();
    std::vector<Creature*> getCreatures();
};