#include <string>
#include <vector>

class Condition {
private:
    std::string object;
    std::string status;
    std::string owner;
    bool has;

public:
    Condition();
    virtual ~Condition();

    void setObject(std::string object);
    void setStatus(std::string status);
    void setOwner(std::string owner);
    void setHas(bool has);

    std::string getObject();
    std::string getStatus();
    std::string getOwner();
    bool getHas();
}