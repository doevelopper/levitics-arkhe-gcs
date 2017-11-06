#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LINEARVALUEPROXY_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LINEARVALUEPROXY_HPP

#include <QObject>
#include <QScopedPointer>
#include <levitics/Config.hpp>
#include <levitics/arkhe/gcs/osgi/core/ValueProxy.hpp>

class LinearValueProxyPrivate;

class EXPORT_API LinearValueProxy : public ValueProxy
{
    Q_OBJECT
    Q_PROPERTY(double coefficient READ coefficient WRITE setCoefficient)
    Q_PROPERTY(double offset READ offset WRITE setOffset)

    public:

        explicit LinearValueProxy(QObject * parent = Q_NULLPTR);
        virtual ~LinearValueProxy();

        virtual double proxyValueFromValue (double value) const;

        virtual double valueFromProxyValue (double proxyValue) const;

        virtual double coefficient () const;
        virtual double offset () const;

    public Q_SLOTS:

        virtual void setCoefficient (double newCoeff);
        virtual void setOffset (double newOffset);

    protected:

        QScopedPointer<LinearValueProxyPrivate> d_ptr;

    private:

        Q_DECLARE_PRIVATE(LinearValueProxy);
        Q_DISABLE_COPY(LinearValueProxy);
};
#endif
