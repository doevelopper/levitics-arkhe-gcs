#ifndef LEVITICS_OSGI_CORE_LOGGER_PIMPLPTRTEST_HPP
#define LEVITICS_OSGI_CORE_LOGGER_PIMPLPTRTEST_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>
#include <levitics/arkhe/gcs/osgi/core/PimplPtr.hpp>

namespace levitics::arkhe::gcs::osgi::core::test
{
    class PimplPtrTestPrivate;

    class PimplPtrTest : public ::testing::Test
    {
        public:

            explicit PimplPtrTest ( );
            virtual ~PimplPtrTest ( );

            virtual void SetUp ( );
            virtual void TearDown ( );

            int get () const;
            void set (int x);

        protected:

            static log4cxx::LoggerPtr logger;

        private:

            PimplPtr <class PimplPtrTestPrivate> d;
    };

}

#endif
