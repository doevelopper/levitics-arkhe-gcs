
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_EXCEPTION_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_EDAC_EXCEPTION_HPP

#include <QObject>
#include <QException>

#include <levitics/arkhe/gcs/osgi/core/edac/BackTrace.hpp>

class Exception : public QException
{
public:

    class TraceManipulator
    {
	public:

        TraceManipulator(const Exception * e);
        QDebug print (QDebug dbg) const;

	private:

        const Exception * Exc;
    };

    using Superclass = QException;

    Exception ();
    Exception(const QString & msg);
    Exception(const QString & msg , const Exception & cause);
    Exception(const Exception & o);
    Exception & operator = (const Exception & o);
    virtual ~Exception () throw ();

    // virtual const char * name () const throw ();
    // virtual const char * className () const throw ();
    // virtual const char * what () const throw ();

    TraceManipulator printStackTrace () const;

    const Exception * cause () const throw ();
    void setCause (const Exception & cause);
    virtual Exception * clone () const;
    virtual void rethrow () const;
    QString message () const throw ();
    std::system_error make_syserr (int e , const char * msg);
    std::system_error make_syserr (int e , const std::string & msg);
    std::system_error make_syserr (const std::string & msg);
    std::system_error make_syserr (const char * msg);

protected:

    virtual QDebug printStackTrace (QDebug dbg) const;

private:

    QString m_msg;
    mutable std::string m_hatMsg;
    Exception * m_nestedException;

    void printEnclosedStackTrace (QDebug dbg , const QList<QString> & enclosingTrace ,
                                  const QString & caption , const QString & prefix ,
                                  QSet<const Exception *> & dejaVu);
};

#define DECLARE_EXCEPTION(API , CLS , BASE)             	\
    class API CLS : public BASE                         	\
    {                                                   	\
public:                                             		\
        explicit CLS(const QString &msg);                 	\
        CLS(const QString &msg , const Exception &exc); 	\
        CLS(const CLS &exc);                              	\
        ~CLS() throw ();                                   	\
        CLS & operator = (const CLS & exc);                 \
        const char * name() const throw ();                 \
        CLS * clone() const;                               	\
        void rethrow() const;                            	\
    };

#define IMPLEMENT_EXCEPTION(CLS , BASE , NAME)              \
    CLS::CLS(const QString & msg)                           \
        : BASE(msg)                                         \
    { }                                                     \
    CLS::CLS(const QString & msg , 							\
             const Exception & exc)                   		\
        : BASE(msg , exc)                                   \
    { }                                                     \
    CLS::CLS(const CLS & exc)                              	\
        : BASE(exc)                                         \
    { }                                                     \
    CLS::~CLS() throw ()                                    \
    { }                                                     \
    CLS & CLS::operator = (const CLS & exc)                 \
    {                                                       \
        BASE::operator = (exc);                             \
        return *this;                                       \
    }                                                       \
    const char * CLS::name() const throw ()                 \
          {                                                 \
              return NAME;                                  \
          }                                                 \
          CLS * CLS::clone() const                          \
          {                                                 \
              return new CLS(*this);                        \
          }                                                 \
          void CLS::rethrow() const                         \
          {                                                 \
              throw *this;                                  \
          }

// DECLARE_EXCEPTION(GCS_CORE_EXPORT, UnsupportedOperationException, Exception)
// DECLARE_EXCEPTION(GCS_CORE_EXPORT, RuntimeException, Exception)
// DECLARE_EXCEPTION(GCS_CORE_EXPORT, InvalidArgumentException, RuntimeException)
// DECLARE_EXCEPTION(GCS_CORE_EXPORT, IllegalStateException, RuntimeException)


#endif
