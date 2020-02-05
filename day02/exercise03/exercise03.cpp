#include <iostream>
#include "pipe.h"
#include "display.h"
#include "generator.h"



int main(){

    Generator gen { };
    Display disp  { };
    Pipe pipe     { };
    
    
    connect(disp, pipe);
    connect(gen, pipe);

    // Generates an alarm and pushes it to the pipe
    gen.execute();
    // Pulls the generated alarm and displays it
    disp.execute();

    // Tries to display again, but there shouldn't be any more alarms to display
    disp.execute();

    for(int i { 0 } ; i < 5; i++){

        gen.execute();
        disp.execute();

    }



    return 0;
}