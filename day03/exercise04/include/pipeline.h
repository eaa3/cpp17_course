#ifndef __PIPELINE__
#define __PIPELINE__

#include <array>
#include <vector>
#include "filter.h"


class Pipeline {

public:

    Pipeline() = default;
    Pipeline(std::initializer_list<IFilter*> init);

    void add(IFilter& filter);
    void run();

private:
    //static constexpr int max_size { 4 };
    using Container = std::vector<IFilter*>; //std::array<IFilter*, max_size>;
    using iterator = Container::iterator;
    Container filters_;
    // iterator next_ins { std::begin(filters_) };

}; // Pipeline class

#endif // __PIPELINE__