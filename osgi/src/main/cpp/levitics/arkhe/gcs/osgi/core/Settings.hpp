
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_SETTINGS_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_SETTINGS_HPP

#include <QtCore>

class Settings : public QSettings
{
public:
    explicit Settings();
    virtual ~Settings();
};

#endif
