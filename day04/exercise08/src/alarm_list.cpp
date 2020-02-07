#include "alarm_list.h"



void Alarm_list::add(Alarm& in_val){

    BaseType::push_back(in_val);

}

void Alarm_list::emplace(Alarm::Category type){

    BaseType::emplace_back(type);


}

void Alarm_list::emplace(Alarm::Category type, const char* description){

    BaseType::emplace_back(type, description);


}

