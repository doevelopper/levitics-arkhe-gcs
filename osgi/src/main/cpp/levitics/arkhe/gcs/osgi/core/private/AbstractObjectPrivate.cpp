#include <levitics/arkhe/gcs/osgi/core/private/AbstractObjectPrivate.hpp>
#include <levitics/arkhe/gcs/osgi/core/AbstractObject.hpp>

AbstractObjectPrivate::AbstractObjectPrivate(AbstractObject *q)
    : q_ptr(q)
{

}

AbstractObjectPrivate::AbstractObjectPrivate(const AbstractObjectPrivate& other
                                             , AbstractObject *q)
    : q_ptr(q),
    values(other.values),
    properties(other.properties),
    metadatas(other.metadatas)
{

}
