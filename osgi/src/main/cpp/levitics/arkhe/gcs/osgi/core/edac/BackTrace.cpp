#include <QList>

#include <levitics/arkhe/gcs/osgi/core/edac/private/BackTracePrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/edac/BackTrace.hpp>

size_t const BackTrace::DEFAULT_STACK_SIZE = 64;

BackTrace::BackTrace( const BackTrace & other )
    :   d( new BackTracePrivate( *other.d.data( ) ) )
{
}

BackTrace::BackTrace( size_t framesNumber )
    :   d( new BackTracePrivate )
{
    if( framesNumber == 0 )
        return;

    d->Frames.resize( framesNumber, Q_NULLPTR );
    size_t size = d->trace( &d->Frames.front( ), framesNumber );
    d->Frames.resize( size );
}

BackTrace::~BackTrace( ) throw ()
{
}

size_t
BackTrace::stackSize( ) const
{
    return d->Frames.size( );
}

void *
BackTrace::returnAddress( unsigned frameNumber ) const
{
    if( frameNumber < stackSize( ) )
    {
        return d->Frames [frameNumber];
    }

    return Q_NULLPTR;
}

QString
BackTrace::stackFrame( unsigned frameNumber ) const
{
    if( frameNumber < d->Frames.size( ) )
        return QString::fromStdString( d->getSymbol( d->Frames [frameNumber] ) );

    return QString( );
}

QList<QString>
BackTrace::stackTrace( ) const
{
    QList<QString> trace;

    if( d->Frames.empty( ) )
        return trace;

    for( std::size_t i = 0; i < d->Frames.size( ); ++i )
    {
        std::string s = d->getSymbol( d->Frames [i] );

        if( !s.empty( ) )
        {
            trace.push_back( QString::fromStdString( s ) );
        }
    }

    return trace;

    // std::ostringstream res;
    // d->writeSymbols(&d->Frames.front(), d->Frames.size(), res, framePrefix.toStdString());
    // return QString::fromStdString(res.str());
}
