#include <levitics/arkhe/gcs/osgi/core/ValueProxy.hpp>
#include <levitics/arkhe/gcs/osgi/core/private/ValueProxyPrivate.hpp>
ValueProxy::ValueProxy(QObject * _parent)
    : QObject(_parent)
    , d_ptr(new ValueProxyPrivate(*this))
{
}

ValueProxy::~ValueProxy()
{
}

double ValueProxy::value() const
{
    Q_D(const ValueProxy);
    return d->Value;
}

void ValueProxy::setValue(double newValue)
{
    Q_D(ValueProxy);
    if( d->Value == newValue )
    {
        return;
    }

    d->Value = newValue;
    emit this->valueChanged(d->Value);
    this->updateProxyValue();
}

double ValueProxy::proxyValue() const
{
    Q_D(const ValueProxy);
    return d->ProxyValue;
}

void ValueProxy::setProxyValue(double newProxyValue)
{
    Q_D(ValueProxy);
    if( d->ProxyValue == newProxyValue )
    {
        return;
    }

    d->ProxyValue = newProxyValue;
    emit this->proxyValueChanged(d->ProxyValue);
    this->updateValue();
}

void ValueProxy::updateProxyValue()
{
    Q_D(ValueProxy);
    double newProxyValue = this->proxyValueFromValue(d->Value);
    if( newProxyValue == d->ProxyValue )
    {
        return;
    }

    d->ProxyValue = newProxyValue;
    emit this->proxyValueChanged(d->ProxyValue);
}

void ValueProxy::updateValue()
{
    Q_D(ValueProxy);
    double newValue = this->valueFromProxyValue(d->ProxyValue);
    if( newValue == d->Value )
    {
        return;
    }

    d->Value = newValue;
    emit this->valueChanged(d->Value);
}
