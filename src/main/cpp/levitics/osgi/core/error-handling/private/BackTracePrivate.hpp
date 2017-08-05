#ifndef LEVITICS_OSGI_CORE_ERRORHANDLING_PRIVATE_BACKTRACEPRIVATE_HPP
#define LEVITICS_OSGI_CORE_ERRORHANDLING_PRIVATE_BACKTRACEPRIVATE_HPP

#include <vector>
#include <string>

#if defined(__linux) || defined(__APPLE__) || defined(__sun)
    #define HAVE_EXECINFO
    #define HAVE_DLADDR
#endif

#if defined(__GNUC__)
    #define HAVE_ABI_CXA_DEMANGLE
#endif

#ifdef HAVE_EXECINFO
    #include <execinfo.h>
#endif

#ifdef HAVE_ABI_CXA_DEMANGLE
    #include <cxxabi.h>
#endif

#ifdef HAVE_DLADDR
    #include <dlfcn.h>
#endif

#include <stdlib.h>
#include <sstream>

class BackTracePrivate
{
public:

    BackTracePrivate ();
    virtual ~BackTracePrivate ();

    std::vector<void *> Frames;
    int trace(void** addresses, size_t size) const;
    std::string getSymbol(void* address) const;
protected:

private:

};

#endif
