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

