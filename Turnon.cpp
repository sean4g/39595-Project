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


void Turnon::setAction(std::string action) {
    this->action = action;
}


std::string Turnon::getPrint() {
    return print;
}

std::string Turnon::getAction() {
    return action;
}
