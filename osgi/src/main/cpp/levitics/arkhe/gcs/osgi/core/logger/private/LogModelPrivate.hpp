
#ifndef LEVITICS_OSGI_CORE_LOGGER_PRIVATE_LOGMODELPRIVATE_HPP
#define LEVITICS_OSGI_CORE_LOGGER_PRIVATE_LOGMODELPRIVATE_HPP
#include <QStringList>
class LogModelPrivate
{
    public:

        LogModelPrivate();
        ~LogModelPrivate();
		
		QStringList logs;
};

#endif
