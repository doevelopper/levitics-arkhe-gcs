#include <levitics/arkhe/gcs/osgi/core/private/OSGIApplicationPrivate.hpp>

OSGIApplicationPrivate::OSGIApplicationPrivate( )
    : m_qtTranslator(Q_NULLPTR)
    , m_gcsTranslator(Q_NULLPTR)
{
    settings = NULL;
    app = NULL;
    parser = new QCommandLineParser;
    parser->setSingleDashWordOptionMode( QCommandLineParser::ParseAsLongOptions );
}

OSGIApplicationPrivate::~OSGIApplicationPrivate( )
{
    if( settings )
    {
        delete settings;
    }
}

void
OSGIApplicationPrivate::setApplication( QCoreApplication * q )
{
    app = q;
}

void
OSGIApplicationPrivate::initialize( void )
{
    qputenv( "QT_PLUGIN_PATH", "1" );
    qputenv( "LC_ALL", "C" );
    QLocale::setDefault( QLocale::c( ) );

#if defined (Q_OS_UNIX) && !defined (Q_OS_MAC)

    // to avoid troubles with floats separators ('.' and not ',')
    setlocale( LC_NUMERIC, "C" );
#endif

    parser->addHelpOption( );
    parser->addVersionOption( );

    QCommandLineOption settingsOption( "settings", "main settings file", "filename" );
    parser->addOption( settingsOption );

    QCommandLineOption nonguiOption( QStringList( ) << "nw" << "no-window", QCoreApplication::translate( "main",
                                                                                                         "non GUI application (no window)" ) );
    parser->addOption( nonguiOption );

    QString verbosity = "info";
    QCommandLineOption loglevelOption( "loglevel", "log level available: trace|debug|info|warn|error|fatal", "level",
        verbosity );
    parser->addOption( loglevelOption );
    parser->process( *app );

    if( parser->isSet( settingsOption ) )
    {
        settings = new QSettings( parser->value( settingsOption ), QSettings::IniFormat );
    }
    else
    {
        settings = new QSettings( app->organizationName( ), app->applicationName( ) );
    }
}
