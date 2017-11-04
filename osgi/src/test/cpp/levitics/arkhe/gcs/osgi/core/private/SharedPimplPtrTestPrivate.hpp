#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_SHAREDPIMPLPTRTESTPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_SHAREDPIMPLPTRTESTPRIVATE_HPP

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

namespace levitics::arkhe::gcs::osgi::core::test
{

    class SharedPimplPtrTestPrivate
    {
        public:

            explicit SharedPimplPtrTestPrivate ( );
            virtual ~SharedPimplPtrTestPrivate ( );

        protected:

            static log4cxx::LoggerPtr logger;

        private:

    };

}

#endif