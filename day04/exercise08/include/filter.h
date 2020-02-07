#ifndef __IFILTER__
#define __IFILTER__


class IFilter {

public:

    virtual ~IFilter() = default;

    virtual void execute() = 0;

    

}; // IFilter interface

#endif // __IFILTER__