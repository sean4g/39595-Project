#include <string>
#include <vector>
#include <iostream>
#include "XMLparser.h"
#include "tinyxml.h"

Trigger* XMLparser::parseTrigger(TiXmlElement* element) {

    Trigger* trigger = new Trigger();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling()) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            if (name == "type") {
                std::string value = childElement->GetText();
                trigger->setType(value);
            }
            else if (name == "command") {
                std::string value = childElement->GetText();
                trigger->setCommand(value);
            }   
            else if (name == "print") {
                std::string value = childElement->GetText();
                trigger->setPrint(value);
            }
            else if (name == "action") {
                std::string value = childElement->GetText();
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
            if (name == "condition") {
                attack->setCondition(parseCondition(childElement));
            }
            else if (name == "action") {
                std::string value = childElement->GetText();
                attack->addAction(value);
            }
            else if (name == "print") {
                std::string value = childElement->GetText();
                attack->setPrint(value);
            }
        }
    }
    return attack;
}

Room* XMLparser::parseRoom(TiXmlElement* element) {
    Room* room = new Room();

    for (TiXmlNode* node = element->FirstChild(); node != NULL; node = node->NextSibling()) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            if (name == "name") {
                std::string value = childElement->GetText();
                room->setName(value);
            }
            else if (name == "description") {
                std::string value = childElement->GetText();                
                room->setDescription(value);
            }
            else if (name == "type") {
                std::string value = childElement->GetText();  
                room->setType(value);
            }
            else if (name == "item") {
                //room->addItem(parseItem(childElement));
                std::string value = childElement->GetText();  
                Item* item = new Item();
                item->setName(value);
                room->addItem(item);
            }
            else if (name == "border") {
                room->addBorder(parseBorder(childElement));
            } 
            else if (name == "container") {
                //room->addContainer(parseItem(childElement));
                std::string value = childElement->GetText();  
                Container* container = new Container();
                container->setName(value);
                room->addContainer(container);
            }   
            else if (name == "creature") {
                //room->addCreature(parseItem(childElement));
                std::string value = childElement->GetText();  
                Creature* creature = new Creature();
                creature->setName(value);
                room->addCreature(creature);
            }   
            else if (name == "trigger") {
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
            
            if (name == "name") {
                std::string value = childElement->GetText();
                item->setName(value);
            }
            else if (name == "writing") {
                std::string value = childElement->GetText();
                item->setWriting(value);
            }
            else if (name == "status") {
                std::string value = childElement->GetText();
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
            if (name == "name") {
                std::string value = childElement->GetText();
                creature->setName(value);
            }
            else if (name == "vulnerability") {
                std::string value = childElement->GetText();
                creature->addVulnerability(value);
            }
            else if (name == "attack") {
                creature->setAttack(parseAttack(childElement));
            }
            else if (name == "trigger") {
                creature->addTrigger(parseTrigger(childElement));
            }
        }
    }
    return creature;
}

Container* XMLparser::parseContainer(TiXmlElement* element, Map* map) {
    Container* container = new Container();
    for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
        TiXmlElement* childElement = node->ToElement();
        if (childElement != NULL) {
            std::string name = childElement->ValueStr();
            if (name == "name") {
                std::string value = childElement->GetText();
                container->setName(value);
            }
            else if (name == "status") {
                std::string value = childElement->GetText();
                container->setStatus(value);
            }
            else if (name == "accept") {
                std::string value = childElement->GetText();
                container->addAccept(value);
            }
            else if (name == "trigger") {
                container->addTrigger(parseTrigger(childElement));
            }
            else if (name == "condition") {
                container->addCondition(parseCondition(childElement));
            }
            else if (name == "item") {
                std::string value = childElement->GetText();
                Item* item = new Item();
                map->itemMap.insert(std::pair<std::string, Item*>(value, item));
                item->setName(value);
                container->addItem(item);
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

    TiXmlNode* node = NULL;
    while ((node = rootElement->IterateChildren(node)) != NULL) {
        TiXmlElement* childElement = node->ToElement();
        std::string name = childElement->ValueStr();
        if (name == "room") {
            map->addRoom(parseRoom(childElement));
        }
        else if (name == "item") {
            map->addItem(parseItem(childElement));
        }
        else if (name == "container") {
            map->addContainer(parseContainer(childElement, map));
        }
        else if (name == "creature") {
            map->addCreature(parseCreature(childElement));
        }
    }

    return map;
}

