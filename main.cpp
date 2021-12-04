#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include "Map.h"
#include "XMLparser.h"
#include "Player.h"
#include "Dungeon.h"

std::string getWords() {
	std::string value;
	std::vector<std::string> values;

	getline(std::cin, value);

	//std::cout << value << std::endl;
	//values.push_back(value);

	//std::cin >> value;
	//values.push_back(value);

	return value;
}

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
	if (map == NULL) {
		return 0;
	}

	Player player(map);
	Dungeon dungeon;
	std::string command;
	std::string take;
	std::string drop;
	//std::string value;
	std::vector<std::string> commands;
	//player.addItem(map->findItem("torch"));
	
	while (!dungeon.getGameOver()) {
		std::cout << "Type your command: ";
		std::string value = "";
		command = getWords();

		if (command == "i") {
			player.printInventory();
		}
		else if (command == "q") {
			std::cout << "Quitting game..." << std::endl; 
			break;
		}
		else if (command == "l") {
			player.lookRoom();
		}
		else if (command == "n" || command == "s" || command == "e" || command == "w")
		{
			player.moveRoom(command, map);
		}
		else if (command.substr(0,4) == "take") {
			take = command.substr(5);
			//std::cout << command << std::endl;
			player.addItem(take);
			
		}
		else if (command.substr(0,4) == "drop") {
			drop = command.substr(5);
			player.dropItem(drop);
		}
		else {
			std::cout << "This command is not understood." << std::endl;
			continue;
		}
	}

	delete map;
	return 0;
}

