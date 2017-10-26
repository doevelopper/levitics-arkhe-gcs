#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_ABSTRACTOBJECT_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_ABSTRACTOBJECT_HPP

#include <QObject>
#include <typeinfo>

class AbstractObjectPrivate;

class AbstractObject : public QObject
{
    Q_OBJECT

public:

// AbstractObject();
    AbstractObject( AbstractObject * parent = Q_NULLPTR );
    AbstractObject( const AbstractObject & other );
    AbstractObject & operator = ( const AbstractObject & other );
    bool operator == ( const AbstractObject & other ) const;
    virtual
    ~AbstractObject( );

    virtual AbstractObject * clone ( );
    virtual void copy ( const AbstractObject & other );
    virtual QString description ( ) const;
    virtual QString identifier ( ) const;
    virtual QString name ( ) const;

    int count ( ) const;
    int retain ( ) const;
    int release ( ) const;

    void enableDeferredDeletion ( bool value );
    bool     isDeferredDeletionEnabled ( void ) const;

    bool hasProperty ( const QString & key ) const;
    void addProperty ( const QString & key,
                       const QStringList & values );
    void addProperty ( const QString & key,
                       const QString & value );
    void setProperty ( const QString & key,
                       const QString & value );
    QStringList propertyList ( void ) const;
    QStringList propertyValues ( const QString & key ) const;
    QString property ( const QString & key ) const;

    bool hasMetaData ( const QString & key ) const;
    void addMetaData ( const QString & key,
                       const QStringList & values );
    void addMetaData ( const QString & key,
                       const QString & value );
    void setMetaData ( const QString & key,
                       const QStringList & values );
    void setMetaData ( const QString & key,
                       const QString & value );
    QStringList metaDataList ( ) const;
    QStringList metaDataValues ( const QString & key ) const;
    QString metadata ( const QString & key ) const;
    QStringList metadatas ( const QString & key ) const;
    void copyMetaDataFrom ( const AbstractObject * obj );

public slots:

    virtual void onPropertySet ( const QString & key,
                                 const QString & value );
    virtual void onMetaDataSet ( const QString & key,
                                 const QString & value );

protected:

    virtual bool isEqual ( const AbstractObject & other ) const;
    AbstractObject( AbstractObjectPrivate & dd,
        QObject * parent );
    AbstractObject( AbstractObjectPrivate & dd,
        const AbstractObject & other );
    AbstractObjectPrivate *
    d_func( )
    {
        return (d_ptr);
    }

    const AbstractObjectPrivate *
    d_func( ) const
    {
        return (d_ptr);
    }

signals:

    void propertySet ( const QString & key,
                       const QString & value );
    void metaDataSet ( const QString & key,
                       const QString & value );

private:

    AbstractObjectPrivate * d_ptr;
    friend class AbstractObjectPrivate;
};

Q_DECLARE_METATYPE( AbstractObject );
Q_DECLARE_METATYPE( AbstractObject * );

#endif
