#include <cassert>
#include <random>
#include "generator.h"

void connect(Generator& generator, Pipe& pipe){

    generator.pipe_ = &pipe;
}

Pipe::elem_type Generator::make_random_alarm(){

 
    // Choose a random mean between 1 and 6
    static std::random_device r_;
    static std::mt19937 gen(r_());
    static std::uniform_int_distribution<int> dist(1, Alarm::Category::num_categories-1);

    auto category = static_cast<Alarm::Category>(dist(gen));

    return Alarm(category);


}

void Generator::execute(){

    assert( pipe_ != nullptr );

    pipe_->push(this->make_random_alarm());

}

