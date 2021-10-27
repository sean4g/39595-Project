#include "Dungeon.h"

Dungeon::Dungeon(){
    gameOver = false;
}

Dungeon::~Dungeon(){
}

void Dungeon::setGameOver(bool gameOver){
    this->gameOver = gameOver;
}

bool Dungeon::getGameOver() {
    return gameOver;
}
