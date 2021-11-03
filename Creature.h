#pragma once
#include <string>
#include <vector>
#include "Attack.h"
#include "Condition.h"
#include "Trigger.h"

class Creature {
private:
    std::string name;
    std::vector<std::string> vulnerabilities;


    Attack* attack;
    std::vector<Condition*> conditions;
    std::vector<Trigger*> triggers;

public:
    Creature();
    virtual ~Creature();

    void setName(std::string name);
    void addVulnerability(std::string vulnerability);

    void setAttack(Attack* attack);
    void addCondition(Condition* condition);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::vector<std::string>& getVulnerabilities();

    Attack* getAttack();
    std::vector<Condition*>& getConditions();
    std::vector<Trigger*>& getTriggers();
};