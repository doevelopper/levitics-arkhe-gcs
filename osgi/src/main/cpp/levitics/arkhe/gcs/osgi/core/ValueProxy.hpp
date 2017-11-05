#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_VALUEPROXY_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_VALUEPROXY_HPP

#include <QObject>
#include <QScopedPointer>
#include <levitics/Config.hpp>

class ValueProxyPrivate;

class EXPORT_API ValueProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double value READ value WRITE setValue NOTIFY valueChanged);
    Q_PROPERTY(double proxyValue READ proxyValue WRITE setProxyValue NOTIFY proxyValueChanged);

    public:

        explicit ValueProxy(QObject * parent = Q_NULLPTR);
// ValueProxy(const ValueProxy &) Q_DECL_EQ_DEFAULT;
// ValueProxy(ValueProxy &&) Q_DECL_EQ_DEFAULT;
// ValueProxy & operator= (const ValueProxy &) Q_DECL_EQ_DEFAULT;
// ValueProxy & operator= (ValueProxy &&) Q_DECL_EQ_DEFAULT;
        virtual ~ValueProxy();

        virtual double proxyValueFromValue (double value) const = 0;
        virtual double valueFromProxyValue (double proxyValue) const = 0;
        double value () const;
        virtual double proxyValue () const;

    public Q_SLOTS:

        void setValue (double newValue);
        void setProxyValue (double newProxyValue);

Q_SIGNALS:
        void valueChanged (double);
        void proxyValueChanged (double);

        void proxyAboutToBeModified ();
        void proxyModified ();

    protected:

        QScopedPointer<ValueProxyPrivate> d_ptr;
        void updateProxyValue ();
        void updateValue ();

    private:

        Q_DECLARE_PRIVATE(ValueProxy);
        Q_DISABLE_COPY(ValueProxy);
};

#endif
