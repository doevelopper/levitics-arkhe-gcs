#include <levitics/arkhe/gcs/osgi/core/logger/private/LogViewPrivate.hpp>

LogViewPrivate::LogViewPrivate( )
{

}

LogViewPrivate::~LogViewPrivate( )
{

}

QRegExp
LogViewPrivate::expression( void )
{
    if( this->exclude.isEmpty( ) )
    {
        return (QRegExp( ) );
    }

    QString patterns;

    foreach(QString pattern, this->exclude)
    {
        patterns.append( QString( "%1|" ).arg( pattern ) );
    }

    patterns.chop( 1 );

    return QRegExp( QString( "^(?!%1).*" ).arg( patterns ), Qt::CaseSensitive, QRegExp::RegExp2 );
}
