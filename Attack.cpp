#include <iostream>
#include "Attack.h"

Attack::Attack() {
    std::cout << "Attack object created." << std::endl;
}

Attack::~Attack() {
    for (Condition* condition : conditions){
        delete condition;
    }
    conditions.clear();
    actions.clear();
}

void Attack::setPrint(std::string print) {
    this->print = print;
    std::cout << "Attack print set to " << print << std::endl;
}

void Attack::addAction(std::string action) {
    actions.push_back(action);
    std::cout << "Added action " << action << " to Attack" << std::endl;
}

void Attack::addCondition(Condition* condition) {
    conditions.push_back(condition);
    std::cout << "Added attack condition" << std::endl;
}

std::string Attack::getPrint() {
    return print;
}

std::vector<std::string>& Attack::getActions() {
    return actions;
}

std::vector<Condition*>& Attack::getConditions() {
    return conditions;
}