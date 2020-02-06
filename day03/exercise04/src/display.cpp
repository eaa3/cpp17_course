

#include <cassert>
#include "display.h"
#include "debug.h"


void connect(Display& display, Pipe& pipe){

    display.pipe_ = &pipe;
}


void Display::execute(){

    assert( pipe_ != nullptr );

    if( !pipe_->is_empty() ){

        auto alarm_list = pipe_->pull();

        TRACE("Display[" << alarm_list.size() << "]::");
        for(auto& alarm : alarm_list){
            TRACELN("Alarm::" << alarm);
        }
        
    }else {
        TRACELN(" Pipe is empty");
    }
    

}