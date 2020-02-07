#include <iostream>
#include <functional>
#include "debug.h"

class ADT {

public:

    void test() {
        std::cout << "What is that? " << std::endl;
    }

    int var { 0 };
};

int main(){


    std::function<int(int)> my_func = [](int i) { return i + 1; };

    auto func2 = [](ADT& elem) { elem.var = 99;
                                 return elem.var; };


    int total { };
    auto fn = [&output = total, i = 10](int new_val) mutable {
                output += new_val;
                ++i;
                TRACELN(i);
    };

    fn(10);
    fn(20);
    fn(30);

    TRACELN("Total: " << total);

    ADT adt { };
    TRACELN("Look::func2 => " << func2(adt));


    TRACELN("Look: " << my_func(10));
    
    return 0;
}