#include <levitics/arkhe/gcs/osgi/core/SharedPimplPtr.hpp>

using namespace levitics::arkhe::gcs::osgi::core;

template <typename T>
SharedPimplPtr<T>::SharedPimplPtr()
    : m_data(new T)
{
}

template <typename T>
SharedPimplPtr<T>::SharedPimplPtr(T * data)
    : m_data(data)
{
    Q_ASSERT(data != 0);
}

template <typename T>
template <typename T1>
SharedPimplPtr<T>::SharedPimplPtr(T1 arg1)
    : m_data(new T(arg1))
{
}

template <typename T>
template <typename T1, typename T2>
SharedPimplPtr<T>::SharedPimplPtr(T1 arg1, T2 arg2)
    : m_data(new T(arg1, arg2))
{
}

template <typename T>
template <typename T1, typename T2, typename T3>
SharedPimplPtr<T>::SharedPimplPtr(T1 arg1, T2 arg2, T3 arg3)
    : m_data(new T(arg1, arg2, arg3))
{
}

template <typename T>
T * SharedPimplPtr<T>::operator->()
{
    return m_data.get();
}

template <typename T>
const T * SharedPimplPtr<T>::operator->() const
{
    return m_data.get();
}

template <typename T>
T & SharedPimplPtr<T>::operator*()
{
    return *m_data;
}

template <typename T>
const T & SharedPimplPtr<T>::operator*() const
{
    return *m_data;
}

template <typename T>
void SharedPimplPtr<T>::swap(SharedPimplPtr<T> & other)
{
    m_data.swap(other.m_data);
}

template <typename T>
void SharedPimplPtr<T>::unique()
{
    if( !m_data.unique())
    {
        m_data.reset(new T(*m_data));
    }
}
