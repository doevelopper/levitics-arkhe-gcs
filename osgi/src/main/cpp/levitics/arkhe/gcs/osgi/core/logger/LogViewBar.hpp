#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEWBAR_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEWBAR_HPP

#include <QFrame>

class LogViewBar : public QFrame
{
    Q_OBJECT

public:

    LogViewBar( QWidget * parent = Q_NULLPTR );
    ~LogViewBar( );

signals:

    void displayTrace ( bool display );
    void displayDebug ( bool display );
    void displayInfo ( bool display );
    void displayWarn ( bool display );
    void displayError ( bool display );
    void displayFatal ( bool display );

private:

};

#endif
