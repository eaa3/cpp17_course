#include <cassert>
#include <cstdlib>
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

    auto category = static_cast<Alarm::Category>(2); //dist(gen)

    return category;//Alarm(category);


}

const char* Generator::make_random_description(){

    static const char* strings[] {
        "Hello",
        "Not bad, not great",
        "All right then!",
        "Jolly good!",
        "Tea time!",
        "Coffe is good",
        "Halo, ales gute",
        "Tchau!"

    };

    int ridx = rand()%8;

    return strings[ridx];




}

Pipe::elem_type Generator::make_random_element(){

 
    // Choose a random mean between 1 and 6
    static std::random_device r_;
    static std::mt19937 gen(r_());
    static std::uniform_int_distribution<int> dist(1, 10);

    int size = 5;//dist(gen);
    
    auto alarm_list = Pipe::elem_type { };
    alarm_list.reserve(size);

    for(int i { 0 }; i < size; i++){
        auto alarm_category = this->make_random_category();
        auto description = this->make_random_description();
        alarm_list.emplace(alarm_category, description);
    }


    return alarm_list;


}


void Generator::execute(){

    assert( pipe_ != nullptr );

    pipe_->push(std::move(this->make_random_element()));

    TRACELN("Generator::execute()");

}

