#include <levitics/arkhe/gcs/osgi/core/private/ApplicationPrivate.hpp>

ApplicationPrivate::ApplicationPrivate( )
{
    settings = NULL;
    app = NULL;
    parser = new QCommandLineParser;
    parser->setSingleDashWordOptionMode( QCommandLineParser::ParseAsLongOptions );
}

ApplicationPrivate::~ApplicationPrivate( )
{
    if( settings )
    {
        delete settings;
    }
}

void
ApplicationPrivate::setApplication( QCoreApplication * q )
{
    app = q;
}

void
ApplicationPrivate::initialize( void )
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
