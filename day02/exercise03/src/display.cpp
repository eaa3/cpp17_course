

#include <cassert>
#include "display.h"
#include "debug.h"


void connect(Display& display, Pipe& pipe){

    display.pipe_ = &pipe;
}


void Display::execute(){

    assert( pipe_ != nullptr );

    TRACE("Display::");

    if( !pipe_->is_empty() ){

        auto alarm = pipe_->pull();


        TRACELN("Alarm: " << alarm);
    }else {
        TRACELN(" Pipe is empty");
    }
    

}