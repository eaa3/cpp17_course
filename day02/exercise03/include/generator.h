#ifndef __GENERATOR__
#define __GENERATOR__

#include "pipe.h"


class Generator {

public:

    Generator() = default;
    // Generator(Pipe& pipe);


    void execute();

    
    friend void connect(Generator& display, Pipe& pipe);
    
private:

    Pipe::elem_type make_random_alarm();

    Pipe* pipe_ { nullptr };
    

}; // Generator class


void connect(Generator& display, Pipe& pipe);

#endif // __GENERATOR__