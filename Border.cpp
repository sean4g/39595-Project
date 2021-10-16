#include <iostream>
#include "Border.h"

Border::Border() {
    std::cout << "Border object created." << std::endl;
}

Border::~Border() {
}

void Border::setDirection(std::string direction) {
    this->direction = direction;
    std::cout << "Border direction set to " << direction << std::endl;
}

void Border::setName(std::string name) {
    this->name = name;
    std::cout << "Border name set to " << name << std::endl;
}

std::string Border::getDirection() {
    return direction;
}

std::string Border::getName() {
    return name;
}