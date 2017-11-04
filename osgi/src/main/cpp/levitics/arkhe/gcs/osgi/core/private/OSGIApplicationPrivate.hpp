#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_OSGIAPPLICATIONPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_OSGIAPPLICATIONPRIVATE_HPP

#include <levitics/Config.hpp>
#include <QSettings>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QtCore>
#include <QLibraryInfo>
#include <QTranslator>
#include <QLocale>

class Application;

class EXPORT_API OSGIApplicationPrivate
{
    public:

        OSGIApplicationPrivate( );
        OSGIApplicationPrivate( OSGIApplicationPrivate * q = Q_NULLPTR );
        virtual ~OSGIApplicationPrivate( );

        virtual void initialize ( void );
        void setApplication ( QCoreApplication * app );

        QSettings * settings;
        QCommandLineParser * parser;
        QCoreApplication * app;

        // Translation support.
        QTranslator * m_qtTranslator;
        QTranslator * m_gcsTranslator;
};

#endif
