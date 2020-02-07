#ifndef __BUFFER__
#define __BUFFER__

#include <cassert>
#include <array>
#include <optional>

template <typename T, std::size_t sz>
class Buffer {

public:

    Buffer() = default;

    template <typename U >
    bool write(U&& elem);
    std::optional<T> read();



    std::size_t size() const;

    bool is_empty() const;




private:


    std::array<T, sz> buf_;
    int ri_ { 0 }; // read index
    int wi_ { 0 }; // write index
    std::size_t count_ { 0 }; // counter of elements



    

}; // Buffer class (a circular buffer)


// 1) written template function, 2) passing by r-value reference, 3) we use std::forward
template <typename T, std::size_t sz>
template <typename U>
bool Buffer<T, sz>::write(U&& in){

    bool ret = false;

    if( count_  < buf_.size() ){

        buf_[wi_] = std::forward<U>(in); //in;//
        wi_ = (wi_+1)%buf_.size();
        count_++;

        ret = true;
    }


    return ret;

}

template <typename T, std::size_t sz>
std::optional<T> Buffer<T, sz>::read(){

    std::optional<T> ret;

    if(count_ > 0){
        
        
        ret = std::move(buf_[ri_]);

        ri_ = (ri_+1)%buf_.size();
        count_--;

    }


    return ret;

}

template <typename T, std::size_t sz>
std::size_t Buffer<T, sz>::size() const {

    return count_;
}

template <typename T, std::size_t sz>
bool Buffer<T, sz>::is_empty() const {
    
    return count_ == 0;
}

#endif // __BUFFER__