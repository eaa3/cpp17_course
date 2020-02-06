#include "pipeline.h"


Pipeline::Pipeline(std::initializer_list<IFilter*> init){

    auto src = std::begin(init);


    for(; src != std::end(init); src++){
       this->add(**src);
    }

}

void Pipeline::add(IFilter& filter){


    filters_.push_back(&filter);

    // if(next_ins != std::end(filters_)){

    //     *next_ins = &filter;
    //     next_ins++;

    // }
    // else {

    //     throw std::runtime_error("Pipeline is full. Unable to add more filters.");

    // }

    
}

void Pipeline::run(){

    for(auto it = std::begin(filters_); it != std::end(filters_); it++){
        (*it)->execute();
    }


}