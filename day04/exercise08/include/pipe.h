#ifndef __PIPE__
#define __PIPE__


#include <optional>
#include "alarm_list.h"


class Pipe {

public:


    using elem_type = Alarm_list;


    Pipe() = default;


    void push(const elem_type& in);
    void push(elem_type&& in);
    elem_type pull();

    bool is_empty() const;

    

private:


    std::optional<elem_type> elem_ { };


    

}; // Pipe class




#endif // __PIPE__