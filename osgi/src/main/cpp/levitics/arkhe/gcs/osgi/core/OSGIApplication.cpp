#include <levitics/arkhe/gcs/osgi/core/Cpuid.hpp>
#include <levitics/arkhe/gcs/osgi/core/private/OSGIApplicationPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/OSGIApplication.hpp>

// OSGIApplication::OSGIApplication( )
////    :   d( new OSGIApplicationPrivate )
// {

// }

OSGIApplication::OSGIApplication (int & argc, char * * argv)
    : QApplication(argc, argv)
{

}

OSGIApplication::~OSGIApplication( )
{
////   delete d;
}
