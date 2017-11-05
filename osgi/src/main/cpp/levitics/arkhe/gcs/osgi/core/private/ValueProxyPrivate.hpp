#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_VALUEPROXYPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_VALUEPROXYPRIVATE_HPP

#include <QObject>
#include <QScopedPointer>
#include <levitics/Config.hpp>
#include <levitics/arkhe/gcs/osgi/core/ValueProxy.hpp>
class EXPORT_API ValueProxyPrivate
{
    Q_DECLARE_PUBLIC(ValueProxy);

    public:

        ValueProxy * q_ptr;
        ValueProxyPrivate(ValueProxy & object);
        ~ValueProxyPrivate();

        double Value;
        double ProxyValue;
};


#endif
