#include <levitics/arkhe/gcs/osgi/core/private/ValueProxyPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/ValueProxy.hpp>
ValueProxyPrivate::ValueProxyPrivate(ValueProxy & object)
    : q_ptr(&object)
{
    this->Value = 0.0;
    this->ProxyValue = 0.0;
}

ValueProxyPrivate::~ValueProxyPrivate()
{
}
