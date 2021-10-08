#include <string>
#include <vector>
#include "Condition.h"

class Trigger {
private:
    std::string type;
    std::string command;
    std::string print;
    std::string action;

    Condition* condition;
public:
    Trigger();
    virtual ~Trigger();

    void setType(std::string type);
    void setCommand(std::string command);
    void setPrint(std::string print);
    void setAction(std::string action);

    void setCondition(Condition* condition);

    std::string getType();
    std::string getCommand();
    std::string getPrint();
    std::string getAction();

    Condition* getCondition();
}