
#ifndef DEMANGLER_HPP
#define DEMANGLER_HPP
#include <string>
#include <typeinfo>

class Demangler
{
public:

    struct type_info : std::type_info
    {
        char const * name () const;
        static type_info const & from_std (std::type_info const &);
    };

    Demangler();
    Demangler(const char * m);
    Demangler(const Demangler & orig);
    virtual ~Demangler();

    std::string demangle (const char * name);
    operator const char * const & () const { return name; }

private:

    int m_status;
    const char * name;
    bool demangled;
};

#endif
