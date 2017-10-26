#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

Logger::Logger( QObject * _parent )
    :   Superclass( _parent )
    , d_ptr( new LoggerPrivate )
{
    Q_D( Logger );

    // d->loggerSvce = log4cxx::Logger::getLogger (name.toStdString().c_str());
}

Logger::~Logger( )
{
    Q_D( Logger );
}

void
Logger::configure( )
{
    // Log4Qt::BasicConfigurator::configure();
}

void
Logger::debug( const QString & s )
{
    Q_D( Logger );
    d->loggerSvce->debug( s.toStdString( ) );
}

void
Logger::info( const QString & s )
{
    Q_D( Logger );
    d->loggerSvce->info( s.toStdString( ) );
}

void
Logger::trace( const QString & s )
{
    Q_D( Logger );
    d->loggerSvce->trace( s.toStdString( ) );
}

void
Logger::warn( const QString & s )
{
    Q_D( Logger );
    d->loggerSvce->warn( s.toStdString( ) );
}

void
Logger::error( const QString & s )
{
    Q_D( Logger );
    d->loggerSvce->error( s.toStdString( ) );
}

void
Logger::fatal( const QString & s )
{
    Q_D( Logger );
    d->loggerSvce->fatal( s.toStdString( ) );
}
