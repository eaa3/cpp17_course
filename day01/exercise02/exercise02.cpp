#include <iostream>
#include "alarm.h"



int main(){

    Alarm a1 { };
    Alarm a2 { Alarm::Category::caution };

    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;


    return 0;
}