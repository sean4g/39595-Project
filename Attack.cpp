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

void Attack::setAction(std::string action) {
    this->action = action;
}

void Trigger::setCondition(Condition* condition) {
    this->condition = condition;
}

std::string Attack::getPrint() {
    return print;
}

std::string Attack::getAction() {
    return action;
}

Condition* Attack::getCondition() {
    return condition;
}