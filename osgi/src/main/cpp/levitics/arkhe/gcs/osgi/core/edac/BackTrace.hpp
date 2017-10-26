#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_BACKTRACE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_BACKTRACE_HPP

#include <QScopedPointer>
#include <QString>

class BackTracePrivate;

class BackTrace
{
public:

    BackTrace ( );
    BackTrace( const BackTrace & other );
    virtual
    ~BackTrace( ) throw ();

    BackTrace( size_t framesNumber = DEFAULT_STACK_SIZE );
    size_t stackSize ( ) const;
    void * returnAddress ( unsigned frameNumber ) const;
    QString stackFrame ( unsigned frameNumber ) const;
    QList<QString> stackTrace ( ) const;

protected:

private:

    QScopedPointer<BackTracePrivate> d;
    static size_t const DEFAULT_STACK_SIZE;
};

#endif
