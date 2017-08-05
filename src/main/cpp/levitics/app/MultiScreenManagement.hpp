
#ifndef LEVITICS_APP_MULTISCREENMANAGEMENT_HPP
#define LEVITICS_APP_MULTISCREENMANAGEMENT_HPP

#include <QPoint>
#include <QRect>
#include <QWidget>
#include <QString>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

#include <levitics/osgi/core/logger/Logger.hpp>

#define MAIN_DISPLAY_WIDTH  (qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).width())
#define MAIN_DISPLAY_HEIGHT (qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).height())

#define SCREEN_DISPLAY_HEIGHT(y)  (qApp->screens() [y]->size().height())
#define SCREEN_DISPLAY_WIDTH (x) (qApp->screens() [x]->size().width())

class MultiScreenManagement
{
public:

    explicit MultiScreenManagement(QWidget * parent = Q_NULLPTR , Qt::WindowFlags f = Qt::WindowFlags());
    MultiScreenManagement(const MultiScreenManagement &) = delete;
    MultiScreenManagement(MultiScreenManagement &&) = delete;
    MultiScreenManagement & operator = (const MultiScreenManagement &) = delete;
    MultiScreenManagement & operator = (MultiScreenManagement &&) = delete;
    ~MultiScreenManagement();     // = delete;

    int screenNumber (const QPoint & pos , QWidget * w);
    QRect screenGeometry (const QPoint & pos , QWidget * w);
    QString orientation (Qt::ScreenOrientation orientation);
    void sreensInfo ();
    void centerWidgetOnGivenScreen (QWidget * w , quint8 screenIndex = 0);
    QRect monitorGeometry (quint32 monitor );
    quint16 monitorCount () const;
    void screenAdded (QScreen * screen);
    QPoint globalPositionToAScreenPosition (QPoint point);
    void showWidgetInTheLastScreenInFullScreenMode (QWidget * w );
    // QString screenOrientation(Qt::ScreenOrientation orientation);

protected:

private:

    QScreen * m_screen;
    static log4cxx::LoggerPtr logger;
};

#endif
