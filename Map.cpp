#include <iostream>
#include "Map.h"

Map::Map() {
    std::cout << "Map object created" << std::endl;
}

Map::~Map() {
    for (Room* room : rooms){
        delete room;
    }
    rooms.clear();

    for (Item* item : items){
        delete item;
    }
    items.clear();

    for (Container* container : containers){
        delete container;
    }
    containers.clear();

    for (Creature* creature : creatures){
        delete creature;
    }
    creatures.clear();
}

void Map::addRoom(Room* room) {
    rooms.push_back(room);
}

void Map::addItem(Item* item) {
    items.push_back(item);
}

void Map::addContainer(Container* container) {
    containers.push_back(container);
}

void Map::addCreature(Creature* creature) {
    creatures.push_back(creature);
}

std::vector<Room*> Map::getRooms() {
    return rooms;
}

std::vector<Item*> Map::getItems() {
    return items;
}

std::vector<Container*> Map::getContainers() {
    return containers;
}

std::vector<Creature*> Map::getCreatures() {
    return creatures;
}
