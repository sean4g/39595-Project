#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <sstream>
#include "Map.h"
#include "XMLparser.h"
#include "Player.h"
#include "Dungeon.h"

std::vector<std::string> getWords() {
	std::string value;
	std::vector<std::string> values;

	getline(std::cin, value);

	std::stringstream check1(value);
	std::string intermediate;

	while(getline(check1, intermediate, ' ')) {
		values.push_back(intermediate);
	}

	return values;
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
		commands = getWords();

		if (commands[0] == "i") {
			player.printInventory();
		}
		else if (commands[0] == "q") {
			std::cout << "Quitting game..." << std::endl; 
			break;
		}
		else if (commands[0] == "l") {
			player.lookRoom();
		}
		else if (commands[0] == "n" || commands[0] == "s" || commands[0] == "e" || commands[0] == "w")
		{
			player.moveRoom(commands[0], map);
		}
		else if (commands[0] == "take") {
			take = commands[1];
			//std::cout << command << std::endl;
			player.addItem(take);
			
		}
		else if (commands[0] == "drop") {
			drop = commands[1];
			player.dropItem(drop);
		}
		else if (commands[0] == "open") {
			std::string container = commands[1];
			player.openContainer(container);
		}
		else if (commands[0] == "put") {
			std::string item1 = commands[1];
			std::string container = commands[3];
			player.putContainer(container, item1);
		}
		else if (commands[0] == "read") {
			std::string item1 = commands[1];
			player.readItem(item1);
		}
		else {
			std::cout << "This command is not understood." << std::endl;
			continue;
		}
	}

	delete map;
	return 0;
}

