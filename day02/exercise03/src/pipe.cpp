#include <cassert>
#include "pipe.h"


void Pipe::push(const elem_type& in){

    elem_ = in;

}

Pipe::elem_type Pipe::pull() {

    assert(elem_.has_value());

    auto ret_elem = elem_.value();

    elem_.reset();

    return ret_elem;

}

bool Pipe::is_empty() const {

    return !elem_.has_value();

}