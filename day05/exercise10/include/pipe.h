#ifndef __PIPE__
#define __PIPE__

#include <type_traits>
#include <optional>
#include "alarm_list.h"
#include "buffer.h"
#include "debug.h"



class Pipe {

public:


    using elem_type = Alarm_list;


    Pipe() = default;


    // void push(const elem_type& in);
    // void push(elem_type&& in);

    template <typename T >
    void push(T&& in);

    std::optional<elem_type> pull();

    bool is_empty() const;

    

private:


    Buffer<elem_type, 10> buffer_ { };


    

}; // Pipe class



// 1) written template function, 2) passing by r-value reference, 3) we use std::forward
template <typename T>
void Pipe::push(T&& in){

    // If it is an l-value, then it becomes T&, thus it stays as an l-value
    // If it is an r-value, then it stays T&&, thus it stays as an r-value.
    buffer_.write(std::forward<T>(in));

    TRACELN("Pipe::push::buffer_size = " << buffer_.size());

}




#endif // __PIPE__