#include <iostream>
#include "Border.h"

Border::Border() {
    std::cout << "Border object created." << std::endl;
}

Border::~Border() {
}

void Border::setDirection(std::string direction) {
    this->direction = direction;
}

void Border::setName(std::string name) {
    this->name = name;
}

std::string Border::getDirection() {
    return direction;
}

std::string Border::getName() {
    return name;
}