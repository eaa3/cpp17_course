#include <cassert>
#include "pipe.h"


// void Pipe::push(const elem_type& in){

//     elem_ = in;

// }

// void Pipe::push(elem_type&& in){


//     elem_ = std::move(in);

// }

std::optional<Pipe::elem_type> Pipe::pull() {

    std::optional<Pipe::elem_type> ret_elem;

    if( !this->is_empty() ){

         ret_elem = std::move(buffer_.read());

    }


    return std::move(ret_elem);

}

bool Pipe::is_empty() const {

    return buffer_.is_empty();

}