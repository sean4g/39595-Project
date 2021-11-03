#pragma once
#include <string>
#include <vector>

class Turnon {
private:
    std::string print;
    std::vector<std::string> actions;

public:
    Turnon();
    virtual ~Turnon();

    void setPrint(std::string object);
    void addAction(std::string action);


    std::string getPrint();
    std::vector<std::string>& getActions();
};