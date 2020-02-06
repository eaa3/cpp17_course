#include <cassert>
#include <random>
#include "generator.h"
#include "debug.h"

void connect(Generator& generator, Pipe& pipe){

    generator.pipe_ = &pipe;
}

Alarm::Category Generator::make_random_category(){

 
    // Choose a random mean between 1 and 6
    static std::random_device r_;
    static std::mt19937 gen(r_());
    static std::uniform_int_distribution<int> dist(1, Alarm::Category::num_categories-1);

    auto category = static_cast<Alarm::Category>(dist(gen));

    return category;//Alarm(category);


}

Pipe::elem_type Generator::make_random_element(){

 
    // Choose a random mean between 1 and 6
    static std::random_device r_;
    static std::mt19937 gen(r_());
    static std::uniform_int_distribution<int> dist(1, 5);

    int size = dist(gen);
    
    auto alarm_list = Pipe::elem_type();
    alarm_list.reserve(size);

    for(int i { 0 }; i < size; i++){
        auto alarm = this->make_random_category();
        alarm_list.emplace(alarm);
    }


    return alarm_list;


}


void Generator::execute(){

    assert( pipe_ != nullptr );

    pipe_->push(this->make_random_element());

    TRACELN("Generator::execute()");

}

