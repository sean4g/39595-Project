#include <iostream>
#include "Turnon.h"

Turnon::Turnon() {
    std::cout << "Turnon object created." << std::endl;
}

Turnon::~Turnon() {
}

void Turnon::setPrint(std::string print) {
    this->print = print;
    std::cout << "Turnon print set to " << print << std::endl;
}


void Turnon::addAction(std::string action) {
    actions.push_back(action);
    std::cout << "Added action " << action << " to Turnon" << std::endl;
}


std::string Turnon::getPrint() {
    return print;
}

std::vector<std::string> Turnon::getActions() {
    return actions;
}
