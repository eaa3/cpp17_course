#include "alarm.h"
#include <string>

#define stringfy( name ) # name


Alarm::Alarm(Alarm::Category type) : type_(type) { 
    // std::cout << "Non-default constructor" << std::endl; 
    
}

Alarm::~Alarm(){
    // std::cout << "Calling destructor" << std::endl;
}


Alarm::Category Alarm::type() const {

    return type_;
}


const char* Alarm::as_string() const {

    //std::cout << typeid(type_).name() << std::endl;

    switch(type_){
        case Category::advisory:
            return stringfy(Category::advisory);
        case Category::caution:
            return stringfy(Category::caution);
        case Category::warning:
            return stringfy(Category::warning);
        default:
            return stringfy(Category::invalid);

    }
}

std::ostream& operator<<(std::ostream& os, const Alarm& alarm)
{
    os << alarm.as_string();
    return os;
}
