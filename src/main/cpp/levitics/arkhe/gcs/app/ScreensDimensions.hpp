
#ifndef LEVITICS_ARKHE_GCS_APP_SCREENSDIMENSIONS_HPP
#define LEVITICS_ARKHE_GCS_APP_SCREENSDIMENSIONS_HPP

#include <QRect>
#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

template <typename T>
class ScreensDimensions
{
public:

    explicit ScreensDimensions(QWidget * parent = Q_NULLPTR);
    ScreensDimensions(const ScreensDimensions &) Q_DECL_EQ_DELETE;
    ScreensDimensions(ScreensDimensions &&) Q_DECL_EQ_DELETE;
    ScreensDimensions & operator = (const ScreensDimensions &) Q_DECL_EQ_DELETE;
    ScreensDimensions & operator = (ScreensDimensions &&) Q_DECL_EQ_DELETE;
    ~ScreensDimensions();     // = delete;
    ScreensDimensions(T w, T h, T xOff = 0, T yOff = 0);

     T left() const;
     T xOff() const;
     T top() const;
     T yOff() const;
     T right() const;
     T bottom() const;
     QRect rect(double scale = 1) const;
     void validate() const Q_DECL_NOEXCEPT_EXPR(false);
private:
    T m_width = 0;
    T m_height = 0;
    T m_xOffset = 0;
    T m_yOffset = 0;

    static log4cxx::LoggerPtr logger;
};
#endif
