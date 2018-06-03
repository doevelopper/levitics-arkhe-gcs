
#include <QAction>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QDockWidget>
#include <QEvent>
#include <QFlags>
#include <QRect>
#include <QTabBar>
#include <QTabWidget>
#include <QWidget>
#include <algorithm>
#include <levitics/app/View.hpp>

#include <iterator>
#include <qcoreevent.h>
#include <qnamespace.h>
#include <set>

log4cxx::LoggerPtr View::logger =
    log4cxx::Logger::getLogger(std::string("levitics.app.View"));

// Q_GLOBAL_STATIC(View, theViewManager)

// View * View::m_instance = Q_NULLPTR;


// void Widget::moveToCenter()
// {
// move(qApp->desktop()->availableGeometry(this).center()-rect().center());
// }

View::View(QObject * parent)
    : QMainWindow{}
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // setObjectName("View");
    // this->setWindowIcon(QIcon("://i-score.png"));

    //    QString version = QString{"%1.%2.%3-%4" }
    //    .arg(PROJECT_VERSION_MAJOR)
    //    .arg(PROJECT_VERSION_MINOR)
    //    .arg(PROJECT_VERSION_MICRO)
    //    .arg(PROJECT_VERSION_PATCH);

    auto title = tr("ARKHE GCS View %1").arg(APP_VERSION_STR);
    this->setWindowIconText(title);
    this->setWindowTitle(title);
    LOG4CXX_DEBUG(logger , title.toStdString());

    setDockOptions(QMainWindow::ForceTabbedDocks | QMainWindow::VerticalTabs);
    setCorner(Qt::BottomLeftCorner , Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner , Qt::RightDockWidgetArea);

    QDesktopWidget w;
    auto rect = w.availableGeometry();
    this->resize( static_cast<int>(rect.width() * 0.75) , static_cast<int>(rect.height() * 0.75));

    // setCentralWidget(m_tabWidget);
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

View::~View()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

// View * View::instance()
// {
// if( Q_NULLPTR == View::m_instance)
// {
//// MainWindow::m_instance = new (nothrow) MainWindow();
//    View::m_instance = new View();
// }
// return View::m_instance;

//   // return theMainwindowManager;
// }

/*
   void View::closeEvent(QCloseEvent* ev)
   {
   // if (m_presenter->exit())
   // {
    // ev->accept();
   // }
   // else
   // {
    // ev->ignore();
   // }
   }


   void View::changeEvent(QEvent* ev)
   {
        if (ev->type() == QEvent::ActivationChange)
        {
                // for(GUIApplicationPlugin* ctrl : m_presenter->applicationContext().guiApplicationPlugins())
                {
                        // ctrl->on_activeWindowChanged();
                }
        }

        QMainWindow::changeEvent(ev);
   }

   void View::resizeEvent(QResizeEvent* e)
   {
        QMainWindow::resizeEvent(e);
        emit sizeChanged(e->size());
   }
 */
