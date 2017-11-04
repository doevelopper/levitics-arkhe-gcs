#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_PIMPLPTRTESTPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_PIMPLPTRTESTPRIVATE_HPP

#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

namespace levitics::arkhe::gcs::osgi::core::test
{

    class PimplPtrTestPrivate
    {
        public:

            explicit PimplPtrTestPrivate ( );
            virtual ~PimplPtrTestPrivate ( );

            quint32 x;

        protected:

            static log4cxx::LoggerPtr logger;

        private:

    };

}

#endif
