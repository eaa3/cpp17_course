#ifndef __ALARM__
#define __ALARM__

#include <ostream>
#include <iostream>



class Alarm {

public:

    enum Category {
        invalid,
        advisory,
        caution,
        warning,
        num_categories
    };

    Alarm() = default;
    Alarm(Category type);
    Alarm(const Alarm& other);

    ~Alarm();

    Category type()     const;
    const char* as_string() const;


    Alarm& operator=(const Alarm& rhs);
    
private:

    Category type_{ Category::invalid };
    

}; // Alarm class


std::ostream& operator<<(std::ostream& os, const Alarm& alarm);

#endif // __ALARM__