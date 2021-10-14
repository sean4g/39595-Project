# Name of the output EXE file
EXECUTABLE=XMLParseDemo

# Compiler to use
CC=g++
# Additional C flags, note that defining TIXML_USE_STL lets us use std::string instead of char* for interacting with TinyXML
CFLAGS=-g -std=c++11 -Wall -Werror -DTIXML_USE_STL

# Any source files with a same named header file
CLASSES=tinystr.cpp tinyxml.cpp Attack.cpp Border.cpp Condition.cpp Container.cpp Creature.cpp Item.cpp Map.cpp Room.cpp Trigger.cpp Turnon.cpp XMLparser.cpp
#  Source files that have no header file are just included here
SOURCES=main.cpp $(CLASSES) tinyxmlerror.cpp tinyxmlparser.cpp
# All cpp files produce a o file
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(CLASSES:.cpp=.h)

# Check if building on Windows or Linux for the clean and zip command
# For most machines you can just directly use the proper command, but this was done to make the file more portable
ifeq ($(OS),Windows_NT)
	# by running rm within cmd, it does not error on missing files
	RM=cmd /c del
	# Windows introduced the tar command that can make zip files
	ZIP=tar -acvf
else
	# running -f means it does not error on missing files
	RM=rm -f
	# Linux needs the zip command to do zip files
	ZIP=zip
endif

# Builds then runs the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# cleans existing build files then builds
rebuild: clean $(EXECUTABLE)

# Compiles the EXE using all source files
$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS)

# general .cpp to .o rule
.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Cleans all build files
clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe
	$(RM) $(ZIPNAME)

.PHONY: run clean rebuild