#include "Player.h"

Player::Player(Map* map) {
    std::cout << "Player created " << std::endl;
    status = " ";
    inventory.clear();
    currentRoom = map->findRoom("Entrance");
}

Player::~Player() {
}

void Player::setStatus(std::string status) {
    this->status = status;
}

void Player::setRoom(Room* room) {
    currentRoom = room;
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
    std::cout << "Item " << item->getName() << " added to the inventory." << std::endl;
}

std::string Player::getStatus() {
    return status;
}

Room* Player::getCurrentRoom() {
    return currentRoom;
}

std::vector<Item*> Player::getInventory() {
    return inventory;
}

void Player::printInventory() {
    if(inventory.size() != 0) {
        std::cout << "Inventory: " << std::endl;
        for (Item* item : inventory) {
            std::cout << item->getName() << std::endl;
        }
    }
    else {
        std::cout << "Inventory: empty" << std::endl;
    }
}