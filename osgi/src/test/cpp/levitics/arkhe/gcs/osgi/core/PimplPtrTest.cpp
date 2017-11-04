#include <levitics/arkhe/gcs/osgi/core/PimplPtrTest.hpp>
using namespace levitics::arkhe::gcs::osgi::core::test;

log4cxx::LoggerPtr PimplPtrTest::logger = \
    log4cxx::Logger::getLogger( std::string( "levitics.arkhe.gcs.osgi.core.test.PimplPtrTest" ) );

PimplPtrTest::PimplPtrTest( )
// :   objectToTest( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

PimplPtrTest::~PimplPtrTest( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

void
PimplPtrTest::SetUp( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

void
PimplPtrTest::TearDown( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

TEST_F( PimplPtrTest, Test1 )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
    EXPECT_TRUE( Q_NULLPTR == NULL );
}
