#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_ABSTRACTOBJECTPRIVATE_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_PRIVATE_ABSTRACTOBJECTPRIVATE_HPP

#include <QtCore>

class AbstractObject;

class AbstractObjectPrivate
{
    public:

        AbstractObjectPrivate( );
        AbstractObjectPrivate( AbstractObject * q = Q_NULLPTR );
        AbstractObjectPrivate( const AbstractObjectPrivate & other,
        AbstractObject * q = Q_NULLPTR );
        virtual
        ~AbstractObjectPrivate( );

        friend class AbstractObject;

        AbstractObject * q_ptr;
        QAtomicInt count;
        QHash<QString, QStringList> values;
        QHash<QString, QString> properties;
        QHash<QString, QStringList> metadatas;
        bool isDeferredDeletionEnabled;
};

#endif
