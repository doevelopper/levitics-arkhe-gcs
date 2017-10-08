
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

#define DEBUG_LOG(msg) \
    if (true) \
    { \
        LOG4CXX_DEBUG(log4cxx::Logger::getLogger("development") , qPrintable(QString(msg))) \
    } \
    else (void)0

#define INFO_LOG(msg) \
    if (true) \
    { \
        LOG4CXX_INFO(log4cxx::Logger::getLogger("info.release") , QString(msg).toUtf8().constData()) \
    } \
    else (void)0

#define WARN_LOG(msg) \
    if (true) \
    { \
        LOG4CXX_WARN(log4cxx::Logger::getLogger("info.release") , QString(msg).toUtf8().constData()) \
    } \
    else (void)0

#define ERROR_LOG(msg) \
    if (true) \
    { \
        LOG4CXX_ERROR(log4cxx::Logger::getLogger("errors.release") , QString(msg).toUtf8().constData()) \
    } \
    else (void)0


#define FATAL_LOG(msg) \
    if (true) \
    { \
        LOG4CXX_FATAL(log4cxx::Logger::getLogger("errors.release") , QString(msg).toUtf8().constData()) \
    } \
    else (void)0


#define DEBUG(message) \
    ( \
        (qDebug() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()) , \
        (void)0 \
    )

#define WARN(message) \
    ( \
        (qWarning() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()) , \
        (void)0 \
    )

#define CRITICAL(message) \
    ( \
        (qCritical() << Q_FUNC_INFO << ":" << QString(message).toStdString().c_str()) , \
        (void)0 \
    )

#define FATAL(message) \
    ( \
        (qFatal("%s : %s" , Q_FUNC_INFO , QString(message).toStdString().c_str())) , \
        (void)0 \
    )

// class LoggerPrivate;

class Logger : public QObject
{
public:

    using Superclass = QObject;
    explicit Logger (QObject * parent = Q_NULLPTR);
    virtual ~Logger ();

    void configure ();
    [[deprecated]]
    void trace (const QString & s);
    [[deprecated]]
    void debug (const QString & s);
    [[deprecated]]
    void info (const QString & s);
    [[deprecated]]
    void warn (const QString & s);
    [[deprecated]]
    void error (const QString & s);
    [[deprecated]]
    void fatal (const QString & s);

protected:

    QScopedPointer<LoggerPrivate> d_ptr;

private:

    Q_DECLARE_PRIVATE(Logger)
    Q_DISABLE_COPY(Logger)
};

#endif
