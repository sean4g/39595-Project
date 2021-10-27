EXECUTABLE=XMLParseDemo

CC=g++

CFLAGS=-g -std=c++11 -Wall -Werror -DTIXML_USE_STL

OBJECTS=tinystr.o tinyxml.o Attack.o Border.o Condition.o Container.o Creature.o Item.o Map.o Room.o Trigger.o Turnon.o XMLparser.o main.o tinyxmlerror.o tinyxmlparser.o Dungeon.o Player.o


run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)

.PHONY: run clean