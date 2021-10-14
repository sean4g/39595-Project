#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "XMLparser.h"
#include "tinyxml.h"

Trigger* XMLparser::parseTrigger(TiXmlElement* element) {

    Trigger* trigger = new Trigger();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "type") {
                trigger->setType(value);
            }
            else if (name == "command") {
                trigger->setCommand(value);
            }   
            else if (name == "print") {
                trigger->setPrint(value);
            }
            else if (name == "action") {
                trigger->setAction(value);
            }
            else if (name == "condition") {
                trigger->setCondition(parseCondition(childElement));
            }
        }
    }
    return trigger;
}

Condition* XMLparser::parseCondition(TiXmlElement* element) {

    Condition* condition = new Condition();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "object") {
                condition->setObject(value);
            }
            else if (name == "status") {
                condition->setStatus(value);
            }
            else if (name == "owner") {
                condition->setOwner(value);
            }
            else if (name == "has") {
                condition->setHas(value);
            }
        }
    }
    return condition;
}

Turnon* XMLparser::parseTurnOn(TiXmlElement* element) {

    Turnon* turnOn = new Turnon();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "print") {
                turnOn->setPrint(value);
            }
            else if (name == "action") {
                turnOn->setAction(value);
            }
        }
    }
    return turnOn;
}

Attack* XMLparser::parseAttack(TiXmlElement* element) {

    Attack* attack = new Attack();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "condition") {
                attack->setCondition(parseCondition(childElement));
            }
            else if (name == "action") {
                attack->setAction(value);
            }
            else if (name == "print") {
                attack->setPrint(value);
            }
        }
    }
    return attack;
}

Room* XMLparser::parseRoom(TiXmlElement* element) {
    Room* room = new Room();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "name") {
                room->setName(value);
            }
            else if (name == "description") {
                room->setDescription(value);
            }
            else if (name == "type") {
                room->setType(value);
            }
            else if (name == "item") {
                //room->addItem(parseItem(childElement));
                Item* item = new Item();
                item->setName(value);
                room->addItem(item);
            }
            else if (name == "border") {
                room->addBorder(parseBorder(childElement));
            } 
            else if (name == "container") {
                //room->addContainer(parseItem(childElement));
                Container* container = new Container();
                container->setName(value);
                room->addContainer(container);
            }   
            else if (name == "Creature") {
                //room->addCreature(parseItem(childElement));
                Creature* creature = new Creature();
                creature->setName(value);
                room->addCreature(creature);
            }   
            else if (name == "Trigger") {
                room->addTrigger(parseTrigger(childElement));
            }             
        }
    }
        return room;
}

Item* XMLparser::parseItem(TiXmlElement* element) {
    Item* item = new Item();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "name") {
                item->setName(value);
            }
            else if (name == "writing") {
                item->setWriting(value);
            }
            else if (name == "status") {
                item->setStatus(value);
            }
            else if (name == "turnon") {
                item->setTurnon(parseTurnOn(childElement));
            }
        }
    }
    return item;
}

Border* XMLparser::parseBorder(TiXmlElement* element) {
    Border* border = new Border();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "name") {
                border->setName(value);
            }
            else if (name == "direction") {
                border->setDirection(value);
            }
        }
    }
    return border;
}

Creature* XMLparser::parseCreature(TiXmlElement* element) {
    Creature* creature = new Creature();

    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "name") {
                creature->setName(value);
            }
            else if (name == "vulnerability") {
                creature->setVulnerability(value);
            }
            else if (name == "attack") {
                creature->addAttack(parseAttack(childElement));
            }
            else if (name == "trigger") {
                creature->addTrigger(parseTrigger(childElement));
            }
        }
    }
    return creature;
}

Container* XMLparser::parseContainer(TiXmlElement* element) {
    Container* container = new Container();
    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "name") {
                container->setName(value);
            }
            else if (name == "status") {
                container->setStatus(value);
            }
            else if (name == "accept") {
                container->setAccept(value);
            }
            else if (name == "trigger") {
                container->addTrigger(parseTrigger(childElement));
            }
            else if (name == "condition") {
                container->addCondition(parseCondition(childElement));
            }
            else if (name == "item") {
                Item* item = new Item();
                item->setName(value);
                container->setItem(item);
            }
        }
    }
    return container;
}

Map* XMLparser::parseXML(std::string filename) {
	TiXmlDocument doc(filename);
	doc.LoadFile();

    Map* map = new Map();

	TiXmlElement* rootElement = doc.RootElement();
	if (rootElement == NULL) {
		std::cerr << "Invalid XML file, contains no data" << std::endl;
		return map;
	}
	if (rootElement->ValueStr() != "Map") {
		std::cerr << "Invalid XML file, should start with a Students array" << std::endl;
		return map;
	}
	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            std::string value = childElement->GetText();
            if (name == "room") {
                map->addRoom(parseRoom(childElement));
            }
            else if (name == "item") {
                map->addItem(parseItem(childElement));
            }
            else if (name == "container") {
                map->addContainer(parseContainer(childElement));
            }
            else if (name == "creature") {
                map->addCreature(parseCreature(childElement));
            }
        }
    }
    return map;
}

