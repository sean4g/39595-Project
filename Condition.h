#include <string>
#include <vector>

class Condition {
private:
    std::string object;
    std::string status;
    std::string owner;
    std::string has;

public:
    Condition();
    virtual ~Condition();

    void setObject(std::string object);
    void setStatus(std::string status);
    void setOwner(std::string owner);
    void setHas(std::string has);

    std::string getObject();
    std::string getStatus();
    std::string getOwner();
    std::string getHas();
}