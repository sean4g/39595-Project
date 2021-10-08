#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"

class Map {
private:
    std::vector<Room*> rooms;
    std::vector<Item*> items;
    std::vector<Container*> containers;
    std::vector<Creature*> creatures;

public:
    Map();
    ~Map();
    
    void addRoom(Room* room);
    void addItem(Item* item;
    void addContainer(Container* container);
    void addCreature(Creature* creature);

    std::vector<Room*> getRooms();
    std::vector<Item*> getItems();
    std::vector<Container*> getContainers();
    std::vector<Creature*> getCreatures();
}