#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_OSGIAPPLICATION_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_OSGIAPPLICATION_HPP

#include <QtCore>
#include <QApplication>
class OSGIApplicationPrivate;
class OSGIApplication : public QApplication
{
    public:

        explicit OSGIApplication ();
        explicit OSGIApplication (int & argc, char * * argv);
        virtual ~OSGIApplication( );

    private:

    private:

        OSGIApplicationPrivate * d;
};

#endif
