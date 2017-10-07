
#ifndef LEVITICS_APP_GCSAPPLICATION_HPP
#define LEVITICS_APP_GCSAPPLICATION_HPP

#include <QtCore/QObject>
#include <QtGlobal>
#include <QUrl>
#include <QApplication>
#include <QException>
#include <functional>
#include <QFontDatabase>
#include <levitics/app/Mainwindow.hpp>
#include <levitics/app/View.hpp>
#include <levitics/app/Version.hpp>
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
        GCSApplication(const GCSApplication &) Q_DECL_EQ_DELETE;
        GCSApplication(GCSApplication &&) Q_DECL_EQ_DELETE;
        GCSApplication & operator = (const GCSApplication &) Q_DECL_EQ_DELETE;
        GCSApplication & operator = (GCSApplication &&) Q_DECL_EQ_DELETE;
        ~GCSApplication();

        static GCSApplication * instance ()
        {
            return static_cast<GCSApplication *>(qApp);
        }

        void init ();
        void applicationShutdown ();
        bool multiScreen () const;
        void multiScreen (bool multiMonitor);

        // Get the computer standard folder paths
        QUrl homePath ();
        QUrl desktopPath ();
        QUrl userPath ();
        QUrl imagePath ();
        QUrl videoPath ();
        QUrl tempFolderPath ();
        QUrl documentsPath ();
        QStringList applicationCurrentPath ();

signals:

public slots:

protected:

        //        bool event (QEvent * event);

private:

        View * m_view { };
        MainWindow * m_MainWindow{ };
        GCSApplicationPrivate * d;
        MultiScreenManagement * m_multiScreenManagement;
        QUrl m_applicationPath;
        QUrl m_userPath;
        QUrl m_imagePath;
        QUrl m_videoPath;
        QUrl m_homePath;
        QUrl m_desktopPath;
        QUrl m_tempFolderPath;
        QUrl m_documentsPath;
        Version m_versionInfo;
        QFontDatabase m_fontDatabase;
        const QString m_fontFileName;           ///< Font file is part of the QRC file and compiled into the app.
        const QString m_fontFamilyName;
        bool m_isMultiScreen;
        static log4cxx::LoggerPtr logger;
    };

#endif
