
#include <levitics/arkhe/gcs/osgi/core/private/LinearValueProxyPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/LinearValueProxy.hpp>

LinearValueProxy::LinearValueProxy(QObject * parent)
    : ValueProxy(parent)
    , d_ptr(new LinearValueProxyPrivate(*this))
{
}

LinearValueProxy::~LinearValueProxy()
{
}

double LinearValueProxy::proxyValueFromValue(double value) const
{
    return (this->coefficient() * value) + this->offset();
}

double LinearValueProxy::valueFromProxyValue(double proxyValue) const
{
    return (proxyValue - this->offset()) / this->coefficient();
}

double LinearValueProxy::coefficient() const
{
    Q_D(const LinearValueProxy);
    return d->Coefficient;
}

double LinearValueProxy::offset() const
{
    Q_D(const LinearValueProxy);
    return d->Offset;
}

void LinearValueProxy::setCoefficient(double newCoeff)
{
    Q_D(LinearValueProxy);
    if( d->Coefficient == newCoeff )
    {
        return;
    }
    emit proxyAboutToBeModified();
    d->Coefficient = newCoeff;
    this->updateProxyValue();
    emit proxyModified();
}

void LinearValueProxy::setOffset(double newOffset)
{
    Q_D(LinearValueProxy);
    if( d->Offset == newOffset )
    {
        return;
    }
    emit proxyAboutToBeModified();
    d->Offset = newOffset;
    this->updateProxyValue();
    emit proxyModified();
}
