#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "XMLparser.h"
#include "Player.h"
#include "Dungeon.h"

int main(int argc, char** args) {
    std::string filename;

    if (argc >= 2) {
		filename = args[1];
	}
	else {
		std::cout << "Enter filename: ";
		std::cin >> filename;
		std::cin.get();
	}

    XMLparser parser;
    Map* map = parser.parseXML(filename);

	Player player(map);
	Dungeon dungeon;
	std::string command;
	player.addItem(map->findItem("torch"));
	
	while (!dungeon.getGameOver()) {
		std::cout << "Type your command: ";
		std::cin >> command;
		if (command == "i" || command == "inventory") {
			player.printInventory();
		}
		if (command == "q") {
			std::cout << "Quitting game..." << std::endl; 
			break;
		}
	}

	//delete map;
}