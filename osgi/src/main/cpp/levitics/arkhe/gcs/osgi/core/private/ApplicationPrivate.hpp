#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_APPLICATIONPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_APPLICATIONPRIVATE_HPP

#include <levitics/Config.hpp>
#include <QSettings>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QtCore>

class Application;

class EXPORT_API ApplicationPrivate
{
public:
    ApplicationPrivate();
    ApplicationPrivate(ApplicationPrivate *q = Q_NULLPTR);
    virtual ~ApplicationPrivate();

    virtual void initialize(void);
    void setApplication(QCoreApplication *app);

    QSettings *settings;
    QCommandLineParser *parser;
    QCoreApplication *app;
};

#endif
