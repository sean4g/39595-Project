#include <iostream>
#include "Item.h"

Item::Item() {
    std::cout << "Item object created." << std::endl;
}

Item::~Item() {
}

void Item::setName(std::string name) { 
    this->name = name;
}

void Item::setWriting(std::string writing) { 
    this->writing = writing;
}
void Item::setStatus(std::string status) { 
    this->status = status;
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