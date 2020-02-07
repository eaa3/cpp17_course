#ifndef __TRACE_DEBUG_H__
#define __TRACE_DEBUG_H__

//

#ifdef TRACE_ENABLED
    #include <iostream>
    #define TRACELN(msg) std::cout << msg << std::endl
    #define TRACE(msg) std::cout << msg 
#else
    #define TRACE(msg)
    #define TRACELN(msg)
#endif

#endif //__TRACE_DEBUG_H__