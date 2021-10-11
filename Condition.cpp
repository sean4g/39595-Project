#include <iostream>
#include "Condition.h"

Condition::Condition() {
    std::cout << "Condition object created." << std::endl;
}

Condition::~Condition() {
}

void Condition::setObject(std::string object) {
    this->object = object;
}


void Condition::setStatus(std::string status) {
    this->status = status;
}


void Condition::setOwner(std::string owner) {
    this->owner = owner;
}


void Condition::setHas(std::string has) {
    this->has = has;
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