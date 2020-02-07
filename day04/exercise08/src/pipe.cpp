#include <cassert>
#include "pipe.h"


void Pipe::push(const elem_type& in){

    elem_ = in;

}

void Pipe::push(elem_type&& in){


    elem_ = std::move(in);

}

Pipe::elem_type Pipe::pull() {

    assert(elem_.has_value());

    auto ret_elem = std::move(elem_.value());

    elem_.reset();

    return std::move(ret_elem);

}

bool Pipe::is_empty() const {

    return !elem_.has_value();

}