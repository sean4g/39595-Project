#include "Player.h"
#include "helper.h"

Player::Player(Map *map, Dungeon* dungeon)
{
    std::cout << "Player created " << std::endl;
    status = " ";
    inventory.clear();
    currentRoom = map->findRoom("Entrance");
    this->map = map;
    this->dungeon = dungeon;
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
        if (i == currentRoom->getItems().size())
        {
            std::cout << "Item not in room." << std::endl;
            return;
        }
        if (currentRoom->getItems()[i]->getName() == item) 
        {
            inventory.push_back(currentRoom->getItems()[i]);
            currentRoom->getItems().erase(currentRoom->getItems().begin() + i);
            std::cout << "Item " << item << " added to the inventory." << std::endl;
            return;
        }
        i++;
    }

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

std::vector<Item *>& Player::getInventory()
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

void Player::openContainer(std::string container){
    std::vector<Container*> containers = currentRoom->getContainers();
    int i = 0;
    int size = containers.size();
    std::cout << size;
    for (i = 0; i < size; i++){
        std::cout << containers[i]->getName() << std::endl;
        if (containers[i]->getName() == container)
        {

            std::cout << container << " contains ";
            for (unsigned int j = 0; j < containers[i]->getItems().size(); j++){
                std::cout << containers[i]->getItems()[j]->getName() << std::endl;
            }
            for (unsigned int j = 0; j < containers[i]->getItems().size(); j++){
                currentRoom->addItem(containers[i]->getItems()[j]);
                containers[i]->getItems().erase(containers[i]->getItems().begin() + j);
            }
            return;
        }
    }

    if (i == size) 
    {
        std::cout << "Container not in room." << std::endl;
        return;
    }
}

void Player::putContainer(std::string container, std::string item){
    std::vector<Container*> containers = currentRoom->getContainers();
    Item* put;

    int i = 0;
    int j = 0;
    int size = containers.size();
    int invSize = inventory.size();

    for (; j < invSize; j++) {
        if (inventory[j]->getName() == item){
            //containers[i]->addItem(inventory[j]);
            put = inventory[j];
            inventory.erase(inventory.begin() + j);
            
            break;
        }
    }
    if (j == invSize) {
        std::cout << "Item not in inventory." << std::endl;
        return;         
    }
    //put item in room !!!!****@(*$@(*!$))
    for (i = 0; i < size; i++){
        std::cout << containers[i]->getName() << std::endl;
        if (containers[i]->getName() == container)
        {
            containers[i]->addItem(put);
            std::cout << "Put " << item << " in " << container << std::endl;
            return;
        }
    }
    if (i == size) 
    {
        std::cout << "Container not in room." << std::endl;
        return;
    }
}


void Player::readItem(std::string item) {
    int i = 0;
    int size = inventory.size();

    for (i = 0; i < size; i++){
        if (inventory[i]->getName() == item)
        {
            std::cout << inventory[i]->getWriting() << std::endl;
            return;
        }
    }
    if (i == size) 
    {
        std::cout << "Item not in invetory." << std::endl;
        return;
    }

}

void Player::checkTriggers() {
    int i = 0;
    Room* current = getCurrentRoom();
    int roomTrigs = current -> getTriggers().size();
    if (roomTrigs > 0) {
        for (;i < roomTrigs; i++) {
            if(checkCommand(current->getTriggers()[i])){
                continue;
            }
            if(current->getTriggers()[i]->getType() == "single") {
                if(current->getTriggers()[i]->getUsed() == false) {
                    int x = checkCondition(current->getTriggers()[i]);
                    if (x) {
                        executeTrigger(current->getTriggers()[i]);
                        current->getTriggers()[i]->setUsed(true);
                    }
                }
            }
            else if(current->getTriggers()[i]->getType() == "permanent"){
                if (checkCondition(current->getTriggers()[i])) {
                    executeTrigger(current->getTriggers()[i]);
                }
            }
        }
    }

    std::vector<Item*> items = current->getItems();
    for (unsigned int x1 = 0; x1 < items.size(); x1++ ){
        int itemTrigs = items[x1]->getTriggers().size();
        if (itemTrigs > 0) {
            for (int f = 0; f < itemTrigs; f++) {
                if(checkCommand(items[x1]->getTriggers()[f])){
                    continue;
                }
                if(items[x1]->getTriggers()[f]->getType() == "single") {
                    if(items[x1]->getTriggers()[f]->getUsed() == false) {
                        int check2 = checkCondition(items[x1]->getTriggers()[f]);
                        if (check2) {
                            executeTrigger(items[x1]->getTriggers()[f]);
                            items[x1]->getTriggers()[f]->setUsed(true);
                        }
                    }
                }
                else if (items[x1]->getTriggers()[f]->getType() == "permanent") {
                    int check2 = checkCondition(items[x1]->getTriggers()[f]);
                    if (check2) {
                        executeTrigger(items[x1]->getTriggers()[f]);
                    }
                }
            }
        }
    }

    std::vector<Container*> containers = current->getContainers();
    for (unsigned int y = 0; y < containers.size(); y++ ){
        int containerTrigs = containers[y]->getTriggers().size();
        if (containerTrigs > 0) {
            for (int s = 0; s < containerTrigs; s++) {
                if(checkCommand(containers[y]->getTriggers()[s])){
                    continue;
                }
                if(containers[y]->getTriggers()[s]->getType() == "single") {
                    if(containers[y]->getTriggers()[s]->getUsed() == false) {
                        int check3 = checkCondition(containers[y]->getTriggers()[s]);
                        if (check3) {
                            executeTrigger(containers[y]->getTriggers()[s]);
                            containers[y]->getTriggers()[s]->setUsed(true);
                        }
                    }
                }
                else if (containers[y]->getTriggers()[s]->getType() == "permanent") {
                    int check3 = checkCondition(containers[y]->getTriggers()[s]);
                    if (check3) {
                        executeTrigger(containers[y]->getTriggers()[s]);
                    }
                }
            }
        }
    }

    std::vector<Creature*> creatures = current->getCreatures();
    for (unsigned int z = 0; z < creatures.size(); z++ ){
        int creatureTrigs = creatures[z]->getTriggers().size();
        if (creatureTrigs > 0) {
            for (int ind = 0; ind < creatureTrigs; ind++) {
                if(checkCommand(creatures[z]->getTriggers()[ind])){
                    continue;
                }
                if(creatures[z]->getTriggers()[ind]->getType() == "single") {
                    if(creatures[z]->getTriggers()[ind]->getUsed() == false) {
                        int check4 = checkCondition(creatures[z]->getTriggers()[ind]);
                        if (check4) {
                            executeTrigger(creatures[z]->getTriggers()[ind]);
                            creatures[z]->getTriggers()[ind]->setUsed(true);
                        }
                    }
                }
                else if(creatures[z]->getTriggers()[ind]->getType() == "permanent"){
                    int check4 = checkCondition(creatures[z]->getTriggers()[ind]);
                    if (check4) {
                        executeTrigger(creatures[z]->getTriggers()[ind]);
                    }
                }
            }
        }
    }
}

void Player::executeTrigger(Trigger* trigger) {
    if (trigger->getPrints().size() > 0) {
        for (unsigned int i = 0; i < trigger->getPrints().size(); i++){
            std::cout << trigger->getPrints()[i] << std::endl;
        }
    }
    if (trigger->getActions().size() > 0) {
        for (unsigned int i = 0; i < trigger->getActions().size(); i++){
            executeAction(trigger->getActions()[i]);
        }
    }
}

void Player::executeAction(std::string action) {
    std::stringstream check1(action);
    std::vector<std::string> commands;
	std::string intermediate;

	while(getline(check1, intermediate, ' ')) {
		commands.push_back(intermediate);
	}
		if (commands[0] == "take") {
			std::string take = commands[1];
			addItem(take);
		}
		else if (commands[0] == "drop") {
			std::string drop = commands[1];
			dropItem(drop);
		}
        else if (commands[0] == "Game Over") {
            dungeon->setGameOver(true);
        }
        else if (commands[0] == "Update") {
            std::string object = commands[1];
            std::string status = commands[3];
            updateObject(object, status);
        }
}

void Player::updateObject(std::string object, std::string status) {
    Container* container = map->findContainerN(object);
    Item* item = map->findItemN(object);

    if (container == nullptr) {
        item->setStatus(status);
    }
    else if (item == nullptr) {
        container->setStatus(status);
    }

}

void Player::turnOnItem(std::string item) {
    int i = 0;
    int size = inventory.size();
    for(; i < size; i++) {
        if (inventory[i]->getName() == item){
            Item* turned = inventory[i];
            Turnon* turnon = turned->getTurnon();
            std::cout << turnon->getPrint() << std::endl;
            if (turnon->getActions().size() > 0) {
                for (unsigned int j = 0; j < turnon->getActions().size(); j++){
                    executeAction(turnon->getActions()[i]);
                }
            }
            return;
        }
    }

    if (i == size) {
        std::cout << "Item not in inventory." << std::endl;
        return;
    }
}

int Player::checkCondition(Trigger* trigger) {
    std::vector<Condition*> conditions = trigger->getConditions();
    int size = conditions.size();
    unsigned int ind = 0;
    unsigned int ind1 = 0;
    int i = 0;
    for(;i < size; i++){
        std::string object = conditions[i]->getObject();
        Container* objCont = map->findContainerN(object);
        Item* objItem = map->findItemN(object);

        if (conditions[i]->getHas() == "") {
            std::string status = conditions[i]->getStatus();
            if (objCont == nullptr && objItem == nullptr) {
                std::cout << "Error" << std::endl;
            }
            else if (objCont == nullptr) {
                if (objItem->getStatus() == status) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else if (objItem == nullptr){
                if (objCont->getStatus() == status) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        else if (conditions[i]->getHas() == "yes") {
            if (conditions[i]->getOwner() == "inventory") {
                for(ind = 0; ind < inventory.size(); ind++){
                    if (inventory[ind] == objItem){
                        return 1;
                    }
                }
                if (ind == inventory.size()) {
                    return 0;
                }
            }
            else {
                Container* ownerCont = map->findContainerN(conditions[i]->getOwner());
                for(ind1 = 0; ind1 < ownerCont->getItems().size(); ind1++){
                    if (ownerCont->getItems()[ind] == objItem){
                        return 1;
                    }
                }
                if (ind1 == ownerCont->getItems().size()) {
                    return 0;
                }
            }
        }
        else if (conditions[i]->getHas() == "no"){
            if (conditions[i]->getOwner() == "inventory") {
                for(ind = 0; ind < inventory.size(); ind++){
                    if (inventory[ind] == objItem){
                        return 0;
                    }
                }
                if (ind == inventory.size()) {
                    return 1;
                }
            }
            else {
                Container* ownerCont = map->findContainerN(conditions[i]->getOwner());
                for(ind1 = 0; ind1 < ownerCont->getItems().size(); ind1++){
                    if (ownerCont->getItems()[ind] == objItem){
                        return 0;
                    }
                }
                if (ind1 == ownerCont->getItems().size()) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int Player::checkTrigCommand(std::string command) {
    int i = 0;
    Room* current = getCurrentRoom();
    int roomTrigs = current -> getTriggers().size();
    if (roomTrigs > 0) {
        for (;i < roomTrigs; i++) {
            if (current->getTriggers()[i]->getType() == "single"){
                if (current->getTriggers()[i]->getUsed() == false){
                    if(checkCommand(current->getTriggers()[i])){
                        if(current->getTriggers()[i]->getCommand() != command){
                            continue;
                        }
                        int x = checkCondition(current->getTriggers()[i]);
                        if (x) {
                            executeTrigger(current->getTriggers()[i]);
                            current->getTriggers()[i]->setUsed(true);
                            return 1;
                        }
                    }
                }
            } else if (current->getTriggers()[i]->getType() == "permanent") {
                if(checkCommand(current->getTriggers()[i])){
                    if(current->getTriggers()[i]->getCommand() != command){
                        continue;
                    }
                    int x = checkCondition(current->getTriggers()[i]);
                    if (x) {
                        executeTrigger(current->getTriggers()[i]);
                        return 1;
                    }
                }
            }
        }
    }

    std::vector<Item*> items = current->getItems();
    for (unsigned int x1 = 0; x1 < items.size(); x1++ ){
        int itemTrigs = items[x1]->getTriggers().size();
        if (itemTrigs > 0) {
            for (int f = 0; f < itemTrigs; f++) {
                if (items[x1]->getTriggers()[f]->getType() == "single"){
                    if (items[x1]->getTriggers()[f]->getUsed() == false){
                        if(checkCommand(items[x1]->getTriggers()[f])){
                            if(items[x1]->getTriggers()[f]->getCommand() != command){
                                continue;
                            }
                            int check2 = checkCondition(items[x1]->getTriggers()[f]);
                            if (check2) {
                                executeTrigger(items[x1]->getTriggers()[f]);
                                items[x1]->getTriggers()[f]->setUsed(true);
                                return 1;
                            }
                        }
                    }
                } else if (items[x1]->getTriggers()[f]->getType() == "permanent") {                
                    if(checkCommand(items[x1]->getTriggers()[f])){
                        if(items[x1]->getTriggers()[f]->getCommand() != command){
                            continue;
                        }
                        int check2 = checkCondition(items[x1]->getTriggers()[f]);
                        if (check2) {
                            executeTrigger(items[x1]->getTriggers()[f]);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    std::vector<Container*> containers = current->getContainers();
    for (unsigned int y = 0; y < containers.size(); y++ ){
        int containerTrigs = containers[y]->getTriggers().size();
        if (containerTrigs > 0) {
            for (int s = 0; s < containerTrigs; s++) {
                if (containers[y]->getTriggers()[s]->getType() == "single"){
                    if (containers[y]->getTriggers()[s]->getUsed() == false){
                        if(checkCommand(containers[y]->getTriggers()[s])){
                            if(containers[y]->getTriggers()[s]->getCommand() != command){
                                continue;
                            }
                            int check3 = checkCondition(containers[y]->getTriggers()[s]);
                            if (check3) {
                                executeTrigger(containers[y]->getTriggers()[s]);
                                containers[y]->getTriggers()[s]->setUsed(true);
                                return 1;
                            }
                        }
                    }
                } else if (containers[y]->getTriggers()[s]->getType() == "permanent") {
                    if(checkCommand(containers[y]->getTriggers()[s])){
                        if(containers[y]->getTriggers()[s]->getCommand() != command){
                            continue;
                        }
                        int check3 = checkCondition(containers[y]->getTriggers()[s]);
                        if (check3) {
                            executeTrigger(containers[y]->getTriggers()[s]);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    std::vector<Creature*> creatures = current->getCreatures();
    for (unsigned int z = 0; z < creatures.size(); z++ ){
        int creatureTrigs = creatures[z]->getTriggers().size();
        if (creatureTrigs > 0) {
            for (int ind = 0; ind < creatureTrigs; ind++) {
                if (creatures[z]->getTriggers()[ind]->getType() == "single"){
                    if (creatures[z]->getTriggers()[ind]->getUsed() == false){
                        if(checkCommand(creatures[z]->getTriggers()[ind])){
                            if(creatures[z]->getTriggers()[ind]->getCommand() != command){
                                continue;
                            }
                            int check4 = checkCondition(creatures[z]->getTriggers()[ind]);
                            if (check4) {
                                executeTrigger(creatures[z]->getTriggers()[ind]);
                                creatures[z]->getTriggers()[ind]->setUsed(true);
                                return 1;
                            }
                        }
                    }
                } else if (creatures[z]->getTriggers()[ind]->getType() == "permanent") {
                    if(checkCommand(creatures[z]->getTriggers()[ind])){
                        if(creatures[z]->getTriggers()[ind]->getCommand() != command){
                            continue;
                        }
                        int check4 = checkCondition(creatures[z]->getTriggers()[ind]);
                        if (check4) {
                            executeTrigger(creatures[z]->getTriggers()[ind]);
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}