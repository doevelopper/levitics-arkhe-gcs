
#include <QPixmapCache>
#include <cstdlib>
// #include <levitics/app/GCSApplication.hpp>

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

    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts , true);
    // QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings , true);
    // QLocale::setDefault(QLocale::C);
    // setlocale(LC_ALL , "C");

    // QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    // QPixmapCache::setCacheLimit(819200);
    // GCSApplication app (argc , argv);
    // app.init();
    // return (app.exec ());
}
