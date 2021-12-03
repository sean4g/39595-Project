#pragma once
#include <string>
#include <vector>
#include "Condition.h"

class Trigger {
private:
    std::string type;
    std::string command;
    std::vector<std::string> prints;
    std::vector<std::string> actions;

    std::vector<Condition*> conditions;
public:
    Trigger();
    virtual ~Trigger();

    void setType(std::string type);
    void setCommand(std::string command);
    void addPrint(std::string print);
    void addAction(std::string action);

    void addCondition(Condition* condition);

    std::string getType();
    std::string getCommand();
    std::vector<std::string>& getPrints();
    std::vector<std::string>& getActions();

    std::vector<Condition*>& getConditions();
};