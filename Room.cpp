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
}

void Room::setDescription(std::string description) { 
    this->description = description;
}

void Room::setType(std::string type) { 
    this->type = type;
}

void Room::addItem(Item* item) {
    items.push_back(item);
}

void Room::addBorder(Border* border) {
    borders.push_back(border);
}

void Room::addContainer(Container* container) {
    containers.push_back(container);
}

void ::addCreature(Creature* creature) {
    creatures.push_back(creature);
}

void Room::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
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