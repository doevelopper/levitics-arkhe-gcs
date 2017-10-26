#include <levitics/arkhe/gcs/osgi/core/Cpuid.hpp>
#include <levitics/arkhe/gcs/osgi/core/private/CpuidPrivate.hpp>
Cpuid::Cpuid( )
    :   d( new CpuidPrivate )
{

}

Cpuid::~Cpuid( )
{
    delete d;
}

void
Cpuid::load( unsigned i )
{
    // #if defined(Q_OS_WIN) && defined(Q_CC_MSVC)
    // __cpuid((int *)d->regs, (int)i);
    // #elif defined(DTK_BUILD_64)
    asm volatile
    ("cpuid" : "=a" (d->regs [0]), "=b" (d->regs [1]), "=c" (d->regs [2]), "=d" (d->regs [3])
     : "a" (i), "c" (0) );

    // #endif
}

QString
Cpuid::vendor( void )
{
    this->load( 0 );     // Get CPU vendor

    QString vendor;
    vendor += QString::fromUtf8( (const char *) &d->regs [1], 4 );
    vendor += QString::fromUtf8( (const char *) &d->regs [3], 4 );
    vendor += QString::fromUtf8( (const char *) &d->regs [2], 4 );

    return vendor;
}
