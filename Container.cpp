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

    accepts.clear();
}

void Container::setName(std::string name) { 
    this->name = name;
    std::cout << "Container name set to " << name << std::endl;
}

void Container::setStatus(std::string status) { 
    this->status = status;
    std::cout << "Container status set to " << status << std::endl;
}

void Container::addAccept(std::string accept) { 
    accepts.push_back(accept);
    std::cout << "Added accept name " << accept << " to Container" << std::endl;
}

void Container::addItem(Item* item) { 
    items.push_back(item);
    std::cout << "Added item " << item->getName() << " to Container" << std::endl;
}
void Container::addCondition(Condition* condition) {
    conditions.push_back(condition);
    std::cout << "Added Condition to Container" << std::endl;
}

void Container::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
    std::cout << "Added Trigger to Container" << std::endl;
}

std::string Container::getName() {
    return name;
}

std::string Container::getStatus() {
    return status;
}

std::vector<std::string> Container::getAccepts() {
    return accepts;
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