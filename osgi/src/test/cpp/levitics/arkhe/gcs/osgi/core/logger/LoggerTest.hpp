
#ifndef LEVITICS_OSGI_CORE_LOGGER_LOGGER_HPP
#define LEVITICS_OSGI_CORE_LOGGER_LOGGER_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

namespace levitics::arkhe::gcs::osgi::core::logger::test
{
	class LoggerTest : public ::testing::Test
	{
	public:

		explicit LoggerTest ();
		virtual ~LoggerTest ();

		virtual void SetUp ();
		virtual void TearDown ();

	protected:


	private:
		static log4cxx::LoggerPtr logger;
		Logger * objectToTest;
	};
}

#endif
