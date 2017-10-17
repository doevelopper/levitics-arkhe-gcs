
#ifndef LEVITICS_OSGI_CORE_LOGGER_PRIVATE_LOGVIEWPRIVATE_HPP
#define LEVITICS_OSGI_CORE_LOGGER_PRIVATE_LOGVIEWPRIVATE_HPP

#include <QStringList>
#include <QCheckBox>
#include <QRegExp>
#include <levitics/arkhe/gcs/osgi/core/logger/LogViewList.hpp>
#include <levitics/arkhe/gcs/osgi/core/logger/LogViewBar.hpp>
#include <levitics/arkhe/gcs/osgi/core/logger/LogViewTree.hpp>
class LogViewPrivate
{
    public:

        LogViewPrivate();
        ~LogViewPrivate();

        QRegExp expression(void);

        QStringList exclude;
        QCheckBox * autoScroll;

        LogViewBar  *bar;
        LogViewTree *tree;
        LogViewList *list;
};

#endif
