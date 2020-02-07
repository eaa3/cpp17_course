INCLUDE_DIR = include/
COMPILE_ARGS = -std=c++17 -Wall -Wextra -ffunction-sections -fdata-sections -Og -g -D TRACE_ENABLED 
SRC_FILES = src/*.cpp 

#

all:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o exercise08 $(SRC_FILES) exercise08.cpp

example:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o example_functional $(SRC_FILES) example_functional.cpp


run: exercise08
	./exercise08


clean:
	rm exercise08