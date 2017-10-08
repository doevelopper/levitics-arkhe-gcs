
#ifndef LEVITICS_ARKHE_GCS_APPLICATION_HPP
#define LEVITICS_ARKHE_GCS_APPLICATION_HPP
#include <locale>
#include <iostream>
#include <cstdlib>      /* getenv */
#include <cstdio>

#include <levitics/arkhe/gcs/LoggingService.hpp>
#include <levitics/arkhe/gcs/errors-handling/Exceptions.hpp>
class Application
{
public:

    Application();
    Application(int argc , char * argv[]);
    Application(const Application &) = delete;
    Application(Application &&) = delete;
    Application & operator = (const Application &) = delete;
    Application & operator = (Application &&) = delete;
    virtual ~Application();

private:

    LoggingService * m_loggerService;
    static const long m_fileMonitorDelay = 5000UL;
    static log4cxx::LoggerPtr logger;
    static std::string loggerConfigLocation;
};

#endif
