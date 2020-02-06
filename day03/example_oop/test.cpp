#include <iostream>
#include "debug.h"

class Base {

public:

    Base() = default;
    

    virtual void op(int) { TRACELN("base::op(int)"); }

};

class Deverived : public Base {


public:


    void op(double) { TRACELN("derived::op(double)"); }


    void op(int) { TRACELN("derived::op(int)"); } 

    void op(int,int) { TRACELN("derived::op(int,int)"); } 

};


int main(){


    Deverived dev { };
    Base& base = dev;

    



    base.op(1); // virtual table is utilised, so we have dynamically bound functions (it will call the derived::op(int), instead of base::op(int))
    dev.op(1,2); // member function only exists in the derived class


    // recovering derived pointer from base reference (since base is actually pointing to a derived object)
    Deverived* ptr = dynamic_cast<Deverived*>(&base);
    ptr->op(1);


}