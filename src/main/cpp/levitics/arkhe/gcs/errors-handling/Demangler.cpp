#include <exercises/errors-handling/Demangler.hpp>

#include <cstdlib>
#include <memory>
#include <cxxabi.h>

Demangler::Demangler()
: m_status(-10)
{
}

Demangler::Demangler(const Demangler& orig)
{
}

Demangler::~Demangler()
{
}

std::string Demangler::demangle(const char* name) 
{
#ifdef HAVE_CXA_DEMANGLE
    //std::unique_ptr<char, decltype(&std::free)>
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, nullptr, nullptr, &this->m_status),
        std::free
    };
    //https://panthema.net/2008/0901-stacktrace-demangled/cxa_demangle.html
    return (this->m_status==0) ? res.get() : name ;
#else
  return name;
#endif  
}
/*
template <class T>
std::string Demangler<T>::type(const T& t) {

    return this->demangle(typeid(t).name());
}
 * */