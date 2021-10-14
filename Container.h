#include <string>
#include <vector>
#include "Trigger.h"
#include "Condition.h"

class Container {
private:
    std::string name;
    std::string item;
    std::string status;
    std::string accept;

    std::vector<Condition*> conditions;
    std::vector<Trigger*> triggers;
public:
    Container();
    virtual ~Container();

    void setName(std::string name);
    void setItem(std::string item);
    void setStatus(std::string status);
    void setAccept(std::string accept);

    void addCondition(Condition* condition);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::string getItem();
    std::string getStatus();
    std::string getAccept();

    std::vector<Condition*> getConditions();
    std::vector<Trigger*> getTriggers();
};