#ifndef __GENERATOR__
#define __GENERATOR__

#include "pipe.h"
#include "filter.h"
#include "alarm.h"


class Generator : public IFilter {

public:

    Generator() = default;
    // Generator(Pipe& pipe);


    void execute();

    
    friend void connect(Generator& display, Pipe& pipe);
    
private:

    Alarm::Category make_random_category();

    Pipe::elem_type make_random_element();

    Pipe* pipe_ { nullptr };
    

}; // Generator class


void connect(Generator& display, Pipe& pipe);

#endif // __GENERATOR__