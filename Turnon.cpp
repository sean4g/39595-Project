#include <iostream>
#include "Turnon.h"

Turnon::Turnon() {
    std::cout << "Turnon object created." << std::endl;
}

Turnon::~Turnon() {
}

void Turnon::setPrint(std::string print) {
    this->print = print;
}


void Condition::setAction(std::string action) {
    this->action = action;
}


std::string Condition::getPrint() {
    return print;
}

std::string Condition::getAction() {
    return action;
}
