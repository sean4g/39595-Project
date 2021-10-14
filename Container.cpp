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

    for (Item* item : items){
        delete item;
    }
    items.clear();
}

void Container::setName(std::string name) { 
    this->name = name;
}

void Container::setStatus(std::string status) { 
    this->status = status;
}

void Container::setAccept(std::string Accept) { 
    this->accept = accept;
}

void Container::addItem(Item* item) { 
    items.push_back(item);
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

std::string Container::getStatus() {
    return status;
}

std::string Container::getAccept() {
    return accept;
}

std::vector<Item*> Container::getItems() {
    return items;
}

std::vector<Condition*> Container::getConditions() {
    return conditions;
}

std::vector<Trigger*> Container::getTriggers() {
    return triggers;
}