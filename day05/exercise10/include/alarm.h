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
    Alarm(Category type, const char* description);
    Alarm(const Alarm& other);
    Alarm(Alarm&& other) noexcept;

    ~Alarm();

    Category type()     const;
    const char* as_string() const;
    const char* what() const;


    Alarm& operator=(Alarm rhs);

    friend std::ostream& operator<<(std::ostream& os, const Alarm& alarm);
    friend void swap(Alarm& rhs, Alarm& lhs);
    
    
private:

    Category type_{ Category::invalid };
    char* description_ { nullptr };
    

}; // Alarm class


// std::ostream& operator<<(std::ostream& os, const Alarm& alarm);
// void swap(Alarm& rhs, Alarm& lhs);

#endif // __ALARM__