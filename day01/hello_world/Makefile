
all: cpp17_example

cpp17_example:
	g++ -std=c++17 -Wall -Wextra -ffunction-sections -fdata-sections -Og -g -o cpp17_example cpp17_example.cpp

dump: cpp17_example
	objdump -h cpp17_example > objdump.txt

nmdump: cpp17_example
	nm -n cpp17_example  
#> objdump.txt

clean:
	rm cpp17_example objdump.txt