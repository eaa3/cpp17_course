#include <string>
#include "alarm.h"
#include "debug.h"


#define stringfy( name ) # name


Alarm::Alarm(Alarm::Category type) : type_(type) { 

    TRACELN("Alarm::ctor");
}

Alarm::Alarm(const Alarm& other) : type_(other.type()) {

    TRACELN("Alarm::cpy_ctor");

}

Alarm::~Alarm(){
    TRACELN("Alarm::dctor");
}


Alarm::Category Alarm::type() const {

    return type_;
}


const char* Alarm::as_string() const {

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


Alarm& Alarm::operator=(const Alarm& rhs){

    this->type_ = rhs.type();

    TRACELN("Alarm::op==");

    return *this;
}
