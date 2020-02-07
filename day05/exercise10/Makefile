INCLUDE_DIR = include/
COMPILE_ARGS = -std=c++17 -Wall -Wextra -ffunction-sections -fdata-sections -Og -g -D TRACE_ENABLED 
SRC_FILES = src/*.cpp 

#

all:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o exercise10 $(SRC_FILES) exercise10.cpp

test:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o test $(SRC_FILES) test.cpp

crp:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o crp $(SRC_FILES) crp.cpp


run: exercise10
	./exercise10


clean:
	rm exercise10