#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGGER_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGGER_HPP

#include <QObject>

#include <levitics/arkhe/gcs/osgi/core/logger/private/LoggerPrivate.hpp>

// #define LOG_EMERG    0       /* system is unusable. A panic condition was reported to all processes. */
// #define LOG_ALERT    1       /* action must be taken immediately. A condition that should be corrected immediately.  */
// #define LOG_CRIT     2       /* critical conditions */
// #define LOG_ERR      3       /* error conditions */
// #define LOG_WARNING  4       /* warning conditions */
// #define LOG_NOTICE   5       /* normal but significant condition. A condition requiring special handling.  */
// #define LOG_INFO     6       /* informational */
// #define LOG_DEBUG    7       /* debug-level messages. A message useful for debugging programs.  */
#define LOG_TRACE(message)      LOG4CXX_TRACE(logger, message)
#define LOG_DEBUG(message)      LOG4CXX_DEBUG(logger, message)
#define LOG_INFO(message)       LOG4CXX_INFO(logger, message)
#define LOG_WARNING(message)    LOG4CXX_WARN(logger, message)
#define LOG_ERROR(message)      LOG4CXX_ERROR(logger, message)
#define LOG_FATAL(message)      LOG4CXX_FATAL(logger, message)
#define LOG_ASSERT(cond, message)        LOG4CXX_ASSERT(logger, condition, message)
#define LOG_ASSERT_X(cond, msg) ((!(cond)) ? cuteLoggerInstance()->writeAssert(__FILE__, __LINE__, Q_FUNC_INFO, msg) : qt_noop())

#define LOG_CATEGORY(category) \
    private: \
        Logger * cuteLoggerInstance() \
        { \
            static Logger customCuteLoggerInstance(category); \
            return &customCuteLoggerInstance; \
        } \

#define LOG_GLOBAL_CATEGORY(category) \
    private: \
        static static log4cxx::LoggerPtr logger; \


#define DEBUG_LOG( msg ) \
    if( true ) \
    { \
        LOG4CXX_DEBUG( log4cxx::Logger::getLogger( "development" ), qPrintable( QString( msg ) ) ) \
    } \
    else (void) 0

#define INFO_LOG( msg ) \
    if( true ) \
    { \
        LOG4CXX_INFO( log4cxx::Logger::getLogger( "info.release" ), QString( msg ).toUtf8( ).constData( ) ) \
    } \
    else (void) 0

#define WARN_LOG( msg ) \
    if( true ) \
    { \
        LOG4CXX_WARN( log4cxx::Logger::getLogger( "info.release" ), QString( msg ).toUtf8( ).constData( ) ) \
    } \
    else (void) 0

#define ERROR_LOG( msg ) \
    if( true ) \
    { \
        LOG4CXX_ERROR( log4cxx::Logger::getLogger( "errors.release" ), QString( msg ).toUtf8( ).constData( ) ) \
    } \
    else (void) 0

#define FATAL_LOG( msg ) \
    if( true ) \
    { \
        LOG4CXX_FATAL( log4cxx::Logger::getLogger( "errors.release" ), QString( msg ).toUtf8( ).constData( ) ) \
    } \
    else (void) 0

#define DEBUG( message ) \
    ( \
        (qDebug( ) << Q_FUNC_INFO << ":" << QString( message ).toStdString( ).c_str( ) ), \
        (void) 0 \
    )

#define WARN( message ) \
    ( \
        (qWarning( ) << Q_FUNC_INFO << ":" << QString( message ).toStdString( ).c_str( ) ), \
        (void) 0 \
    )

#define CRITICAL( message ) \
    ( \
        (qCritical( ) << Q_FUNC_INFO << ":" << QString( message ).toStdString( ).c_str( ) ), \
        (void) 0 \
    )

#define FATAL( message ) \
    ( \
        (qFatal( "%s : %s", Q_FUNC_INFO, QString( message ).toStdString( ).c_str( ) ) ), \
        (void) 0 \
    )

// class LoggerPrivate;

class Logger : public QObject
{
    public:

        using Superclass = QObject;
        explicit
        Logger ( QObject * parent = Q_NULLPTR );
        virtual
        ~Logger ( );

        void configure ( );
        Q_DECL_DEPRECATED void trace ( const QString & s );
        Q_DECL_DEPRECATED void debug ( const QString & s );
        Q_DECL_DEPRECATED void info ( const QString & s );
        Q_DECL_DEPRECATED void warn ( const QString & s );
        Q_DECL_DEPRECATED void error ( const QString & s );
        Q_DECL_DEPRECATED void fatal ( const QString & s );

    protected:

        QScopedPointer<LoggerPrivate> d_ptr;

    private:

        Q_DECLARE_PRIVATE( Logger )
        Q_DISABLE_COPY( Logger )
};

#endif
