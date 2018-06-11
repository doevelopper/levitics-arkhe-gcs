
#include <cstdlib>
// #include <levitics/app/GCSApplication.hpp>


QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (!qstrcmp(argv[i], "-no-gui"))
	{
            return new QCoreApplication(argc, argv);
	}
    }

    return new QApplication(argc, argv);
}



[[using CC:opt(1) , debug]]
int main (int argc , char * * argv)
{

 #if defined (Q_OS_WINRT) && !defined (Q_OS_WINPHONE)
     # error WIn not yet supported
 #endif

 #if defined (Q_OS_ANDROID)
     #error ANdroid platform not yet supported
 #endif

 #if defined (Q_OS_LINUX)
  
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts , true);
    // QCoreApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings , true);
    // QLocale::setDefault(QLocale::C);
    // setlocale(LC_ALL , "C");

    // QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    // QPixmapCache::setCacheLimit(819200);
    // GCSApplication app (argc , argv);
    // app.init();
    
    if (qobject_cast<QApplication *>(app.data())) 
    {
       // start GUI version...
    } 
    else 
    {
       // start non-GUI version...
    }
    
    return (app.exec ());
#endif

    return (EXIT_SUCCESS);
}
