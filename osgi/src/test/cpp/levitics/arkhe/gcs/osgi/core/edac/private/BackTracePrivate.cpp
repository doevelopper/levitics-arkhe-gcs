
#include <iostream>
#include <sstream>
#include <locale>
#include <levitics/osgi/core/error-handling/private/BackTracePrivate.hpp>

BackTracePrivate::BackTracePrivate ()
{

}

BackTracePrivate::~BackTracePrivate ()
{

}

int BackTracePrivate::trace (void * * addresses ,
                             size_t size) const
{
    // return ::backtrace(array , n);
}

std::string
BackTracePrivate::getSymbol (void * ptr) const
{
    if (!ptr)
        return std::string();

    std::ostringstream res;
    res.imbue(std::locale::classic());
    res << ptr;
    return res.str();
}
