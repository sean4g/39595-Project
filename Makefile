EXECUTABLE=XMLParseDemo

CC=g++

CFLAGS=-g -std=c++11 -Wall -Werror -DTIXML_USE_STL

CLASSES=tinystr.cpp tinyxml.cpp Attack.cpp Border.cpp Condition.cpp Container.cpp Creature.cpp Item.cpp Map.cpp Room.cpp Trigger.cpp Turnon.cpp XMLparser.cpp

SOURCES=main.cpp $(CLASSES) tinyxmlerror.cpp tinyxmlparser.cpp

OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(CLASSES:.cpp=.h)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

rebuild: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe

.PHONY: run clean rebuild