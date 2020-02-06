#include <iostream>
#include "pipe.h"
#include "display.h"
#include "generator.h"
#include "pipeline.h"


#define ARRAY_SIZEOF(arr) (*(&arr + 1) - arr)

int main(){

    Generator gen { };
    Display disp  { };
    Pipe pipe     { };
    Pipeline pipeline { &gen, &disp };
    
    
    connect(disp, pipe);
    connect(gen, pipe);

    // pipeline.add(gen);
    // pipeline.add(disp);

    // pipeline.add(disp);
    // pipeline.add(disp);
    


    for(int i { 0 } ; i < 5; i++){

        pipeline.run();

    }

    // int arr[2][3];
    // int rows = ARRAY_SIZEOF(arr);
    // int cols = (sizeof(arr)/sizeof(arr[0][0]))/rows;
    // printf("Size: %d %d\n", rows, cols);
    // for(int i = 0; i < 2; i ++){
    //     for(int j = 0; j < 3; j++){
    //         printf("%x ",&arr[i][j]);
    //     }

    //     printf("\n");
    // }



    return 0;
}