#include <iostream>
#include "pipe.h"
#include "display.h"
#include "generator.h"
#include "alarm_filter.h"
#include "pipeline.h"


#define ARRAY_SIZEOF(arr) (*(&arr + 1) - arr)


int main(){

    AlarmFilter alarm_filter { };
    Generator gen { };
    Display disp  { };
    Pipe pipe_in { }, pipe_out { };
    Pipeline pipeline { &gen, &alarm_filter, &disp };

    
    
    
    connect(gen, pipe_in);
    connect(alarm_filter, pipe_in, pipe_out);
    connect(disp, pipe_out);


    for(int i { 0 } ; i < 10; i++){

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