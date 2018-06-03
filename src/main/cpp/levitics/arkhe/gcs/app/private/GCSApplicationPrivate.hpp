/*
     ,___                         ,___                    _    __,                      
    /   /                   /    /   /        _/_        //   (    _/_     _/_o         
   /  ___   __ , , _ _   __/    /    __ _ _   /  _   __ //     `.  /  __,  / ,  __ _ _  
  (___// (_(_)(_/_/ / /_(_/_   (___/(_)/ / /_(__/ (_(_)(/_   (___)(__(_/(_(__(_(_)/ / /_
   __               __               __              
  /_____    __  _| /   _ ___|____ | (__|_ __|_o _ __ 
  \_||(_)|_|| |(_| \__(_)| ||_|(_)| __)|_(_||_|(_)| |

  ╔═╗┬─┐┌─┐┬ ┬┌┐┌┌┬┐  ╔═╗┌─┐┌┐┌┌┬┐┬─┐┌─┐┬    ╔═╗┌┬┐┌─┐┌┬┐┬┌─┐┌┐┌
  ║ ╦├┬┘│ ││ ││││ ││  ║  │ ││││ │ ├┬┘│ ││    ╚═╗ │ ├─┤ │ ││ ││││
  ╚═╝┴└─└─┘└─┘┘└┘─┴┘  ╚═╝└─┘┘└┘ ┴ ┴└─└─┘┴─┘  ╚═╝ ┴ ┴ ┴ ┴ ┴└─┘┘└┘
   Copyright 2015-2017 [name of copyright owner]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#ifndef LEVITICS_ARKHE_GCS_APP_PRIVATE_GCSAPPLICATIONPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_APP_PRIVATE_GCSAPPLICATIONPRIVATE_HPP

#include <QCommandLineParser>
#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QtCore/QLockFile>
#include <QtCore/QScopedPointer>
#include <QtCore/QPointer>
#include <QtCore/QLoggingCategory>
#include <QtCore/QFile>
#include <QtNetwork/QLocalServer>

#include <levitics/arkhe/gcs/app/logger/Logger.hpp>
#include <levitics/arkhe/gcs/app/GCSApplication.hpp>

namespace levitics::arkhe::gcs::app::internal
{
    class GCSApplicationPrivate : public QObject
    {
        Q_OBJECT

    public:

        // explicit GCSApplicationPrivate(QObject * parent = nullptr);
        static GCSApplicationPrivate * p_ptr ();
        GCSApplicationPrivate(GCSApplication * q_ptr);
        ~GCSApplicationPrivate();
        static QString generateSingleId (const QString &seed = QString());
        void setInstanceId (const QString &id);

    signals:

    public Q_SLOTS:

        int initControlFlow (const QCommandLineParser &parser);

    private Q_SLOTS:

        // int makeMaster (const QCommandLineParser &parser);
        // int startMaster (bool isAutoStart = false , bool isRestart = false);
        // int restartMaster (const QCommandLineParser &parser);
        // int commandMaster ();
        // int purgeMaster (const QCommandLineParser &parser);

        // void newTerminalConnected ();
        // void terminalLoaded (TerminalPrivate * terminal , bool success);
        // void stopMaster (Terminal * term);
        // void doExit (int code);

        // void beginMasterConnect (const QStringList &arguments , bool isStarter);

    protected:

    private:

        GCSApplication * q;

        static bool p_valid;

        bool m_running;
        bool m_masterLogging;
        bool m_autoStart;
        bool m_ignoreExtraStart;
        bool m_autoDelete;
        bool m_autoKill;

        QString m_instanceId;

        static const QString m_masterArgument;
        static const QString m_purgeArgument;
        static const QString m_startArgument;
        static const QString m_restartArgument;
        static const QString m_terminalMessageFormat;
        static const QString m_masterMessageFormat;

        Logger * m_loggerService;
        static log4cxx::LoggerPtr logger;
    };
}

#endif
