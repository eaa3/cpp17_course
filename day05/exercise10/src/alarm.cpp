#include <string>
#include <cstring>
#include "alarm.h"
#include "debug.h"


#define stringfy( name ) # name


Alarm::Alarm(Alarm::Category type) : type_(type) { 

    TRACELN("Alarm::ctor");
}

Alarm::Alarm(Category type, const char* description) : Alarm { type } {


    description_ = new char[ std::strlen(description)+1 ];

    strcpy(description_, description);

    TRACELN("Alarm::ctor(type,desc)");

} 

Alarm::Alarm(const Alarm& other) : Alarm {other.type(), other.what() } {

    static int counter = 0;

    TRACELN("Alarm::cpy_ctor => " << counter++);

}

Alarm::Alarm(Alarm&& other) noexcept : Alarm { } {

    swap(*this, other);

    TRACELN("Alarm::mv_ctor(other)");

}

Alarm::~Alarm(){
    TRACELN("Alarm::dctor");

    delete [] description_;
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

const char* Alarm::what() const {

    return description_;

}




Alarm& Alarm::operator=(Alarm rhs){

    swap(*this, rhs);

    TRACELN("Alarm::op=");

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Alarm& alarm)
{
    os << alarm.as_string() << " desc: " << alarm.what();
    return os;
}

void swap(Alarm& rhs, Alarm& lhs){
    using std::swap;

    swap(lhs.type_, rhs.type_);
    swap(lhs.description_, rhs.description_);

}
