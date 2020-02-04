INCLUDE_DIR = include/
COMPILE_ARGS = -std=c++17 -Wall -Wextra -ffunction-sections -fdata-sections -Og -g
SRC_FILES = src/*.cpp ./*.cpp

all:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o exercise03 $(SRC_FILES)

run: exercise03
	./exercise03


clean:
	rm exercise02