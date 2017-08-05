
#ifndef LEVITICS_OSGI_CORE_LOGGER_PRIVATE_LOGGERPRIVATE_HPP
#define LEVITICS_OSGI_CORE_LOGGER_PRIVATE_LOGGERPRIVATE_HPP

#include <string>
#include <stdexcept>
#include <apr-1/apr.h>
#include <log4cxx/logger.h>
#include <log4cxx/appender.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/consoleappender.h>                              // CONSOLE Appender
#include <log4cxx/fileappender.h>                                 // FILE Appender
#include <log4cxx/rolling/rollingfileappender.h>                  // ROLLING FILE Appender
#include <log4cxx/nt/nteventlogappender.h>                        // NT EVENT LOG Appender
#include <log4cxx/nt/outputdebugstringappender.h>                 // NT OUTPUTDEBUGSTRING Appender
#include <log4cxx/net/socketappender.h>                           // SOCKET Appender
#include <log4cxx/simplelayout.h>                                 // needed for simple layout
#include <log4cxx/patternlayout.h>                                // needed for pattern layout
#include <log4cxx/logmanager.h>
#include <log4cxx/logstring.h>                                    // has typedefed string type used in log4cxx
#include <log4cxx/rolling/rollingpolicy.h>
#include <log4cxx/rolling/rollingpolicybase.h>
#include <log4cxx/rolling/triggeringpolicy.h>
#include <log4cxx/rolling/sizebasedtriggeringpolicy.h>
#include <log4cxx/rolling/fixedwindowrollingpolicy.h>
#include <log4cxx/xml/domconfigurator.h>

// extern log4cxx::LoggerPtr logger;

// #define LOG_TRACE(x) LOG4CXX_TRACE(logger , x)
// #define LOG_DEBUG(x) LOG4CXX_DEBUG(logger , x)
// #define LOG_INFO(x)  LOG4CXX_INFO(logger , x)
// #define LOG_WARN(x)  LOG4CXX_WARN(logger , x)
// #define LOG_ERROR(x) LOG4CXX_ERROR(logger , x)

class LoggerPrivate
{

public:

    LoggerPrivate(unsigned long delay = 5000L);
    ~LoggerPrivate();
    //    LoggerPrivate(const LoggerPrivate & rsh);

    unsigned long periodicalCheck () const;
    void loggerReset ();
    log4cxx::LoggerPtr getLoggerByName (const char * loggerName);
    void loadConfig (const std::string & configFilename);
    void loadConfigAndWatch (const std::string & configFilename);
    void loggerNames (std::vector<std::string> & names);
    log4cxx::LoggerPtr operator -> (void)
    {
        return this->m_logger;
    }

    //    log4cxx::LoggerPtr operator = (const LoggerPrivate &logger)
    //    {
    //        return this->m_logger;
    //    }

    log4cxx::Logger * loggerSvce;

    Q_DISABLE_COPY(LoggerPrivate);

private:

    bool checkLogManagerStatus ();
    std::string getFileExtension (const std::string & s);
    /*!
     *  @brief Value for periodical check if configFilename has been created or modified!
     */
    unsigned long m_watchPeriod;
    /*!
     *  @brief Value for periodical check if configFilename has been created or modified!
     */
    static const char * configEnv;
    /*!
     *  @brief Value for periodical check if configFilename has been created or modified!
     */
    log4cxx::LoggerPtr m_logger;
    static std::string m_loggerConfigLocation;
};

#endif
