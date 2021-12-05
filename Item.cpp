#include <iostream>
#include "Item.h"

Item::Item() {
    std::cout << "Item object created." << std::endl;
    setTurnon(NULL);
    setWriting("Nothing written.");
}

Item::~Item() {
    for (Trigger* trigger : triggers){
        delete trigger;
    }
    triggers.clear();
}

void Item::setName(std::string name) { 
    std::cout << "Item name set to " << name << std::endl;
    this->name = name;
}

void Item::setWriting(std::string writing) { 
    this->writing = writing;
    std::cout << "Item writing set to " << writing << std::endl;
}
void Item::setStatus(std::string status) { 
    this->status = status;
    std::cout << "Item status set to " << status << std::endl;
}

void Item::setDescription(std::string description) {
    this->description = description;
    std::cout << "Item description set to " << description << std::endl;
}

void Item::setTurnon(Turnon* turnon) {
    this->turnon = turnon;
    std::cout << "Item Turnon set " << std::endl;
}

void Item::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
    std::cout << "Added Trigger to Item " << std::endl;
}

std::string Item::getName() {
    return name;
}

std::string Item::getWriting() {
    return writing;
}
std::string Item::getStatus() {
    return status;
}

std::string Item::getDescription() {
    return description;
}

std::vector<Trigger*>& Item::getTriggers() {
    return triggers;
}

Turnon* Item::getTurnon() {
    return turnon;
}