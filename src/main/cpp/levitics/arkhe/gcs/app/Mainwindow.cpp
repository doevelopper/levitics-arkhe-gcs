
#include <QGraphicsLinearLayout>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QFont>
#include <new>

#include <levitics/app/private/MainWindowPrivate.hpp>
#include <levitics/app/Mainwindow.hpp>

log4cxx::LoggerPtr MainWindow::logger =
    log4cxx::Logger::getLogger(std::string("levitics.app.MainWindow"));

// #include <arkhe/core/Version.hpp>
// Q_GLOBAL_STATIC(MainWindow , theMainwindowManager)
// MainWindow * MainWindow::m_instance = Q_NULLPTR;
#define GET_D static_cast<MainWindowPrivate *>(get()->d_ptr.data())

// -------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *       parent ,
                       Qt::WindowFlags flags)
    : QMainWindow(parent , flags | Qt::FramelessWindowHint)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // Setup the window
    // setStyleSheet("background: white");
    // setWindowTitle("ARKHE - Ground Control Station");

     //resize(800 , 700);

    // m_statusBar = new StatusBar(this);
}

MainWindow::~MainWindow()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

/*
   MainWindow * MainWindow::instance ()
   {
    if ( Q_NULLPTR == MainWindow::m_instance)
    {
        //// MainWindow::m_instance = new (nothrow) MainWindow();
        MainWindow::m_instance = new MainWindow();
    }

    return MainWindow::m_instance;

    // return theMainwindowManager;
   }
 */

void MainWindow::setFrameless (QWidget * w)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    Qt::WindowFlags flags = w->windowFlags();
    flags |= Qt::FramelessWindowHint;
    flags &=
        ~(Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    w->setWindowFlags(flags);
}

void MainWindow::mousePressEvent (QMouseEvent * event)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // Reset the drag position
    // if (event->buttons() & Qt::LeftButton)
    // m_dragPosition = event->globalPos();
}

void MainWindow::wheelEvent (QWheelEvent * ev)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    if ( ev->delta() > 0 )
    {
        // emit mouseWheelUp();
    }
    else
    if ( ev->delta() < 0 )
    {
        // emit mouseWheelDown();
    }
}

void MainWindow::mouseMoveEvent (QMouseEvent * event)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // Move the window accordingly
    // if (event->buttons() & Qt::LeftButton)
    // {
    // QPoint offset = event->globalPos() - m_dragPosition;
    // m_dragPosition = event->globalPos();

    // if (event->modifiers() & Qt::ControlModifier)
    // {
    // Resize
    // resize(width() + offset.x(), height() + offset.y());
    // setMinimumSize(m_view->frontInstrument()->minimumSize().toSize());
    // }
    // else
    // {
    // Move
    // move(x() + offset.x(), y() + offset.y());
    // }
    // }
}

// -------------------------------------------------------------------------------------------------
void MainWindow::keyPressEvent (QKeyEvent * event)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // Close the window if escape is pressed
    if ( event->key() == Qt::Key_Escape )
        close();
}

void MainWindow::dragEnterEvent (QDragEnterEvent * evt)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    evt->acceptProposedAction();
}

void MainWindow::dropEvent (QDropEvent * evt)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MainWindow::showEvent (QShowEvent * evt)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    this->Superclass::showEvent(evt);
}

void MainWindow::closeEvent (QCloseEvent * evt)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // pqApplicationCore* core = pqApplicationCore::instance();
    // if (core->settings()->value("GeneralSettings.ShowSaveStateOnExit", false).toBool())
    {
        if ( QMessageBox::question(this , QString("Exit ARKHE GCS %1 ?").arg(APP_VERSION_STR) ,
                                   "Do you want to save the state before exiting?" ,
                                   QMessageBox::Save | QMessageBox::Discard
                                   ) == QMessageBox::Save )
        {
            // pqSaveStateReaction::saveState();
        }
    }
    evt->accept();
}

void MainWindow::showWelcomeDialog ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // pqWelcomeDialog dialog(this);
    // dialog.exec();
}

void MainWindow::handleMessage (const QString & ,
                                int type)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // QDockWidget* dock = this->Internals->outputWidgetDock;
    // if (!dock->isVisible() && (type == pqOutputWidget::ERROR || type == pqOutputWidget::WARNING))
    {
        // if dock is not visible, we always pop it up as a floating dialog. This
        // avoids causing re-renders which may cause more errors and more confusion.
        // QRect rectApp = this->geometry();

        // QRect rectDock(
        // QPoint(0, 0), QSize(static_cast<int>(rectApp.width() * 0.4), dock->sizeHint().height()));
        // rectDock.moveCenter(
        // QPoint(rectApp.center().x(), rectApp.bottom() - dock->sizeHint().height() / 2));
        // dock->setFloating(true);
        // dock->setGeometry(rectDock);
        // dock->show();
    }

    //  if (dock->isVisible())
    {
        // dock->raise();
    }
}

MainWindow::GcsMainwindowStyle
MainWindow::currentStyle () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MainWindow::currentStyle (const MainWindow::GcsMainwindowStyle & value)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void
MainWindow::retranslateUi ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void
MainWindow::showAndEnableMenu (QMenu & menu ,
                               bool show)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void
MainWindow::resizeEvent (QResizeEvent * event)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

bool
MainWindow::eventFilter (QObject * watched ,
                         QEvent *  event)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MainWindow::addDGCSDockWidget (QString name ,
                                    Qt::DockWidgetArea area ,
                                    quint32 flags)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

QString MainWindow::styleFileName () const
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

void MainWindow::styleFileName (const QString & value)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
}

bool MainWindow::loadStyle (GcsMainwindowStyle style ,
                            QString styleSheetFileName)
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    switch ( style )
    {
    //! Native mode means setting no style so if we were already in native mode
    //! take no action  Only if a style was set, remove it.
    case GCS_MAINWINDOW_STYLE_NATIVE :

        if ( style != currentStyle() )
        {
            // qApp->setStyleSheet("");
            // showInfoMessage(tr("Please restart QGroundControl"), tr("Please restart QGroundControl to switch to fully native look and feel. Currently you have loaded Qt's plastique style."));
        }

        break;

    case GCS_MAINWINDOW_STYLE_INDOOR :
        styleFileName (":/resources/qrcs/styles/styles/style-indoor.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_OUTDOOR :

        styleFileName (":/resources/qrcs/styles/styles/style-outdoor.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_DARK :
        styleFileName (":/resources/qrcs/styles/styles/style-dark.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_LIGHT :
        styleFileName (":/resources/qrcs/styles/styles/style-light.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_WIN :
        styleFileName (":/resources/qrcs/styles/styles/style-outdoor.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_OXYGEN :

        styleFileName (":/resources/qrcs/styles/styles/style-outdoor.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_PLASMA :
        styleFileName (":/resources/qrcs/styles/styles/DGCS.css");
        reloadStylesheet();
        break;

    case GCS_MAINWINDOW_STYLE_KDE :
        styleFileName (":/resources/qrcs/styles/styles/style-outdoor.css");
        reloadStylesheet();
        break;

    default :
        styleFileName (":/resources/qrcs/styles/styles/DGCS.css");
        reloadStylesheet();
        break;
    }

    currentStyle (style);
}

void MainWindow::reloadStylesheet ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);
    QFile * styleSheet = new QFile(this->styleFileName ());

    if ( !styleSheet->exists() )
    {
        styleSheet = new QFile(":/resources/qrcs/styles/styles/DGCS.css");
    }
    else
    {
    }

    if ( styleSheet->open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        //! Signal to the user that the app will pause to apply a new stylesheet
        // QCoreApplication::instance()->setOverrideCursor(Qt::WaitCursor);
        qApp->setOverrideCursor(Qt::WaitCursor);

        //        style.replace("ICONDIR", QCoreApplication::applicationDirPath()+ "files/styles/");
        // qApp->setStyleSheet(styleSheet->readAll());

        // setStyleFileName (this->getStyleFileName ());
        // emit styleChanged (currentStyle);
        // emit styleChanged ();
        ////! Finally restore the cursor before returning.
        // qApp->restoreOverrideCursor();
    }
    else
    {
    }

    styleSheet->close ();
    delete styleSheet;
}

bool MainWindow::saveLayout ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // QString fileName = QFileDialog::getSaveFileName(this, tr("Save layout"));
    // if (fileName.isEmpty())
    // {
    // return (false);
    // }
    // QFile file(fileName);
    // if (!file.open(QFile::WriteOnly))
    // {
    // QString msg = tr("Failed to open %1\n%2")
    // .arg(fileName)
    // .arg(file.errorString());
    // QMessageBox::warning(this, tr("Error"), msg);
    // return (false);
    // }

    // QByteArray geoGata = saveGeometry();
    // QByteArray layoutData = saveState();

    // bool ok = file.putChar((uchar)geoGata.size());
    // if (ok)
    // {
    // ok = file.write(geoGata) == geoGata.size();
    // }
    // if (ok)
    // {
    // ok = file.write(layoutData) == layoutData.size();
    // }

    // if (!ok)
    // {
    // QString msg = tr("Error writing to %1\n%2")
    // .arg(fileName)
    // .arg(file.errorString());
    // QMessageBox::warning(this, tr("Error"), msg);
    // return (false);
    // }
}

bool MainWindow::loadLayout ()
{
    LOG4CXX_TRACE(logger , __LOG4CXX_FUNC__);

    // QString fileName = QFileDialog::getOpenFileName(this, tr("Load layout"));

    // if (fileName.isEmpty())
    // {
    // return (false);
    // }

    // QFile file(fileName);
    // if (!file.open(QFile::ReadOnly))
    // {
    // QString msg = tr("Failed to open %1\n%2")
    // .arg(fileName)
    // .arg(file.errorString());
    // QMessageBox::warning(this, tr("Error"), msg);
    // return (false);
    // }

    // uchar geoSize;
    // QByteArray geoData;
    // QByteArray layout_data;

    // bool ok = file.getChar((char*)&geoSize);
    // if (ok)
    // {
    // geoData = file.read(geoSize);
    // ok = geoData.size() == geoSize;
    // }
    // if (ok)
    // {
    // layout_data = file.readAll();
    // ok = layout_data.size() > 0;
    // }

    // if (ok)
    // {
    // ok = restoreGeometry(geoData);
    // }
    // if (ok)
    // {
    // ok = restoreState(layout_data);
    // }

    // if (!ok)
    // {
    // QString msg = tr("Error reading %1")
    // .arg(fileName);
    // QMessageBox::warning(this, tr("Error"), msg);
    // return;
    // }
}
