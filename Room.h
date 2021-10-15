#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include "Border.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"

class Room {
private:
    std::string name;
    std::string description;
    std::string type;

    std::vector<Item*> items;
    std::vector<Border*> borders;
    std::vector<Container*> containers;
    std::vector<Creature*> creatures;
    std::vector<Trigger*> triggers;
public:
    Room();
    virtual ~Room();

    void setName(std::string name);
    void setDescription(std::string description);
    void setType(std::string type);

    void addItem(Item* item);
    void addBorder(Border* border);
    void addContainer(Container* container);
    void addCreature(Creature* creature);
    void addTrigger(Trigger* trigger);

    std::string getName();
    std::string getDescription();
    std::string getType();

    std::vector<Item*> getItems();
    std::vector<Border*> getBorders();
    std::vector<Container*> getContainers();
    std::vector<Creature*> getCreatures();
    std::vector<Trigger*> getTriggers();
};