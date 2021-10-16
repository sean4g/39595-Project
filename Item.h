#pragma once
#include <string>
#include <vector>
#include "Turnon.h"
#include "Trigger.h"

class Item {
private:
    std::string name;
    std::string writing;
    std::string status;
    std::string description;

    Turnon* turnon;
    std::vector<Trigger*> triggers;
public:
    Item();
    virtual ~Item();

    void setName(std::string name);
    void setWriting(std::string writing);
    void setStatus(std::string status);
    void setDescription(std::string description);

    void setTurnon(Turnon* Turnon);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::string getWriting();
    std::string getStatus();
    std::string getDescription();

    Turnon* getTurnon();
    std::vector<Trigger*> getTriggers();

    bool operator==(Item* item) const {
        return item->name == name;
    }
};