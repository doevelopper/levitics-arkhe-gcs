#include <levitics/arkhe/gcs/osgi/core/PimplPtr.hpp>

using namespace levitics::arkhe::gcs::osgi::core;

template <typename T>
PimplPtr<T>::PimplPtr()
    : m_data(new T)
{
}

template <typename T>
PimplPtr<T>::PimplPtr(T * data)
    : m_data(data)
{
    Q_ASSERT(data != 0);
}

template <typename T>
PimplPtr<T>::PimplPtr(const PimplPtr<T> & copy)
    : m_data(new T(*copy.m_data))
{
}

template <typename T>
template <typename A1>
PimplPtr<T>::PimplPtr(A1 argument1)
    : m_data(new T(argument1))
{
}

template <typename T>
template <typename A1, typename A2>
PimplPtr<T>::PimplPtr(A1 argument1, A2 argument2)
    : m_data(new T(argument1, argument2))
{
}

template <typename T>
template <typename A1, typename A2, typename A3>
PimplPtr<T>::PimplPtr(A1 argument1, A2 argument2, A3 argument3)
    : m_data(new T(argument1, argument2, argument3))
{
}

template <typename T>
T * PimplPtr<T>::operator->()
{
    return m_data.get();
}

template <typename T>
const T * PimplPtr<T>::operator->() const
{
    return m_data.get();
}

template <typename T>
T & PimplPtr<T>::operator*()
{
    return *m_data;
}

template <typename T>
const T & PimplPtr<T>::operator*() const
{
    return *m_data;
}

template <typename T>
void PimplPtr<T>::swap(PimplPtr<T> & other)
{
    m_data.swap(other.m_data);
}
