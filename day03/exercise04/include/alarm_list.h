#ifndef __ALARM_LIST__
#define __ALARM_LIST__

#include <vector>
#include "alarm.h"

class Alarm_list : private std::vector<Alarm> {

public:
    using BaseType = std::vector<Alarm>;

    using BaseType::vector;

    using Iterator = Alarm_list::iterator;

    void add(Alarm& in_val);

    void emplace(Alarm::Category type);

    using BaseType::size;
    using BaseType::begin;
    using BaseType::end;
    using BaseType::erase;
    using BaseType::reserve;


    

}; // Alarm_list adapter class

#endif // __ALARM_LIST__