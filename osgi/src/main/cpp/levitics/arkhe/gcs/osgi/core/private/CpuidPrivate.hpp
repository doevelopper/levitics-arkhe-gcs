#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_CPUIDPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_CPUIDPRIVATE_HPP

#include <levitics/Config.hpp>
#include <QtCore>
#include <cstdint>
class Cpuid;

class EXPORT_API CpuidPrivate
{
public:

    CpuidPrivate( );
    virtual ~CpuidPrivate( );

    uint32_t regs [4];
};

#endif
