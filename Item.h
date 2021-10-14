#include <string>
#include <vector>
#include "Turnon.h"

class Item {
private:
    std::string name;
    std::string writing;
    std::string status;

    Turnon* turnon;
public:
    Item();
    virtual ~Item();

    void setName(std::string name);
    void setWriting(std::string writing);
    void setStatus(std::string status);

    void setTurnon(Turnon* Turnon);

    std::string getName();
    std::string getWriting();
    std::string getStatus();

    Turnon* getTurnon();
};