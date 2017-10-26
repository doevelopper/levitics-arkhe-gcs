#include <typeinfo>
#include <QDebug>
#include <type_traits>
#include <string>
#include <memory>
#include <system_error>
#include <levitics/arkhe/gcs/osgi/core/edac/Exception.hpp>

Exception::TraceManipulator::TraceManipulator( const Exception * e )
    :   Exc( e )
{
}

QDebug
Exception::TraceManipulator::print( QDebug dbg ) const
{
    if( Exc )
        Exc->printStackTrace( dbg );

    return dbg.maybeSpace( );
}

Exception::Exception( Exception const & )
{

}

Exception::~Exception( )
{

}

QDebug
Exception::printStackTrace( QDebug dbg ) const
{
    QSet<const Exception *> dejaVu;
    dejaVu.insert( this );
    /*
       // Print our stack trace
       dbg.nospace() << this->what() << '\n';
       QList<QString> trace = stackTrace();

       foreach(QString traceElement , trace)
       {
       dbg.nospace() << "\tat " << qPrintable(traceElement) << '\n';
       }

       // Print cause, if any
       if (NestedException)
       {
       NestedException->printEnclosedStackTrace(dbg , trace , "Caused by: " , "" , dejaVu);
       }
     */

    return dbg;

}

QString
Exception::message( ) const throw ()
{
    return m_msg;
}

Exception::TraceManipulator
Exception::printStackTrace( ) const
{
    return TraceManipulator( this );
}

Exception *
Exception::clone( ) const
{
    return new Exception( *this );
}

void
Exception::rethrow( ) const
{
    throw *this;
}

std::system_error
Exception::make_syserr( int e,
    const char * msg )
{
    return std::system_error( std::error_code( e, std::system_category( ) ), msg );
}

std::system_error
Exception::make_syserr( int e,
    const std::string & msg )
{
    return make_syserr( e, msg.c_str( ) );
}

std::system_error
Exception::make_syserr( const std::string & msg )
{
    return make_syserr( errno, msg );
}

std::system_error
Exception::make_syserr( const char * msg )
{
    return make_syserr( errno, msg );
}
