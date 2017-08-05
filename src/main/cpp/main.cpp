
#include <QPixmapCache>
#include <cstdlib>
#include <levitics/app/GCSApplication.hpp>

// [[using CC:opt(1) , debug]]
int main (int argc ,
          char * * argv)
{
 #if defined (Q_OS_WINRT) \
    && !defined (Q_OS_WINPHONE)

 #endif

 #if defined (Q_OS_ANDROID) \
    && !defined (Q_OS_WINPHONE)

 #endif

 #if defined (Q_OS_LINUX) \
    && !defined (Q_OS_WINPHONE)

 #endif

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QLocale::setDefault(QLocale::C);
    setlocale(LC_ALL , "C");

    GCSApplication * app = Q_NULLPTR;
    quint8 applicationStatus = 0;

    if ( app )
    {
        delete app;
    }
    else
    {
        QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
        QPixmapCache::setCacheLimit(819200);
        app = new GCSApplication(argc , argv);
    }

    applicationStatus = app->exec ();
    // app->applicationShutdown();
    delete app;

    return (EXIT_SUCCESS);
}
