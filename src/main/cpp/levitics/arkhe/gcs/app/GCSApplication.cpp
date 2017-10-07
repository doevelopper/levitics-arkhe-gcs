
#include <QCommandLineParser>
#include <levitics/app/GCSApplication.hpp>
#include <levitics/app/MultiScreenManagement.hpp>
#include <levitics/app/private/GCSApplicationPrivate.hpp>

log4cxx::LoggerPtr GCSApplication::logger =
    log4cxx::Logger::getLogger(std::string("levitics.app.GCSApplication"));

// #ifndef QIMSYS_NO_GUI
//    : QApplication(argc, argv)
// #else
//    : QCoreApplication(argc, argv)
// #endif

GCSApplication::GCSApplication(int &  argc ,
                               char * *  argv ,
                               Qt::WindowFlags f)
    :  QApplication(argc , argv , f)
    , d(new GCSApplicationPrivate(this))
    , m_multiScreenManagement(new MultiScreenManagement())
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    m_multiScreenManagement->sreensInfo();

    //    QLocale us(QLocale::English,QLocale::UnitedStates);
    //    QLocale::setDefault(us);
    Version ver;
    LOG4CXX_INFO(logger , "Dvcs info: " << ver.getRevString());
    LOG4CXX_INFO(logger , "Release: "<< VERSION_HEX);
    LOG4CXX_INFO(logger , "Dev info: " << ver.getABI().toStdString());
    LOG4CXX_WARN(logger , "Locale: " << QLocale::system().name().toStdString());
    LOG4CXX_WARN(logger , "Country: " << QLocale::system().country());
    //    this->init();
}

GCSApplication::~GCSApplication()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if ( m_multiScreenManagement )
    {
        delete m_multiScreenManagement;
    }

    if (  m_view)
    {
        delete m_view;
    }

    if (  m_MainWindow)
    {
        delete m_MainWindow;
    }

    //    this->setParent(Q_NULLPTR);
}

void GCSApplication::init ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    QDesktopWidget * widget = QApplication::desktop();

    if (QApplication::desktop()->screenCount() > 1)
    {
        QRect screenres = QApplication::desktop()->screenGeometry(1 /*screenNumber*/);
        m_MainWindow = new  MainWindow();
        this->m_MainWindow->move(QPoint(screenres.x() , screenres.y()));
        this->m_MainWindow->resize(screenres.width() , screenres.height());
        //    QRect rect = widget->screenGeometry(0);
        //    m_MainWindow->move(rect.width() , rect.y());
        //    this->m_MainWindow->move(0 , 0);
        // this->m_MainWindow->windowHandle()->setScreen(qApp->screens()[1]);
        this->m_MainWindow->show();
        //        this->m_MainWindow->showFullScreen();

        QRect secodScreenRes = QApplication::desktop()->screenGeometry(0 /*screenNumber*/);
        this->m_view = new  View();
        this->m_view->move(QPoint(secodScreenRes.x() , secodScreenRes.y()));
        this->m_view->resize(secodScreenRes.width() , secodScreenRes.height());
        //        this->m_view->showFullScreen();
        this->m_view->show();
        //    //    QRect rect widget->screenGeometry(1);
        //    //    m_view->move(rect.width() , rect.y());
    }
    else
    {
        LOG4CXX_WARN(logger , "Multi screen not supported");
    }
}

/*
   bool GCSApplication::event (QEvent * event)
   {
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    switch (event->type())
    {
    case QEvent::FileOpen :
        break;

    case QEvent::Close :
        // saveSettings();
        break;

    case QEvent::FontChange :
        break;

    case QEvent::Gesture :
    case QEvent::GestureOverride :
        break;

    case QEvent::Hide :
        break;

    case QEvent::HideToParent :
        break;

    case QEvent::HoverEnter :
        break;

    case QEvent::HoverLeave :
        break;

    case QEvent::OrientationChange :             // The screens orientation has changes
        break;

    case QEvent::HoverMove :            // Widget's position changed
        break;

    case QEvent::Move :
        break;

    case QEvent::Resize :            // Widget's size changed
        break;

    case QEvent::Leave :             // Mouse leaves widget's boundaries.
        break;

    default :
        break;
    }

    // return QApplication::event(event);
   }
 */

QUrl GCSApplication::homePath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList homesLocation = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    QUrl appPath(applicationCurrentPath().at(0));

    if (homesLocation.isEmpty())
    {
        m_homePath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_homePath = QString("%1").arg(homesLocation.first());
    }

    return (m_homePath);
}

QUrl GCSApplication::desktopPath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList desktopsLocation = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (desktopsLocation.isEmpty())
    {
        m_desktopPath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_desktopPath = QString("%1").arg(desktopsLocation.first());
    }

    return (m_desktopPath);
}

QStringList GCSApplication::applicationCurrentPath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    m_applicationPath = QString("%1").arg(QCoreApplication::applicationDirPath());
}

QUrl GCSApplication::userPath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList usersLocation = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (usersLocation.isEmpty())
    {
        // m_userPath = applicationCurrentPath().resolved(QUrl("/home/"));
        m_userPath = appPath.resolved(QUrl("/home/"));
    }
    else
    {
        m_userPath = QString("%1").arg(usersLocation.first());
    }

    return (m_userPath);
}

QUrl GCSApplication::imagePath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (picturesLocation.isEmpty())
    {
        m_imagePath = appPath.resolved(QUrl("images"));
    }
    else
    {
        m_imagePath = QString("%1").arg(picturesLocation.first());
    }

    return (m_imagePath);
}

bool GCSApplication::multiScreen () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    return m_isMultiScreen;
}

void GCSApplication::multiScreen (bool multiMonitor)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    m_isMultiScreen = multiMonitor;
}

QUrl GCSApplication::videoPath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList moviesLocation = QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (moviesLocation.isEmpty())
    {
        m_videoPath = appPath.resolved(QUrl("./"));
    }
    else
    {
        m_videoPath = QString("%1").arg(moviesLocation.first());
    }

    return (m_videoPath);
}

QUrl GCSApplication::tempFolderPath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList tempsLocation = QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (tempsLocation.isEmpty())
    {
        m_tempFolderPath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_tempFolderPath = QString("%1").arg(tempsLocation.first());
    }

    return (m_tempFolderPath);
}

QUrl GCSApplication::documentsPath ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    const QStringList docsLocation = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    QUrl appPath(applicationCurrentPath().join(""));

    if (docsLocation.isEmpty())
    {
        m_documentsPath = appPath.resolved(QUrl("/"));
    }
    else
    {
        m_documentsPath = QString("%1").arg(docsLocation.first());
    }

    return (m_documentsPath);
}
