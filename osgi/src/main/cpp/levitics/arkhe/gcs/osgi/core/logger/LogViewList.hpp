#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEWLIST_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGVIEWLIST_HPP

#include <QListView>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <QHash>
#include <QString>
#include <levitics/arkhe/gcs/osgi/core/logger/LogModel.hpp>

class LogViewList : public QListView
{
    Q_OBJECT

    public:

        LogViewList( QWidget * parent = Q_NULLPTR );
        ~LogViewList( );

    public slots:

        void setRuntime ( void );
        void setFile ( const QString & path );
        void setAutoScroll ( bool autoScroll );

    public:

        void setFilter ( const QRegExp & expression );

    private:

        LogModel * m_model;

    private:

        QHash<QString, QStringListModel *> m_models;

    private:

        QSortFilterProxyModel * m_proxy;

};

#endif
