#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEW_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEW_HPP

#include <QWidget>

class LogViewPrivate;

class LogView : public QWidget
{
    Q_OBJECT

    public:

        LogView( QWidget * parent = Q_NULLPTR );
        ~LogView( void );

    protected slots:

        void autoScrollChecked ( int state );
        void disableAutoScroll ( void );
        void enableAutoScroll ( void );

    public slots:

        void displayTrace ( bool display );
        void displayDebug ( bool display );
        void displayInfo ( bool display );
        void displayWarn ( bool display );
        void displayError ( bool display );
        void displayFatal ( bool display );

    private:

        LogViewPrivate * d;
};

#endif
