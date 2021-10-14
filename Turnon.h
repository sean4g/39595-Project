#include <string>
#include <vector>

class Turnon {
private:
    std::string print;
    std::string action;

public:
    Turnon();
    virtual ~Turnon();

    void setPrint(std::string object);
    void setAction(std::string status);


    std::string getPrint();
    std::string getAction();
}