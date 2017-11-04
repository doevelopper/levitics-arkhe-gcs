
#ifndef LEVITICS_ARKHE_GCS_APP_MULTISCREENMANAGEMENT_HPP
#define LEVITICS_ARKHE_GCS_APP_MULTISCREENMANAGEMENT_HPP

#include <QPoint>
#include <QRect>
#include <QWidget>
#include <QString>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QMap>
#include <QVariant>
#include <QByteArray>
#include <levitics/arkhe/gcs/osgi/core/logger/Logger.hpp>

#define MAIN_DISPLAY_WIDTH  (qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).width())
#define MAIN_DISPLAY_HEIGHT (qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).height())
#define SCREEN_DISPLAY_HEIGHT(y)  (qApp->screens() [y]->size().height())
#define SCREEN_DISPLAY_WIDTH (x) (qApp->screens() [x]->size().width())

class MultiScreenManagement
{
public:

    explicit MultiScreenManagement(QWidget * parent = Q_NULLPTR , Qt::WindowFlags f = Qt::WindowFlags());
    MultiScreenManagement(const MultiScreenManagement &) Q_DECL_EQ_DELETE;
    MultiScreenManagement(MultiScreenManagement &&) Q_DECL_EQ_DELETE;
    MultiScreenManagement & operator = (const MultiScreenManagement &) Q_DECL_EQ_DELETE;
    MultiScreenManagement & operator = (MultiScreenManagement &&) Q_DECL_EQ_DELETE;
    ~MultiScreenManagement();     // = delete;

    int screenNumber (const QPoint & pos , QWidget * w);
    QRect screenGeometry (const QPoint & pos , QWidget * w);
    QString orientation (Qt::ScreenOrientation orientation);
    QRect availableGeometry (const QPoint & pos , QWidget * w);
    void sreensInfo ();
    void centerWidgetOnGivenScreen (QWidget * w , quint8 screenIndex = 0);
    QRect monitorGeometry (quint32 monitor );
    qint32 monitorCount () const;
    auto const primaryScreen ();
    void setScreenGeometry (QWidget &wnd);
    void screenAdded (QScreen * screen);
    QPoint globalPositionToAScreenPosition (QPoint point);
    void showWidgetInTheLastScreenInFullScreenMode (QWidget * w );
    static const QScreen * effectiveScreen (const QWindow * window);
    /*!
     * @brief Resize the given window proportionally to the screen geometry
     */
    void resizeNativeWidgetWindow (QWindow * w , const QRect &previousScreenGeometry) const;
    /*!
     * @brief Resize the given window to fit the screen geometry
     */
    void resizeTopLevelWindow (QWindow * w , const QRect &previousScreenGeometry) const;
    // QString screenOrientation(Qt::ScreenOrientation orientation);
    QRect geometry () const /// Q_DECL_OVERRIDE
    {
        return m_currentGeometry;
    }
    /*!
     * @brief Move a window to a new virtual screen, accounting for varying sizes.
     */
    static void  moveToVirtualScreen (QWindow * w , const QScreen * newScreen);
    void removeScreen (int index);

protected:

private:

    const bool MULTIPLEWINDOWS;
    const bool MULTIPLESCREENS;
    qint32 m_numberOfScreens;
    QRect m_currentGeometry;
    QScreen * m_screen;
    static log4cxx::LoggerPtr logger;
    QMap<QString , QVariant> m_screensCharacteristics;
};

#endif
