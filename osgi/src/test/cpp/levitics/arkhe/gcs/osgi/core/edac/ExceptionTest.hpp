#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_EXCEPTIONTEST_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_EXCEPTIONTEST_HPP
#include <levitics/arkhe/gcs/osgi/core/edac/Exception.hpp>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

namespace levitics::arkhe::gcs::osgi::core::edac::test
{

    class ExceptionTest : public ::testing::Test
    {
        public:

            ExceptionTest ( );
            virtual
            ~ExceptionTest ( );

    };

}
#endif
