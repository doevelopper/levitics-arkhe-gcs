
#include <QtCore/QRegularExpression>
#include <QtCore/QThread>
#include <QtCore/QDir>
#include <QtCore/QProcess>
#include <QtCore/QStandardPaths>

#include <iostream>
#ifdef Q_OS_WIN
  # include <qt_windows.h>
#else
  # include <unistd.h>
  # include <sys/types.h>
  # include <QCtrlSignals>
#endif

#include <levitics/arkhe/gcs/app/private/GCSApplicationPrivate.hpp>

// using namespace levitics::arkhe::gcs::app::private;
 
log4cxx::LoggerPtr GCSApplicationPrivate::logger =
    log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.app.private.GCSApplicationPrivate"));


GCSApplicationPrivate::GCSApplicationPrivate(GCSApplication * q_ptr)
    : QObject(q_ptr)
    , q(q_ptr)
    , m_loggerService(new Logger())
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    this->setApplicationName("APP_NAME");
    //    this->setApplicationVersion(APP_VERSION_STR);
    //    this->setOrganizationName(APP_ORG);
    //    this->setOrganizationDomain(APP_DOMAIN);
}

GCSApplicationPrivate::~GCSApplicationPrivate()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    delete this->m_loggerService;
}

void GCSApplicationPrivate::setInstanceId (const QString & id)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

QString
GCSApplicationPrivate::generateSingleId (const QString & seed)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    auto applicationID = QCoreApplication::applicationName().toLower();
    applicationID.remove(QRegularExpression(QStringLiteral("[^a-zA-Z0-9_]")));
    applicationID.truncate(8);
    applicationID.prepend(QStringLiteral("qbackproc-"));
    QByteArray hashBase = (QCoreApplication::organizationName() +
                           QCoreApplication::organizationDomain() +
                           seed).toUtf8();
    applicationID += QLatin1Char('-') +
                     QString::number(qChecksum(hashBase.data() , hashBase.size()) , 16) +
                     QLatin1Char('-');

 #ifdef Q_OS_WIN
        DWORD sessID;

        // if (::ProcessIdToSessionId(::GetCurrentProcessId() , &sessID))
        // {
        //    applicationID += QString::number(sessID , 16);
        // }

 #else
        applicationID += QString::number(::getuid() , 16);
 #endif

    return applicationID;
}

GCSApplicationPrivate *
GCSApplicationPrivate::p_ptr ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // return qApp->d;
}

int GCSApplicationPrivate::initControlFlow (const QCommandLineParser & parser)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}
