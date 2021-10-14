#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "XMLParser.h"

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
}