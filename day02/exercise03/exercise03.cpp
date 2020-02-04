#include <iostream>
#include "pipe.h"
#include "display.h"
#include "generator.h"



int main(){

    Pipe pipe { };
    Display disp { };
    Generator gen { };


    connect(disp, pipe);
    connect(gen, pipe);

    gen.execute();
    disp.execute();

    disp.execute();

    gen.execute();

    disp.execute();



    return 0;
}