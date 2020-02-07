
#include <iostream>

// Practise this again and again!

template <typename Derived_Ty>
class Base {

public:

    void read() { actual().read_impl(); }
    void write() { actual().write_impl(); }

protected:

    void read_impl() { std::cout << "Base::read " << std::endl;  }
    void write_impl() {  std::cout << "Base::write " << std::endl; }


    Derived_Ty& actual() { return *(static_cast<Derived_Ty*>(this));}
};


class Sub_type : public Base<Sub_type> {

public:

    void read_impl() { std::cout << "Sub_type::read" << std::endl; }

};


int main() {


    Sub_type example { };


    example.read();



}