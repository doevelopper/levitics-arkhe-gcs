
#include <QStyleHints>
#include <QScopedPointer>
#include <QGuiApplication>
#include <QWindow>
#include <QDesktopWidget>
// #include <QHighDpiScaling>
// #include <qpa/qplatformwindow.h>
#include <levitics/arkhe/gcs/app/MultiScreenManagement.hpp>

log4cxx::LoggerPtr MultiScreenManagement::logger =
    log4cxx::Logger::getLogger(std::string("levitics.app.MultiScreenManagement"));

MultiScreenManagement::MultiScreenManagement(QWidget * parent ,
                                             Qt::WindowFlags f)
    : MULTIPLEWINDOWS (QGuiApplication::arguments().contains(QStringLiteral("--multiple")))
    , MULTIPLESCREENS (QGuiApplication::arguments().contains(QStringLiteral("--multiscreen")))
    , m_screen()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    m_numberOfScreens = QApplication::desktop()->screenCount();
}

void MultiScreenManagement::resizeNativeWidgetWindow (QWindow * w ,
                                                      const QRect &previousScreenGeometry) const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const qreal relativeX = static_cast<qreal>(w->geometry().topLeft().x()) / previousScreenGeometry.width();
    const qreal relativeY = static_cast<qreal>(w->geometry().topLeft().y()) / previousScreenGeometry.height();
    const qreal relativeWidth = static_cast<qreal>(w->geometry().width()) / previousScreenGeometry.width();
    const qreal relativeHeight = static_cast<qreal>(w->geometry().height()) / previousScreenGeometry.height();

    //    const QRect windowGeometry(relativeX * geometry().width() , relativeY * geometry().height() ,
    //                               relativeWidth * geometry().width() , relativeHeight * geometry().height());

    // w->setGeometry(windowGeometry);
}

void MultiScreenManagement::resizeTopLevelWindow (QWindow * w ,
                                                  const QRect &previousScreenGeometry) const
{
    QRect windowGeometry = w->geometry();

    const qreal relativeCenterX = static_cast<qreal>(w->geometry().center().x()) / previousScreenGeometry.width();
    const qreal relativeCenterY = static_cast<qreal>(w->geometry().center().y()) / previousScreenGeometry.height();
    //    const QPoint newCenter(relativeCenterX * geometry().width(), relativeCenterY * geometry().height());

}

void MultiScreenManagement::moveToVirtualScreen (QWindow * w ,
                                                 const QScreen * newScreen)
{
    QRect geometry = w->geometry();
    const QRect oldScreenGeometry = w->screen()->geometry();
    const QRect newScreenGeometry = newScreen->geometry();
    QPoint relativePosition = geometry.topLeft() - oldScreenGeometry.topLeft();

    if (oldScreenGeometry.size() != newScreenGeometry.size())
    {
        const qreal factor =
            qreal(QPoint(newScreenGeometry.width() , newScreenGeometry.height()).manhattanLength()) /
            qreal(QPoint(oldScreenGeometry.width() , oldScreenGeometry.height()).manhattanLength());
        relativePosition = (QPointF(relativePosition) * factor).toPoint();
    }

    geometry.moveTopLeft(relativePosition);
    w->setGeometry(geometry);
}

MultiScreenManagement::~MultiScreenManagement()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MultiScreenManagement::removeScreen (int index)
{
    /*
       QScreen * screen = m_screens.at(index)->screen();
       QScreen * primaryScreen = QGuiApplication::primaryScreen();

       if (screen != primaryScreen)
       {
        unsigned movedWindowCount = 0;
        foreach (QWindow *w , QGuiApplication::topLevelWindows())
        {
            if (w->screen() == screen && w->handle() && w->type() != Qt::Desktop)
            {
                if (w->isVisible() && w->windowState() != Qt::WindowMinimized
                    && (QWindowsWindow::baseWindowOf(w)->exStyle() & WS_EX_TOOLWINDOW))
                {
                    moveToVirtualScreen(w , primaryScreen);
                }
                else
                {
                    QWindowSystemInterface::handleWindowScreenChanged(w , primaryScreen);
                }

     ++movedWindowCount;
            }
        }

        if (movedWindowCount)
            QWindowSystemInterface::flushWindowSystemEvents();
       }*/

}

int MultiScreenManagement::screenNumber (const QPoint & pos ,
                                         QWidget *      w)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if ( QApplication::desktop()->isVirtualDesktop() )
    {
        return QApplication::desktop()->screenNumber(pos);
    }
    else
    {
        return QApplication::desktop()->screenNumber(w);
    }
}

QRect MultiScreenManagement::screenGeometry (const QPoint & pos ,
                                             QWidget *      w)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    return QApplication::desktop()->screenGeometry(screenNumber(pos , w));
}

QRect MultiScreenManagement::availableGeometry (const QPoint & pos ,
                                                QWidget *      w)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    return QApplication::desktop()->availableGeometry(screenNumber(pos , w));
}

QString MultiScreenManagement::orientation (Qt::ScreenOrientation orientation)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    switch ( orientation )
    {
    case Qt::PrimaryOrientation :

        return "Primary";

    case Qt::LandscapeOrientation :

        return "Landscape";

    case Qt::PortraitOrientation :

        return "Portrait";

    case Qt::InvertedLandscapeOrientation :

        return "Inverted landscape";

    case Qt::InvertedPortraitOrientation :

        return "Inverted portrait";

    default :

        return "Unknown";
    }
}

void MultiScreenManagement::centerWidgetOnGivenScreen (QWidget * w ,
                                                       quint8 screenIndex)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QPoint offset = QPoint(w->width() / 2 , w->height() / 2);
    w->move(QGuiApplication::primaryScreen()->availableGeometry().center() - offset);

    QRect geometry = QGuiApplication::primaryScreen()->availableGeometry();

    if ( !QGuiApplication::styleHints()->showIsFullScreen() )
    {
        const QSize size   = geometry.size() * 4 / 5;
        const QSize offset = (geometry.size() - size) / 2;
        const QPoint pos   = geometry.topLeft() + QPoint(offset.width() , offset.height());
        geometry = QRect(pos , size);
    }

}

void MultiScreenManagement::showWidgetInTheLastScreenInFullScreenMode (QWidget * w )
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // w->windowHandle()->setScreen(qApp->screens().last());
    // w->showFullScreen();

    // Here is how to show your widget in the last screen in full-screen mode :

    // QWidget * widget = new QWidget();
    // widget->show();
    // widget->windowHandle()->setScreen(qApp->screens().last());
    // widget->showFullScreen();

    // Or in the second screen :

    // QWidget * widget = new QWidget();
    // widget->show();
    // widget->windowHandle()->setScreen(qApp->screens()[1]);
    // widget->showFullScreen();
}

QPoint MultiScreenManagement::globalPositionToAScreenPosition (QPoint point)
{
    return point - QApplication::desktop()->screenGeometry(point).topLeft();
}

QRect MultiScreenManagement::monitorGeometry (quint32 monitor )
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // QApplication::primaryScreen()->physicalDotsPerInch();
    QRect rectangle = QApplication::desktop()->screenGeometry(monitor);

    return { rectangle.x() , rectangle.y() , rectangle.width() , rectangle.height() };  // ???

    auto ppi = QApplication::primaryScreen()->logicalDotsPerInch();
}

qint32 MultiScreenManagement::monitorCount() const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    return QApplication::desktop()->screenCount();
}

auto const MultiScreenManagement::primaryScreen ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return (QGuiApplication::primaryScreen());
}

void MultiScreenManagement::setScreenGeometry (QWidget & wnd)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // wnd.setGeometry(screen->availableVirtualGeometry());
    //    window->setFlags(    (window->flags() & ~Qt::WindowTitleHint) | Qt::FramelessWindowHint );
}

void MultiScreenManagement::screenAdded (QScreen * screen)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    screen->setOrientationUpdateMask((Qt::ScreenOrientations)0x0F);
    LOG4CXX_INFO(logger ,
                 "Screen added:" << screen->name().toStdString() <<" Siblings: "<<screen->virtualSiblings().count() << " First:" <<
                 (screen->virtualSiblings().isEmpty() ? "None" : screen->virtualSiblings().first()->name().toStdString()));
}

const QScreen * MultiScreenManagement::effectiveScreen (const QWindow * window)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if (!window)
    {
        return QGuiApplication::primaryScreen();
    }

    const QScreen * screen = window->screen();

    if (!screen)
    {
        return QGuiApplication::primaryScreen();
    }

    if (screen != QGuiApplication::primaryScreen())
    {
        return screen;
    }

 #ifndef QT_NO_CURSOR
        const QList<QScreen *> siblings = screen->virtualSiblings();

        if (siblings.size() > 1)
        {
            const QPoint referencePoint =
                window->transientParent() ? window->transientParent()->geometry().center() : QCursor::pos();

            for (const QScreen * sibling : siblings)
            {
                if (sibling->geometry().contains(referencePoint))
                {
                    return sibling;
                }
            }
        }

 #endif
    return screen;
}

void MultiScreenManagement::sreensInfo ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    //    QList<QScreen *> screens = qApp->screens();
    //    LOG4CXX_INFO(logger, "Number of screens:" << screens.size());
    LOG4CXX_DEBUG(logger , "Screens: "<<m_numberOfScreens<<" X Windows: " <<MULTIPLEWINDOWS <<" X Screens: "<<
                  MULTIPLESCREENS);
    // LOG4CXX_INFO(logger , "Number of screens:" << m_screen->name().toStdString());
    LOG4CXX_INFO(logger , "Number of screens:" << QApplication::desktop()->screenCount());
    LOG4CXX_INFO(logger , "Number of screens:" << QGuiApplication::screens().size());
    LOG4CXX_INFO(logger , "The primary screen is " << QGuiApplication::primaryScreen()->name().toStdString());

    foreach (QScreen * screen , QGuiApplication::screens())
    {
        this->screenAdded(screen);
        LOG4CXX_INFO(logger , "Information for screen:" << screen->name().toStdString());

        LOG4CXX_INFO(logger ,
                     "Available geometry: X=" << screen->availableGeometry().x() <<" Y="<< screen->availableGeometry().y() << " Resolutions: "<<
                     screen->availableGeometry().width() << "x" << screen->availableGeometry().height()
                     );
        LOG4CXX_INFO(logger ,
                     "Available size:" << screen->availableSize().width() << "x" << screen->availableSize().height()
                     );
        LOG4CXX_INFO(logger ,
                     "Available virtual geometry X:" << screen->availableVirtualGeometry().x() << " Y:" <<
                     screen->availableVirtualGeometry().y() << " Res: "<< screen->availableVirtualGeometry().width() << "x" <<
                     screen->availableVirtualGeometry().height()
                     );
        LOG4CXX_INFO(logger , "Available virtual size:" << screen->availableVirtualSize().width() << "x" <<
                     screen->availableVirtualSize().height()
                     );
        LOG4CXX_INFO(logger , "Depth:" << screen->depth() << "bits");
        LOG4CXX_INFO(logger ,
                     "Geometry X:" << screen->geometry().x() <<" Y:"<< screen->geometry().y() <<" Res: "<< screen->geometry().width() <<
                     "x" << screen->geometry().height()
                     );
        LOG4CXX_INFO(logger , "Logical DPI:" << screen->logicalDotsPerInch());
        LOG4CXX_INFO(logger , "Logical DPI X:" << screen->logicalDotsPerInchX());
        LOG4CXX_INFO(logger , "Logical DPI Y:" << screen->logicalDotsPerInchY());
        LOG4CXX_INFO(logger , "Orientation:" << this->orientation(screen->orientation()).toStdString());
        LOG4CXX_INFO(logger , "Physical DPI:" << screen->physicalDotsPerInch());
        LOG4CXX_INFO(logger , "Physical DPI X:" << screen->physicalDotsPerInchX());
        LOG4CXX_INFO(logger , "Physical DPI Y:" << screen->physicalDotsPerInchY());
        LOG4CXX_INFO(logger , "DPR=" << screen->devicePixelRatio());

        if (0 /*QHighDpiScaling::isActive()*/)
        {
            LOG4CXX_INFO(logger , "Factor=: " << "QHighDpiScaling::factor(screen)");
        }
        else
        {
            LOG4CXX_WARN(logger , "No scaling Factor");
        }

        LOG4CXX_INFO(logger ,
                     "Physical size:" << screen->physicalSize().width() << "x" << screen->physicalSize().height() <<
                     "mm"
                     );
        LOG4CXX_INFO(logger ,
                     "Primary orientation:" << this->orientation(screen->primaryOrientation()).toStdString()
                     );
        LOG4CXX_INFO(logger , "Refresh rate:" << screen->refreshRate() << "Hz");
        LOG4CXX_INFO(logger , "Size:" << screen->size().width() << "x" << screen->size().height());
        LOG4CXX_INFO(logger , "Virtual geometry:" << screen->virtualGeometry().x() << screen->virtualGeometry().y() <<
                     screen->virtualGeometry().width() << "x" << screen->virtualGeometry().height()
                     );
        LOG4CXX_INFO(logger ,
                     "Virtual size:" << screen->virtualSize().width() << "x" << screen->virtualSize().height()
                     );
    }
}
