#pragma once
#include <iostream>

class Dungeon {
private:
    bool gameOver;
public:
    Dungeon();
    ~Dungeon();
    void setGameOver(bool gameOver);
    bool getGameOver();
};