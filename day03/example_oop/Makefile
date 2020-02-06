INCLUDE_DIR = ./
COMPILE_ARGS = -std=c++17 -Wall -Wextra -ffunction-sections -fdata-sections -Og -g -D TRACE_ENABLED
SRC_FILES = ./*.cpp

all:
	g++ $(COMPILE_ARGS) -I$(INCLUDE_DIR) -o test $(SRC_FILES)

run: test
	./test


clean:
	rm test