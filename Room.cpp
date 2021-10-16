#include <iostream>
#include "Room.h"

Room::Room() {
    std::cout << "Room object created" << std::endl;
}

Room::~Room() {
    for (Item* item : items){
        delete item;
    }
    items.clear();

    for (Border* border : borders){
        delete border;
    }
    borders.clear();

    for (Container* container : containers){
        delete container;
    }
    containers.clear();

    for (Creature* creature : creatures){
        delete creature;
    }
    creatures.clear();

    for (Trigger* trigger : triggers){
        delete trigger;
    }
    triggers.clear();
}

void Room::setName(std::string name) { 
    this->name = name;
    std::cout << "Room name set to " << name << std::endl;
}

void Room::setDescription(std::string description) { 
    this->description = description;
    std::cout << "Room description set to " << description << std::endl;
}

void Room::setType(std::string type) { 
    this->type = type;
    std::cout << "Room type set to " << type << std::endl;
}

void Room::setStatus(std::string status) {
    this->status = status;
    std::cout << "Room status set to " << status << std::endl;
}

void Room::addItem(Item* item) {
    items.push_back(item);
    std::cout << "Added item " << item->getName() << " to Room" << std::endl;
}

void Room::addBorder(Border* border) {
    borders.push_back(border);
    std::cout << "Added Border to Room" << std::endl;
}

void Room::addContainer(Container* container) {
    containers.push_back(container);
    std::cout << "Added Container " << container->getName() << " to Room" << std::endl;
}

void Room::addCreature(Creature* creature) {
    creatures.push_back(creature);
    std::cout << "Added Creature " << creature->getName() << " to Room" << std::endl;
}

void Room::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
    std::cout << "Added Trigger to Room" << std::endl;
}

std::string Room::getName() {
    return name;
}

std::string Room::getDescription() {
    return description;
}

std::string Room::getType() {
    return type;
}

std::string Room::getStatus() {
    return status;
}

std::vector<Item*> Room::getItems() {
    return items;
}

std::vector<Border*> Room::getBorders() {
    return borders;
}

std::vector<Container*> Room::getContainers() {
    return containers;
}

std::vector<Creature*> Room::getCreatures() {
    return creatures;
}

std::vector<Trigger*> Room::getTriggers() {
    return triggers;
}