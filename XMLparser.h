#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "Map.h"
#include "Border.h"
#include "Condition.h"
#include "Trigger.h"
#include "Turnon.h"
#include "Creature.h"
#include "Container.h"
#include "Item.h"
#include "Attack.h"
#include "tinyxml.h"

class XMLparser {
private:
    Room* parseRoom(TiXmlElement* element, Map* map);
    Item* parseItem(TiXmlElement* element, Map* map);
    Border* parseBorder(TiXmlElement* element, Map* map);
    Creature* parseCreature(TiXmlElement* element, Map* map);
    Container* parseContainer(TiXmlElement* element, Map* map);

    Turnon* parseTurnOn(TiXmlElement* element);
    Condition* parseCondition(TiXmlElement* element);
    Trigger* parseTrigger(TiXmlElement* element);
    Attack* parseAttack(TiXmlElement* element);

public:
    Map* parseXML(std::string filename);

};