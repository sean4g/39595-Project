#include <iostream>
#include "Trigger.h"

Trigger::Trigger() {
    std::cout << "Trigger object created." << std::endl;
}

Trigger::~Trigger() {
    for (Condition* condition : conditions){
        delete condition;
    }
    conditions.clear();
}

void Trigger::setType(std::string type) {
    this->type = type;
    std::cout << "Trigger type set to " << type << std::endl;
}

void Trigger::setCommand(std::string command) {
    this->command = command;
    std::cout << "Trigger command set to " << command << std::endl;
}

void Trigger::addPrint(std::string print) {
    prints.push_back(print);
    std::cout << "Added print " << print << " to Trigger" << std::endl;
}

void Trigger::addAction(std::string action) {
    actions.push_back(action);
    std::cout << "Added action " << action << " to Trigger" << std::endl;
}

void Trigger::addCondition(Condition* condition) {
    conditions.push_back(condition);
    std::cout << "Added Condition to Trigger" << std::endl;
}

std::string Trigger::getType(){
    return type;
}

std::string Trigger::getCommand() {
    return command;
}

std::vector<std::string> Trigger::getPrints() {
    return prints;
}

std::vector<std::string> Trigger::getActions() {
    return actions;
}

std::vector<Condition*> Trigger::getConditions() {
    return conditions;
}