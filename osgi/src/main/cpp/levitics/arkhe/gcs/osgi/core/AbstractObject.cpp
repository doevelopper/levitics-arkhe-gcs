#include <levitics/Defines.hpp>
#include <levitics/arkhe/gcs/osgi/core/AbstractObject.hpp>
#include <levitics/arkhe/gcs/osgi/core/private/AbstractObjectPrivate.hpp>

AbstractObject::AbstractObject(AbstractObjectPrivate& dd, QObject *parent)
    : QObject(parent),
      d_ptr(&dd)
{

}

AbstractObject::AbstractObject(AbstractObjectPrivate& dd, const AbstractObject& other)
    : QObject(other.parent()),
      d_ptr(&dd)
{

}

AbstractObject::AbstractObject(AbstractObject *parent)
    : QObject(parent),
      d_ptr(new AbstractObjectPrivate(this))
{
    d_ptr->count = 0;
    d_ptr->isDeferredDeletionEnabled = true;
}

AbstractObject::AbstractObject(const AbstractObject& other)
    : QObject(other.parent()),
      d_ptr(new AbstractObjectPrivate(*other.d_ptr, this))
{
    d_ptr->count = 0;
    d_ptr->isDeferredDeletionEnabled = true;
}

AbstractObject::~AbstractObject()
{
    if ( d_ptr->count != 0 )
    {
//        Debug() << "Warning : deleting object of type " << this->metaObject()->className() << " with non-zero reference count";
    }

    delete d_ptr;
    d_ptr = Q_NULLPTR;
}

AbstractObject *AbstractObject::clone()
{
    return new AbstractObject(*this);
}

AbstractObject& AbstractObject::operator = (const AbstractObject& other)
{
    this->copy(other);
    return (*this);
}

void AbstractObject::copy(const AbstractObject& other)
{
    if (this == &other)
    {
        return;
    }

    this->setParent(other.parent());

    d_ptr->values     = other.d_ptr->values;
    d_ptr->properties = other.d_ptr->properties;
    d_ptr->metadatas  = other.d_ptr->metadatas;
    d_ptr->count = 0;
    d_ptr->isDeferredDeletionEnabled = true;
}

bool AbstractObject::operator == (const AbstractObject& other) const
{
    return (this->isEqual(other));
}

bool AbstractObject::isEqual(const AbstractObject& other) const
{
    if (this == &other)
    {
        return true;
    }

    if (d_ptr->values != other.d_ptr->values         ||
        d_ptr->properties != other.d_ptr->properties ||
        d_ptr->metadatas != other.d_ptr->metadatas)
    {
        return (false);
    }

    return (true);
}

QString AbstractObject::description() const
{
//    GCS_DEFAULT_IMPLEMENTATION;
    return QString("");
}

QString AbstractObject::identifier() const
{
//    GCS_DEFAULT_IMPLEMENTATION;

    return (QString(""));
}

QString AbstractObject::name() const
{
    return (this->objectName());
}

int AbstractObject::count() const
{
    return (d_ptr->count);
}

int AbstractObject::retain() const
{
    return (d_ptr->count.fetchAndAddOrdered(1)+1);
}

int AbstractObject::release(void) const
{
    int newCount = d_ptr->count.fetchAndAddOrdered(-1)-1;

    if(!(newCount))
    {

        if (d_ptr->isDeferredDeletionEnabled)
        {
            const_cast<AbstractObject *>(this)->deleteLater();
        }
        else
        {
            delete this;
        }
    }

    return newCount;
}

void AbstractObject::enableDeferredDeletion(bool value)
{
    d_ptr->isDeferredDeletionEnabled = value;
}

bool AbstractObject::isDeferredDeletionEnabled(void) const
{
    return (d_ptr->isDeferredDeletionEnabled);
}

void AbstractObject::addProperty(const QString& key, const QStringList& values)
{
    d_ptr->values.insert(key, values);
}

void AbstractObject::addProperty(const QString& key, const QString& value)
{
    d_ptr->values.insert(key, QStringList() << value);
}

void AbstractObject::setProperty(const QString& key, const QString& value)
{
    if(!d_ptr->values.contains(key))
    {
        qDebug() << this->metaObject()->className() << " has no such property:" << key;
        return;
    }

    if(!d_ptr->values.value(key).contains(value))
    {
        qDebug() << this->metaObject()->className() << " has no such value:" << value << " for key: " << key;
        return;
    }

    d_ptr->properties.insert(key, value);

    onPropertySet(key, value);

    emit propertySet(key, value);
}

QStringList AbstractObject::propertyList(void) const
{
    return d_ptr->properties.keys();
}

QStringList AbstractObject::propertyValues(const QString& key) const
{
    if(d_ptr->values.contains(key))
    {
        return d_ptr->values[key];
    }

    return QStringList();
}

bool AbstractObject::hasProperty(const QString& key) const
{
    return (d_ptr->values.contains(key));
}

QString AbstractObject::property(const QString& key) const
{
    if(!d_ptr->values.contains(key))
    {
        qDebug() << this->metaObject()->className() << "has no such property:" << key;
        return QString();
    }

    return d_ptr->properties.value(key);
}

void AbstractObject::addMetaData(const QString& key, const QStringList& values)
{
    QStringList currentValues = d_ptr->metadatas.value(key);

    d_ptr->metadatas.insert(key, currentValues + values);

    foreach(QString value, values)
    {
        onMetaDataSet(key, value);
    }

    foreach(QString value, values)
    {
        emit metaDataSet(key, value);
    }
}

void AbstractObject::addMetaData(const QString& key, const QString& value)
{
    QStringList currentValues = d_ptr->metadatas.value(key);

    d_ptr->metadatas.insert(key, currentValues << value);

    onMetaDataSet(key, value);

    emit metaDataSet(key, value);
}

void AbstractObject::setMetaData(const QString& key, const QStringList& values)
{
    d_ptr->metadatas.insert(key, values);

    foreach(QString value, values)
    {
        onMetaDataSet(key, value);
    }

    foreach(QString value, values)
    {
        emit metaDataSet(key, value);
    }
}

void AbstractObject::setMetaData(const QString& key, const QString& value)
{
    d_ptr->metadatas.insert(key, QStringList() << value);

    onMetaDataSet(key, value);

    emit metaDataSet(key, value);
}

QStringList AbstractObject::metaDataList(void) const
{
    return (d_ptr->metadatas.keys());
}

QStringList AbstractObject::metaDataValues(const QString& key) const
{
    if(d_ptr->metadatas.contains(key))
    {
        return d_ptr->metadatas[key];
    }

    return QStringList();
}

bool AbstractObject::hasMetaData(const QString& key) const
{
    return d_ptr->metadatas.contains(key);
}

void AbstractObject::onPropertySet(const QString& key, const QString& value)
{
    GCS_UNUSED(key);
    GCS_UNUSED(value);
}

void AbstractObject::onMetaDataSet(const QString& key, const QString& value)
{
    GCS_UNUSED(key);
    GCS_UNUSED(value);
}

QString AbstractObject::metadata(const QString& key) const
{
    if(!d_ptr->metadatas.contains(key))
    {
        qDebug() << this->metaObject()->className() << "has no such property:" << key;
        return QString();
    }

    return d_ptr->metadatas.value(key).first();
}

QStringList AbstractObject::metadatas(const QString& key) const
{
    if(!d_ptr->metadatas.contains(key))
    {
        qDebug() << this->metaObject()->className() << "has no such property:" << key;
        return QStringList();
    }

    return d_ptr->metadatas.value(key);
}

void AbstractObject::copyMetaDataFrom(const AbstractObject *obj)
{
    if (!obj)
    {
        return;
    }

    foreach(QString key, obj->metaDataList())
    {
        this->setMetaData(key, obj->metadatas(key));
    }
}
