#include <exercises/errors-handling/Backtrace.hpp>

//#include <execinfo.h>
//#include <dlfcn.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cxxabi.h>
#include <memory>

Backtrace::Backtrace()
{

}

Backtrace::~Backtrace()
{

}

std::ostream &operator<<(std::ostream &os, const Backtrace &backtrace)
{
    return os;
}
