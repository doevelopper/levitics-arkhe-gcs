
#include <levitics/arkhe/gcs/osgi/core/logger/LoggerTest.hpp>
using namespace levitics::arkhe::gcs::osgi::core::logger::test;

log4cxx::LoggerPtr LoggerTest::logger = \
	log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.osgi.core.logger.test.LoggerTest"));
	
LoggerTest::LoggerTest()
: objectToTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

LoggerTest::~LoggerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void LoggerTest::SetUp ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void LoggerTest::TearDown ()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TEST_F(LoggerTest, TestLoggerSettings) 
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
	EXPECT_TRUE(Q_NULLPTR == NULL);
}

