
#include <levitics/arkhe/gcs/osgi/core/logger/LoggerTest.hpp>
using namespace levitics::arkhe::gcs::osgi::core::logger::test;

log4cxx::LoggerPtr LoggerTest::logger = \
	log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.osgi.core.logger.test.LoggerTest"));
	
LoggerTest::LoggerTest()
{

}

LoggerTest::~LoggerTest()
{

}

void LoggerTest::SetUp ()
{

}

void LoggerTest::TearDown ()
{

}
