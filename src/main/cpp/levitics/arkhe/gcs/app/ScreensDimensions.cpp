#include <levitics/arkhe/gcs/app/ScreensDimensions.hpp>
template <typename T>
log4cxx::LoggerPtr ScreensDimensions<T>::logger =
    log4cxx::Logger::getLogger(std::string("levitics.arkhe.gcs.app.ScreensDimensions"));

template <typename T>
ScreensDimensions<T>::ScreensDimensions(T w, T h, T xOff, T yOff)
    : m_width(w)
    , m_height(h)
    , m_xOffset(xOff)
    , m_yOffset(yOff)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

template <typename T>
T ScreensDimensions<T>::left() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (m_xOffset);
}

template <typename T>
T ScreensDimensions<T>::xOff() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (m_xOffset);
}

template <typename T>
T ScreensDimensions<T>::top() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (m_yOffset);
}

template <typename T>
T ScreensDimensions<T>::yOff() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (m_yOffset);
}

template <typename T>
T ScreensDimensions<T>::right() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (m_xOffset + m_width);
}

template <typename T>
T ScreensDimensions<T>::bottom() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (m_yOffset + m_height);
}

template <typename T>
QRect ScreensDimensions<T>::rect(double scale) const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (QRect(QPoint(left(), top()) * scale, QSize(m_width, m_height) * scale));
}
