
#include <levitics/arkhe/gcs/Application.hpp>

log4cxx::LoggerPtr Application::logger = log4cxx::Logger::getLogger(std::string("exercises.Application"));
std::string Application::loggerConfigLocation = "LOG4CXX_CONFIGURATION_PATH =/etc/cfg/log4cxx.xml";

Application::Application()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    LOG4CXX_INFO(logger , std::locale("").name().c_str());
    /*
       std::setlocale(LC_ALL, "en_US.UTF-8");
       std::setlocale(LC_NUMERIC, "de_DE");
       std::setlocale(LC_TIME, "ja_JP");
       std::setlocale(LC_ALL    );//selects the entire C locale
       std::setlocale(LC_COLLATE        );//selects the collation category of the C locale
       std::setlocale(LC_CTYPE  );//selects the character classification category of the C locale
       std::setlocale(LC_MONETARY       );//selects the monetary formatting category of the C locale
       std::setlocale(LC_NUMERIC        );//selects the numeric formatting category of the C locale
       std::setlocale(LC_TIME   );//selects the time formatting category of the C locale
     */
    // DO some stuffs
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Application::Application(int argc ,
                         char * argv[])
    : m_loggerService(new LoggingService(5000))
{
    int ret = ::putenv(loggerConfigLocation.c_str());

    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // DO some stuffs
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

Application::~Application()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->m_loggerService;
}
