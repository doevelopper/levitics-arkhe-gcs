#ifndef TEAMPLATE_BACKTRACE_HPP
#define TEAMPLATE_BACKTRACE_HPP


#include <ostream>

class Backtrace
{
    struct BacktraceInfo
    {
        static const int maxFrames = 128;
        int numFrames;
        void * addressList[maxFrames];
    };

public:

    Backtrace();
    virtual ~Backtrace();

    friend std::ostream &operator<<(std::ostream &os, const Backtrace &backtrace);

};


#endif
