#include <iostream>
#include "Trigger.h"

Trigger::Trigger() {
    std::cout << "Trigger object created." << std::endl;
}

Trigger::~Trigger() {
    delete condition;
}

void Trigger::setType(std::string type) {
    this->type = type;
}

void Trigger::setCommand(std::string command) {
    this->command = command;
}

void Trigger::setPrint(std::string print) {
    this->print = print;
}

void Trigger::setAction(std::string action) {
    this->action = action;
}

void Trigger::setCondition(Condition* condition) {
    this->condition = condition;
}

std::string Trigger::getType(){
    return type;
}

std::string Trigger::getCommand() {
    return command;
}

std::string Trigger::getPrint() {
    return print;
}

std::string Trigger::getAction() {
    return action;
}

Condition* Trigger::getCondition() {
    return condition;
}