#include <string>
#include <vector>
#include "Attack.h"
#include "Condition.h"
#include "Trigger.h"

class Creature {
private:
    std::string name;
    std::string vulnerability;


    std::vector<Attack*> attacks;
    std::vector<Condition*> conditions;
    std::vector<Trigger*> triggers;

public:
    Creature();
    virtual ~Creature();

    void setName(std::string name);
    void setVulnerability(std::string vulnerability);

    void addAttack(Attack* attack);
    void addCondition(Condition* condition);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::string getVulnerability();

    std::vector<Attack*> getAttacks();
    std::vector<Condition*> getConditions();
    std::vector<Trigger*> getTriggers();
};