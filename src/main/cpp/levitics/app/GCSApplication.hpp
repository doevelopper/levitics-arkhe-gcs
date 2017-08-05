
#ifndef LEVITICS_APP_GCSAPPLICATION_HPP
#define LEVITICS_APP_GCSAPPLICATION_HPP

#include <QtCore/QObject>
#include <QtGlobal>
#include <QApplication>
#include <QException>
#include <functional>

#include <levitics/app/View.hpp>
#include <levitics/osgi/core/logger/Logger.hpp>

class GCSApplicationPrivate;
class MultiScreenManagement;

#ifndef GCS_NO_GUI
    class GCSApplication : public QApplication
#else
    class GCSApplication : public QCoreApplication
#endif
    {
        Q_OBJECT

public:

        //! Creates a new app with it's arguments
        GCSApplication(int & argc , char * * argv , Qt::WindowFlags f = Qt::WindowFlags());
        GCSApplication(const GCSApplication &) = delete;
        GCSApplication & operator = (const GCSApplication &) = delete;
        ~GCSApplication();
        void init ();
        void applicationShutdown ();

signals:

public slots:

private:

        View * m_view { };
        GCSApplicationPrivate * d;
        MultiScreenManagement * m_multiScreenManagement;
        static log4cxx::LoggerPtr logger;
    };

#endif
