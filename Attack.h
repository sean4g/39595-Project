#pragma once
#include <string>
#include <vector>
#include "Condition.h"

class Attack {
private:
    std::string print;
    std::vector<std::string> actions;

    std::vector<Condition*> conditions;
public:
    Attack();
    virtual ~Attack();

    void setPrint(std::string print);
    void addAction(std::string action);

    void addCondition(Condition* condition);

    std::string getPrint();
    std::vector<std::string>& getActions();

    std::vector<Condition*>& getConditions();
};