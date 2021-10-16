#include <iostream>
#include "Creature.h"

Creature::Creature() {
    std::cout << "Creature object created" << std::endl;
}

Creature::~Creature() {

    for (Condition* condition : conditions){
        delete condition;
    }
    conditions.clear();

    for (Trigger* trigger : triggers){
        delete trigger;
    }
    triggers.clear();
}

void Creature::setName(std::string name) { 
    this->name = name;
    std::cout << "Creature name set to " << name << std::endl;
}

void Creature::addVulnerability(std::string vulnerability) { 
    vulnerabilities.push_back(vulnerability);
    std::cout << "Added vulnerability " << vulnerability << " to Creature" << std::endl;
}

void Creature::setAttack(Attack* attack) {
    this->attack = attack;
    std::cout << "Creature attack set" << std::endl;
}

void Creature::addCondition(Condition* condition) {
    conditions.push_back(condition);
    std::cout << "Added Condition to Creature" << std::endl;
}

void Creature::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
    std::cout << "Added Trigger to Creature" << std::endl;
}

std::string Creature::getName() {
    return name;
}

std::vector<std::string> Creature::getVulnerabilities() {
    return vulnerabilities;
}

Attack* Creature::getAttack() {
    return attack;
}

std::vector<Condition*> Creature::getConditions() {
    return conditions;
}

std::vector<Trigger*> Creature::getTriggers() {
    return triggers;
}