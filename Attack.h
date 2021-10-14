#include <string>
#include <vector>
#include "Condition.h"

class Attack {
private:
    std::string print;
    std::string action;

    Condition* condition;
public:
    Attack();
    virtual ~Attack();

    void setPrint(std::string print);
    void setAction(std::string action);

    void setCondition(Condition* condition);

    std::string getPrint();
    std::string getAction();

    Condition* getCondition();
}