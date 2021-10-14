#include <iostream>
#include "Container.h"

Container::Container() {
    std::cout << "Container object created" << std::endl;
}

Container::~Container() {
    for (Condition* condition : conditions){
        delete condition;
    }
    conditions.clear();

    for (Trigger* trigger : triggers){
        delete trigger;
    }
    triggers.clear();
}

void Container::setName(std::string name) { 
    this->name = name;
}

void Container::setItem(std::string item) { 
    this->item = item;
}
void Container::setStatus(std::string status) { 
    this->status = status;
}

void Container::setAccept(std::string Accept) { 
    this->accept = accept;
}

void Container::addCondition(Condition* condition) {
    conditions.push_back(condition);
}

void Container::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
}

std::string Container::getName() {
    return name;
}

std::string Container::getItem() {
    return item;
}
std::string Container::getStatus() {
    return status;
}

std::string Container::getAccept() {
    return accept;
}

std::vector<Condition*> Container::getConditions() {
    return conditions;
}

std::vector<Trigger*> Container::getTriggers() {
    return triggers;
}