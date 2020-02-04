
all:
	g++ -std=c++17 -Wall -Wextra -ffunction-sections -fdata-sections -Og -g -o user_def_types user_def_types.cpp

dump: user_def_types
	objdump -h cpp17_example > objdump.txt

nmdump: user_def_types
	nm -n user_def_types  
#> objdump.txt

clean:
	rm user_def_types objdump.txt 2> /dev/null 