#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_LINEARVALUEPROXYPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_LINEARVALUEPROXYPRIVATE_HPP

#include <QObject>
#include <QScopedPointer>
#include <levitics/Config.hpp>
#include <levitics/arkhe/gcs/osgi/core/LinearValueProxy.hpp>
class EXPORT_API LinearValueProxyPrivate
{
    Q_DECLARE_PUBLIC(LinearValueProxy);

    protected:

        LinearValueProxy * q_ptr;

    public:

        LinearValueProxyPrivate(LinearValueProxy & object);
        ~LinearValueProxyPrivate();

        bool isCoefficientValid () const;

        double Coefficient;
        double Offset;
};

#endif
