#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_BACKTRACETEST_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_BACKTRACETEST_HPP

#include <levitics/arkhe/gcs/osgi/core/edac/BackTrace.hpp>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

namespace levitics::arkhe::gcs::osgi::core::edac::test
{
    class BackTraceTest : public ::testing::Test
    {
        public:

            BackTraceTest ( );
            BackTraceTest( const BackTraceTest & other );
            ~BackTraceTest ( );

        protected:

        private:

    };
}
#endif
