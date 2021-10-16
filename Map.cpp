#include <iostream>
#include "Map.h"

void Map::insertRoom(Room* room) {
    roomMap.insert(std::pair<std::string, Room*>(room->getName(), room));
}

void Map::insertItem(Item* item) {
    itemMap.insert(std::pair<std::string, Item*>(item->getName(), item));
}

void Map::insertContainer(Container* container) {
    containerMap.insert(std::pair<std::string, Container*>(container->getName(), container));
}

void Map::insertCreature(Creature* creature) {
    creatureMap.insert(std::pair<std::string, Creature*>(creature->getName(), creature));
}

Item* Map::findItem(std::string name) {

    std::unordered_map<std::string, Item*>::const_iterator got = itemMap.find(name);

    if (got == itemMap.end()) {
        Item* item = new Item();
        item->setName(name);
        insertItem(item);        
        return item;
    }   
    else {
        std::cout << "Using existing Item " << got->second->getName() << " from Map" << std::endl;
        return got->second;
    }
}

Container* Map::findContainer(std::string name) {

    std::unordered_map<std::string, Container*>::const_iterator got = containerMap.find(name);

    if (got == containerMap.end()) {
        Container* container = new Container();
        container->setName(name);
        insertContainer(container);        
        return container;
    }   
    else {
        std::cout << "Using existing Container " << got->second->getName() << " from Map" << std::endl;
        return got->second;
    }
}

Creature* Map::findCreature(std::string name) {

    std::unordered_map<std::string, Creature*>::const_iterator got = creatureMap.find(name);

    if (got == creatureMap.end()) {
        Creature* creature = new Creature();
        creature->setName(name);
        insertCreature(creature);        
        return creature;
    }   
    else {
        std::cout << "Using existing Creature " << got->second->getName() << " from Map" << std::endl;
        return got->second;
    }
}


Map::Map() {
    std::cout << "Map object created." << std::endl;
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
    std::cout << "Added room " << room->getName() << " to Map" << std::endl;
}

void Map::addItem(Item* item) {
    items.push_back(item);
    std::cout << "Added item " << item->getName() << " to Map" << std::endl;
}

void Map::addContainer(Container* container) {
    containers.push_back(container);
    std::cout << "Added container " << container->getName() << " to Map" << std::endl;
}

void Map::addCreature(Creature* creature) {
    creatures.push_back(creature);
    std::cout << "Added creature " << creature->getName() << " to Map" << std::endl;
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
