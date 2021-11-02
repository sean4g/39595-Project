#include "Player.h"

Player::Player(Map *map)
{
    std::cout << "Player created " << std::endl;
    status = " ";
    inventory.clear();
    currentRoom = map->findRoom("Entrance");
}

Player::~Player()
{
}

void Player::setStatus(std::string status)
{
    this->status = status;
}

void Player::setRoom(Room *room)
{
    currentRoom = room;
}

void Player::addItem(std::string item)
{
    unsigned int i = 0;
    while (true)
    {
        
        std::cout << i;
        if (i == currentRoom->getItems().size())
        {
            std::cout << "Item not in room." << std::endl;
            return;
        }
        if (currentRoom->getItems()[i]->getName() == item) 
        {
            inventory.push_back(currentRoom->getItems()[i]);
            std::cout << currentRoom->getItems().size() << std::endl;
            currentRoom->getItems().erase(currentRoom->getItems().begin() + i);
            std::cout << currentRoom->getItems().size() << std::endl;
            std::cout << "Item " << item << " added to the inventory." << std::endl;
            return;
        }
        i++;
    }

    /*    for (Item* roomItem : roomItems) {
            if(roomItem->getName() == item) {
                inventory.push_back(roomItem);
                std::cout << roomItem << std::endl;
                delete roomItem;
                std::cout << roomItem->getName() << std::endl;
                std::cout << "Item " << item << " added to the inventory." << std::endl;
                break;
            }
            i++;
        }
    */

}

void Player::dropItem(std::string item)
{
    unsigned i = 0;
    int size = inventory.size();
    while (true)
    {
        if ((int)i == size)
        {
            std::cout << "Item not in inventory." << std::endl;
            return;
        }
        if (inventory[i]->getName() == item)
        {
            currentRoom->addItem(inventory[i]);
            inventory.erase(inventory.begin() + i);
            std::cout << "Dropped item " << item << std::endl;
            return;
        };
        i++;
    }
}

void Player::lookRoom()
{
    std::cout << "You are in " << currentRoom->getName() << "." << std::endl;
    std::cout << currentRoom->getDescription() << std::endl;
}

void Player::moveRoom(std::string direction, Map *map)
{
    unsigned i = 0;
    if (direction == "n")
    {
        while (true)
        {
            if (i == currentRoom->getBorders().size())
            {
                std::cout << "Cannot move that way!" << std::endl;
                return;
            }
            if (currentRoom->getBorders()[i]->getDirection() == "north")
            {
                std::cout << "Moved to " << currentRoom->getBorders()[i]->getName() << std::endl;
                setRoom(map->findRoom(currentRoom->getBorders()[i]->getName()));
                return;
            }
            i++;
        }
    }
    else if (direction == "s")
    {
        while (true)
        {
            if (i == currentRoom->getBorders().size())
            {
                std::cout << "Cannot move that way!" << std::endl;
                return;
            }
            if (currentRoom->getBorders()[i]->getDirection() == "south")
            {
                std::cout << "Moved to " << currentRoom->getBorders()[i]->getName() << std::endl;
                setRoom(map->findRoom(currentRoom->getBorders()[i]->getName()));
                return;
            }
            i++;
        }
    }
    else if (direction == "e")
    {
        while (true)
        {
            if (i == currentRoom->getBorders().size())
            {
                std::cout << "Cannot move that way!" << std::endl;
                return;
            }
            if (currentRoom->getBorders()[i]->getDirection() == "east")
            {
                std::cout << "Moved to " << currentRoom->getBorders()[i]->getName() << std::endl;
                setRoom(map->findRoom(currentRoom->getBorders()[i]->getName()));
                return;
            }
            i++;
        }
    }
    else if (direction == "w")
    {
        while (true)
        {
            if (i == currentRoom->getBorders().size())
            {
                std::cout << "Cannot move that way!" << std::endl;
                return;
            }
            if (currentRoom->getBorders()[i]->getDirection() == "west")
            {
                std::cout << "Moved to " << currentRoom->getBorders()[i]->getName() << std::endl;
                setRoom(map->findRoom(currentRoom->getBorders()[i]->getName()));
                return;
            }
            i++;
        }
    }
}

std::string Player::getStatus()
{
    return status;
}

Room *Player::getCurrentRoom()
{
    return currentRoom;
}

std::vector<Item *> Player::getInventory()
{
    return inventory;
}

void Player::printInventory()
{
    if (inventory.size() != 0)
    {
        std::cout << "Inventory: " << std::endl;
        for (Item *item : inventory)
        {
            std::cout << item->getName() << std::endl;
        }
    }
    else
    {
        std::cout << "Inventory: empty" << std::endl;
    }
}