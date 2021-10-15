#pragma once
#include <string>
#include <vector>
#include "Trigger.h"
#include "Condition.h"
#include "Item.h"

class Container {
private:
    std::string name;
    std::string status;
    std::string accept;

    std::vector<Item*> items;
    std::vector<Condition*> conditions;
    std::vector<Trigger*> triggers;
public:
    Container();
    virtual ~Container();

    void setName(std::string name);  
    void setStatus(std::string status);
    void setAccept(std::string accept);

    void addItem(Item* item);
    void addCondition(Condition* condition);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::string getStatus();
    std::string getAccept();

    std::vector<Item*> getItems();
    std::vector<Condition*> getConditions();
    std::vector<Trigger*> getTriggers();
};