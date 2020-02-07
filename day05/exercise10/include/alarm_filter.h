#ifndef __ALARM_FILTER__
#define __ALARM_FILTER__


#include "filter.h"
#include "pipe.h"

class AlarmFilter : public IFilter {

public:

    AlarmFilter() = default;
    virtual ~AlarmFilter() = default;

    void execute();


    friend void connect(AlarmFilter& display, Pipe& pipe_in, Pipe& pipe_out);

private:

    Pipe* pipe_in_ { nullptr };
    Pipe* pipe_out_ { nullptr };

    

}; // AlarmFilter class

void connect(AlarmFilter& display, Pipe& pipe_in, Pipe& pipe_out);

#endif // __ALARM_FILTER__