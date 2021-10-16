#include <iostream>
#include "Attack.h"

Attack::Attack() {
    std::cout << "Attack object created." << std::endl;
}

Attack::~Attack() {
    delete condition;
}

void Attack::setPrint(std::string print) {
    this->print = print;
}

void Attack::addAction(std::string action) {
    actions.push_back(action);
}

void Attack::setCondition(Condition* condition) {
    this->condition = condition;
}

std::string Attack::getPrint() {
    return print;
}

std::vector<std::string> Attack::getActions() {
    return actions;
}

Condition* Attack::getCondition() {
    return condition;
}