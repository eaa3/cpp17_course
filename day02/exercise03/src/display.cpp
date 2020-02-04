

#include <cassert>
#include "display.h"


void connect(Display& display, Pipe& pipe){

    display.pipe_ = &pipe;
}


void Display::execute(){

    assert( pipe_ != nullptr );

    std::cout << "Display::";

    if( !pipe_->is_empty() ){

        auto alarm = pipe_->pull();


        std::cout << "Alarm: " << alarm << std::endl;
    }else {

        std::cout << " Pipe is empty" << std::endl;
    }
    

}