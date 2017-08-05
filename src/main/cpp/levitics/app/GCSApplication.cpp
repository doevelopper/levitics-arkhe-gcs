
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
    this->init();
}

GCSApplication::~GCSApplication()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if ( m_multiScreenManagement )
        delete m_multiScreenManagement;

    if (  m_view)
        delete m_view;

    //    this->setParent(Q_NULLPTR);
}

void GCSApplication::init ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->m_view = new  View();
}

void GCSApplication::applicationShutdown ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    //    if ( m_multiScreenManagement )
    //        delete m_multiScreenManagement;
}
