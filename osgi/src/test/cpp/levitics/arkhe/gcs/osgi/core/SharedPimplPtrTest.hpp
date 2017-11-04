#ifndef LEVITICS_ARKHE_OSGI_CORE_SHAREDPIMPLPTRTEST_HPP
#define LEVITICS_ARKHE_OSGI_CORE_SHAREDPIMPLPTRTEST_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/SharedPimplPtr.hpp>

namespace levitics::arkhe::gcs::osgi::core::test
{

    class SharedPimplPtrTest : public ::testing::Test
    {
        public:

            explicit SharedPimplPtrTest ( );
            virtual ~SharedPimplPtrTest ( );

            virtual void SetUp ( );
            virtual void TearDown ( );

        protected:

            static log4cxx::LoggerPtr logger;

        private:

            // SharedPimplPtr * objectToTest;
    };

}

#endif
