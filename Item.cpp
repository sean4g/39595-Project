#include <iostream>
#include "Item.h"

Item::Item() {
    std::cout << "Item object created." << std::endl;
}

Item::~Item() {
}

void Item::setName(std::string name) { 
    std::cout << "Item name set to " << name << std::endl;
    this->name = name;
}

void Item::setWriting(std::string writing) { 
    this->writing = writing;
}
void Item::setStatus(std::string status) { 
    this->status = status;
}

void Item::setTurnon(Turnon* turnon) {
    this->turnon = turnon;
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

Turnon* Item::getTurnon() {
    return turnon;
}