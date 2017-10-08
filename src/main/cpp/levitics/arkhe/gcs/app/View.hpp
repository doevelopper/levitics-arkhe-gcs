
#ifndef ARKHE_VIEW_HPP
#define ARKHE_VIEW_HPP

#include <QMainWindow>
#include <QWidget>
#include <QPair>
#include <QString>
#include <vector>

#include <levitics/osgi/core/logger/Logger.hpp>
// #include <arkhe/widgets/StatusBar.hpp>

class QCloseEvent;
class QDockWidget;
class QEvent;
class QObject;
class QTabWidget;

/**
 * @brief The second display of the application.
 */
class View Q_DECL_FINAL : public QMainWindow
{
    Q_OBJECT
    using Superclass = QMainWindow;

public:

    View(QObject * parent = Q_NULLPTR);
    View(const View &)  Q_DECL_EQ_DELETE;
    View(View &&)  Q_DECL_EQ_DELETE;
    View & operator = (const View &)  Q_DECL_EQ_DELETE;
    View & operator = (View &&)  Q_DECL_EQ_DELETE;
    virtual ~View();     // = delete;

    // static View * instance();
    void restoreLayout ();
    // void closeEvent(QCloseEvent*) override;

    // Q_SIGNALS:

    // void sizeChanged(QSize);

    // Q_SLOTS:

private:

    // void changeEvent(QEvent*) override;
    // void resizeEvent(QResizeEvent*) override;
    QTabWidget * m_tabWidget{ };

    // static View * m_instance;
    // StatusBar * m_statusBar;
    static log4cxx::LoggerPtr logger;
};

#endif
