
#ifndef ARKHE_MAINWINDOW_HPP
#define ARKHE_MAINWINDOW_HPP

#include <QApplication>
#include <QtGlobal>
#include <QMainWindow>

// #include <arkhe/widgets/StatusBar.hpp>
#include <levitics/osgi/core/logger/Logger.hpp>

namespace Ui
{
    class MainWindow;
}

class MainWindowPrivate;
class QSplashScreen;
/*!
 * @brief Main window class
 *
 * This is the main class of the application, it handles the
 * graphics scene, view and instruments.
 */

class MainWindow
    : public QMainWindow
{
    Q_OBJECT
    using Superclass = QMainWindow;

    /*! @enum MainWindow::DGCS_MAINWINDOW_STYLE
     *  Theme to apply on the maon window
     */
    enum GcsMainwindowStyle
    {
        GCS_MAINWINDOW_STYLE_DARK ,

        /*!< DARK */
        GCS_MAINWINDOW_STYLE_LIGHT ,

        /*!< LIGHT */
        GCS_MAINWINDOW_STYLE_NATIVE ,

        /*!< NATIVE */
        GCS_MAINWINDOW_STYLE_INDOOR ,

        /*!< INDOOR */
        GCS_MAINWINDOW_STYLE_OUTDOOR ,

        /*!< OUTDOOR */
        GCS_MAINWINDOW_STYLE_OXYGEN ,

        /*!< OXYGEN */
        GCS_MAINWINDOW_STYLE_WIN ,

        /*!< WIN */
        GCS_MAINWINDOW_STYLE_KDE ,

        /*!< KDE */
        GCS_MAINWINDOW_STYLE_PLASMA      /*!< PLASMA */
    };

public:

    MainWindow(QWidget * parent = Q_NULLPTR , Qt::WindowFlags flags = Qt::WindowFlags());
    MainWindow(const QMap<QString , QSize> & customSizeHints ,
               QWidget * parent = Q_NULLPTR , Qt::WindowFlags flags = Qt::WindowFlags());
    MainWindow(const QMap<QString , QSize> & customSizeHints , QSplashScreen * screen ,
               QWidget * parent = Q_NULLPTR , Qt::WindowFlags flags = Qt::WindowFlags());
    virtual ~MainWindow();

    static MainWindow * get ();
    static Ui::MainWindow * getUi ();

    GcsMainwindowStyle currentStyle () const;
    void currentStyle (const GcsMainwindowStyle & value);
    void addDGCSDockWidget (QString name , Qt::DockWidgetArea area , quint32 flags);
    QString styleFileName () const;
    void styleFileName (const QString & value);
    bool loadStyle (GcsMainwindowStyle style , QString styleSheetFileName);
    void reloadStylesheet ();
    bool isAdvancedMode () const;
    void setIsAdvancedMode (bool isAdvancedMode);
    void deleteInstance (void);
    void setFrameless (QWidget * w);

    // static MainWindow * instance ();

    virtual void retranslateUi ();
    virtual void showAndEnableMenu (QMenu & menu , bool show);
    virtual void resizeEvent (QResizeEvent * event) Q_DECL_OVERRIDE;
    virtual bool eventFilter (QObject * watched , QEvent * event) Q_DECL_OVERRIDE;

signals:

    void mouseWheelUp ();
    void mouseWheelDown ();

protected slots:

    void showWelcomeDialog ();
    void handleMessage (const QString & , int);

protected:

    Q_DECLARE_PRIVATE(MainWindow);
    QScopedPointer<MainWindowPrivate> const d_ptr;
    explicit MainWindow(MainWindowPrivate & d , QWidget * parent);

    void dragEnterEvent (QDragEnterEvent * evt);
    void dropEvent (QDropEvent * evt);
    void showEvent (QShowEvent * evt);
    void closeEvent (QCloseEvent * evt);
    void wheelEvent (QWheelEvent * ev);

    /*!
     * @brief Called when a mouse button is pressed over the window
     *
     * @param event Event's attributes
     */
    virtual void mousePressEvent (QMouseEvent * event);

    /*!
     * @brief Called when the mouse moves over the window
     *
     * @param event Event's attributes
     */
    virtual void mouseMoveEvent (QMouseEvent * event);

    /*!
     * @brief Called when a key is pressed
     *
     * @param event Event's attributes
     */
    virtual void keyPressEvent (QKeyEvent * event);

private:

    bool saveLayout ();
    bool loadLayout ();

    // Q_DISABLE_COPY(MainWindow);
    static MainWindow * m_instance;

    // StatusBar * m_statusBar;
    static log4cxx::LoggerPtr logger;
};

#endif
