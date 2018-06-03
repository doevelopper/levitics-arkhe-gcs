
#ifndef LEVITICS_ARKHE_GCS_APP_PRIVATE_MAINWINDOWPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_APP_PRIVATE_MAINWINDOWPRIVATE_HPP

#include <QObject>
#include <levitics/app/mainwindow.hpp>
#include <levitics/osgi/core/logger/Logger.hpp>

class MainWindowPrivate : public QObject
{
    Q_OBJECT

public:

    explicit MainWindowPrivate(MainWindow * mainWindow);
    MainWindowPrivate(QWidget * parent = Q_NULLPTR);
    MainWindowPrivate(const MainWindowPrivate &) = delete;
    MainWindowPrivate(MainWindowPrivate &&) = delete;
    MainWindowPrivate & operator = (const MainWindowPrivate &) = delete;
    MainWindowPrivate & operator = (MainWindowPrivate &&) = delete;
    virtual ~MainWindowPrivate() Q_DECL_OVERRIDE; // = delete;

    void setupActions ();
    void setupGui ();
    void setupStatusBar ();

public Q_SLOTS:

    void split (Qt::Orientation orientation);
    void toggleFullScreen (bool fullScreen);

protected:

private:

    MainWindow * m_mainWindow;
    bool m_changingActiveView;
    // std::unique_ptr<Ui::MainWindow> ui;
    static log4cxx::LoggerPtr logger;
};

#endif
