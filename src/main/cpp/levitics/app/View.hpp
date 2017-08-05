
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
class View final : public QWidget
{
    Q_OBJECT
    using Superclass = QWidget;

public:

    // View(QObject* parent = Q_NULLPTR);
    View(QWidget * parent = Q_NULLPTR);
    View(const View &) = delete;
    View(View &&) = delete;
    View & operator = (const View &) = delete;
    View & operator = (View &&) = delete;
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
    // QTabWidget* m_tabWidget{};

    // static View * m_instance;
    // StatusBar * m_statusBar;
    static log4cxx::LoggerPtr logger;
};

#endif
