
#ifndef LEVITICS_APP_GCSAPPLICATIONPRIVATE_HPP
#define LEVITICS_APP_GCSAPPLICATIONPRIVATE_HPP

#include <QCommandLineParser>
#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QtCore/QLockFile>
#include <QtCore/QScopedPointer>
#include <QtCore/QPointer>
#include <QtCore/QLoggingCategory>
#include <QtCore/QFile>
#include <QtNetwork/QLocalServer>

#include <levitics/osgi/core/logger/Logger.hpp>
#include <levitics/app/GCSApplication.hpp>

class GCSApplicationPrivate : public QObject
{
    Q_OBJECT

public:

    // explicit GCSApplicationPrivate(QObject * parent = nullptr);
    static GCSApplicationPrivate * p_ptr ();
    static QString generateSingleId (const QString &seed = QString());
    GCSApplicationPrivate(GCSApplication * q_ptr);
    ~GCSApplicationPrivate();
    void setInstanceId (const QString &id);

signals:

public Q_SLOTS:

    int initControlFlow (const QCommandLineParser &parser);

private Q_SLOTS:

    // int makeMaster (const QCommandLineParser &parser);
    // int startMaster (bool isAutoStart = false , bool isRestart = false);
    // int restartMaster (const QCommandLineParser &parser);
    // int commandMaster ();
    // int purgeMaster (const QCommandLineParser &parser);

    // void newTerminalConnected ();
    // void terminalLoaded (TerminalPrivate * terminal , bool success);
    // void stopMaster (Terminal * term);
    // void doExit (int code);

    // void beginMasterConnect (const QStringList &arguments , bool isStarter);

protected:

private:

    GCSApplication * q;

    static bool p_valid;

    bool m_running;
    bool m_masterLogging;
    bool m_autoStart;
    bool m_ignoreExtraStart;
    bool m_autoDelete;
    bool m_autoKill;

    QString m_instanceId;

    static const QString m_masterArgument;
    static const QString m_purgeArgument;
    static const QString m_startArgument;
    static const QString m_restartArgument;

    static const QString m_terminalMessageFormat;
    static const QString m_masterMessageFormat;

    Logger * m_loggerService;
    static log4cxx::LoggerPtr logger;
};

#endif
