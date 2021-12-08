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
    std::vector<std::string> accepts;

    
    
    std::vector<Item*> items;
    std::vector<Condition*> conditions;
    std::vector<Trigger*> triggers;
public:
    Container();
    virtual ~Container();

    std::string open;

    void setName(std::string name);  
    void setStatus(std::string status);
    void addAccept(std::string accept);

    void addItem(Item* item);
    void addCondition(Condition* condition);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::string getStatus();
    std::vector<std::string> getAccepts();

    std::vector<Item*>& getItems();
    std::vector<Condition*>& getConditions();
    std::vector<Trigger*>& getTriggers();
};