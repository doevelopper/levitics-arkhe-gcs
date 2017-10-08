
#include <QApplication>
#include <QLayout>
#include <QMenu>
#include <levitics/app/private/MainWindowPrivate.hpp>

log4cxx::LoggerPtr MainWindowPrivate::logger =
    log4cxx::Logger::getLogger(std::string("levitics.app.private.MainWindowPrivate"));

/*
   MainWindowPrivate::MainWindowPrivate()
    : ui{new Ui::MainWindow}
   {
   }
 */

MainWindowPrivate::MainWindowPrivate(MainWindow * mainWindow)
    : QObject(mainWindow)
    , m_mainWindow(mainWindow)
    //    , m_statusBar(nullptr)
    , m_changingActiveView(false)

{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

MainWindowPrivate::~MainWindowPrivate()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MainWindowPrivate::setupGui ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    //    m_statusBar = new KDevelop::StatusBar(m_mainWindow);
    //    setupStatusBar();
}

void
MainWindowPrivate::setupStatusBar ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    // QWidget * location = m_mainWindow->statusBarLocation();

    //    if (m_statusBar)
    //        location->layout()->addWidget(m_statusBar);
}

void
MainWindowPrivate::split (Qt::Orientation orientation)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void
MainWindowPrivate::toggleFullScreen (bool fullScreen)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}
