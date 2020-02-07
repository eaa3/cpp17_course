#include <cassert>
#include <algorithm>
#include "alarm_filter.h"
#include "debug.h"


void connect(AlarmFilter& alarm_filter, Pipe& pipe_in, Pipe& pipe_out){

    alarm_filter.pipe_in_ = &pipe_in;
    alarm_filter.pipe_out_ = &pipe_out;
}

void AlarmFilter::execute(){

    assert( pipe_in_ != nullptr && pipe_out_ != nullptr );


    if( !pipe_in_->is_empty() ){

        auto alarm_list = std::move(pipe_in_->pull().value());

        TRACE("AlarmFilter[" << alarm_list.size() << "]=>");


        auto it = std::remove_if(std::begin(alarm_list), 
                                 std::end(alarm_list), 
                                 [](const auto& alarm) {
                                
                                     return alarm.type() == Alarm::Category::advisory;

                                  });

        alarm_list.erase(it, std::end(alarm_list));

        TRACELN("[" << alarm_list.size() << "]");

        pipe_out_->push(std::move(alarm_list));

        
    }else {
        TRACELN("AlarmFilter::[Empty]");
    }



}