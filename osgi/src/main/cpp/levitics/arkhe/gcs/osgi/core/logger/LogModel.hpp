#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGMODEL_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_LOGGER_LOGMODEL_HPP

#include <QModelIndex>
#include <QVariant>
#include <QAbstractListModel>
#include <QPair>

class LogModelPrivate;

class LogModel : public QAbstractListModel
{

public:

    LogModel( QObject * parent = Q_NULLPTR );
    ~LogModel( );

    void append ( const QString & message );
    int rowCount ( const QModelIndex & parent = QModelIndex( ) ) const;
    QVariant data ( const QModelIndex & index,
                    int role ) const;
    bool setData ( const QModelIndex & index,
                   const QVariant & value,
                   int role = Qt::EditRole );
    Qt::ItemFlags flags ( const QModelIndex & index ) const;
    bool insertRows ( int row,
                      int count,
                      const QModelIndex & parent = QModelIndex( ) );
    bool removeRows ( int row,
                      int count,
                      const QModelIndex & parent = QModelIndex( ) );
    void sort ( int column,
                Qt::SortOrder order = Qt::AscendingOrder );
    Qt::DropActions supportedDropActions ( void ) const;

    static bool
    ascendingLessThan( const QPair<QString, int> & s1,
        const QPair<QString, int> & s2 )
    {
        return s1.first < s2.first;
    }

    static bool
    decendingLessThan( const QPair<QString, int> & s1,
        const QPair<QString, int> & s2 )
    {
        return s1.first > s2.first;
    }

private:

    LogModelPrivate * d;
};

#endif
