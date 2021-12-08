#include <iostream>
#include "Condition.h"

Condition::Condition() {
    std::cout << "Condition object created." << std::endl;
    has = "";
    object = "";
}

Condition::~Condition() {
}

void Condition::setObject(std::string object) {
    this->object = object;
    std::cout << "Condition object name set to " << object << std::endl;
}


void Condition::setStatus(std::string status) {
    this->status = status;
    std::cout << "Condition status set to " << status << std::endl;
}


void Condition::setOwner(std::string owner) {
    this->owner = owner;
    std::cout << "Condition owner name set to " << owner << std::endl;
}


void Condition::setHas(std::string has) {
    this->has = has;
    std::cout << "Condition Has set to " << has << std::endl;
}

std::string Condition::getObject() {
    return object;
}

std::string Condition::getStatus() {
    return status;
}

std::string Condition::getOwner() {
    return owner;
}

std::string Condition::getHas() {
    return has;
}