#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_DEMANGLERTEST_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_DEMANGLERTEST_HPP

#include <levitics/arkhe/gcs/osgi/core/edac/Demangler.hpp>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>

namespace levitics::arkhe::gcs::osgi::core::edac::test
{
    class DemanglerTest : public ::testing::Test
    {
        public:

            DemanglerTest( );
            virtual
            ~DemanglerTest( );

        private:

    };
}
#endif
