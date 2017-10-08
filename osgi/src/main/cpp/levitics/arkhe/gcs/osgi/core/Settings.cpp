
#include <levitics/arkhe/gcs/osgi/core/Settings.hpp>

Settings::Settings(void) 
: QSettings(QSettings::IniFormat, QSettings::UserScope, "levitics", "gcs-osgi")
{

}

Settings::~Settings(void)
{

}
