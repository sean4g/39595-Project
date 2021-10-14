#include <iostream>
#include "Creature.h"

Creature::Creature() {
    std::cout << "Creature object created" << std::endl;
}

Creature::~Creature() {
    for (Attack* attack : attacks){
        delete attack;
    }
    attacks.clear();

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
}

void Creature::setVulnerability(std::string vulnerability) { 
    this->vulnerability = vulnerability;
}

void Creature::addAttack(Attack* attack) {
    attacks.push_back(attack);
}

void Creature::addCondition(Condition* condition) {
    conditions.push_back(condition);
}

void Creature::addTrigger(Trigger* trigger) {
    triggers.push_back(trigger);
}

std::string Creature::getName() {
    return name;
}

std::string Creature::getVulnerability() {
    return vulnerability;
}

std::vector<Attack*> Creature::getAttacks() {
    return attacks;
}

std::vector<Condition*> Creature::getConditions() {
    return conditions;
}

std::vector<Trigger*> Creature::getTriggers() {
    return triggers;
}