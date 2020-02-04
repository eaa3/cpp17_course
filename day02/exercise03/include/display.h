#ifndef __DISPLAY__
#define __DISPLAY__

#include "pipe.h"


class Display {

public:

    Display() = default;


    void execute();

    
    friend void connect(Display& display, Pipe& pipe);

private:

    Pipe* pipe_ { nullptr };
    

}; // Display class


void connect(Display& display, Pipe& pipe);

#endif // __DISPLAY__