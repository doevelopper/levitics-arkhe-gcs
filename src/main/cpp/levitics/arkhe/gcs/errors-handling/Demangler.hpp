#ifndef DEMANGLER_HPP
#define DEMANGLER_HPP
#include <string>
#include <typeinfo>
class Demangler 
{
public:
    struct type_info : std::type_info 
    { 
        char const * name() const; 
        static type_info const & from_std(std::type_info const&); 
    };
    Demangler();
    Demangler(const Demangler& orig);
    virtual ~Demangler();
    
    std::string demangle(const char* name);
    template <class T>
    std::string type(const T& t);
private:
    int m_status;
};

#endif

