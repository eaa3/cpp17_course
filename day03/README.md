# Day 03


* Repository with solutions: `git clone git@bitbucket.org:Feabhas/acpp11_502_solutions.git`



## Bringing base class constructors into scope


```cpp
class Rotary_encoder : public Sensor {

public:
    using Sensor::Sensor; // make all base class constructors visible within the scope of Rotary encoder

private:

    double conv_factor { 1.0 };
    double gain        { 1.0 };

};

```

1. Single Responsability
2. Open-Closed
3. Linked Substitution



* Cohesion, how well the set of interfaces relate relates to state, construction and behaviour/functional interface. It is all about separating concerns.


## Class adapter

Change from one interface to another. How to make an adaptor? 


### Example 1: the object adapter

```cpp

class Utility {

public:
    void op1() { }
    void op2() { }
    void op3() { }
    void op4() { }
};


class Object_adapter {

public:
    void func1() { ut.op1(); }
    void func2() { ut.op3(); }

private:
    Utility ut { };
};

// An alternative is to use the Class adapter pattern
// We use private inheritance
// This is a derived type: a non-substitutable version, since it has a different interface 
// blog.feabhas.com
class Class_adapter : private Utility {

public:

    void func1() { Utility::op1(); }
    void func2() { Utility::op2(); }

    // Exposing op4 back to public again in this class scope
    using Utility::op4;


};


```


## Emplacement

```cpp

#include <vector>

using namespace std;

class ADT {

};

int main(){

    vector<ADT> v{ };
}


```