#include <levitics/arkhe/gcs/osgi/core/SharedPimplPtrTest.hpp>

using namespace levitics::arkhe::gcs::osgi::core::test;

log4cxx::LoggerPtr SharedPimplPtrTest::logger = \
    log4cxx::Logger::getLogger( std::string( "levitics.arkhe.gcs.osgi.core.test.SharedPimplPtrTest" ) );

SharedPimplPtrTest::SharedPimplPtrTest( )
// :   objectToTest( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

SharedPimplPtrTest::~SharedPimplPtrTest( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

void
SharedPimplPtrTest::SetUp( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

void
SharedPimplPtrTest::TearDown( )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
}

TEST_F( SharedPimplPtrTest, Test1 )
{
    LOG4CXX_TRACE( logger, __LOG4CXX_FUNC__ );
    EXPECT_TRUE( Q_NULLPTR == NULL );
}
