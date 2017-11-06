
#include <limits>
#include <levitics/arkhe/gcs/osgi/core/private/LinearValueProxyPrivate.hpp>

LinearValueProxyPrivate::LinearValueProxyPrivate(LinearValueProxy & object)
    : q_ptr(&object)
{
    this->Coefficient = 1.0;
    this->Offset = 0.0;
}

LinearValueProxyPrivate::~LinearValueProxyPrivate()
{
}

bool LinearValueProxyPrivate::isCoefficientValid() const
{
    return qAbs(this->Coefficient) > std::numeric_limits<double>::epsilon();
}
