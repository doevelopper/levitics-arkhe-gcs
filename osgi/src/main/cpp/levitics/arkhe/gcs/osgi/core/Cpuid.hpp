
#ifndef LEVITICS_ARKHE_GCS_OSGI_CORE_SETTINGS_HPP
#define LEVITICS_ARKHE_GCS_OSGI_CORE_SETTINGS_HPP

#include <QtCore>
class CpuidPrivate;
class Cpuid : public QSettings
{
public:
    explicit Cpuid();
    virtual ~Cpuid();
	
	QString vendor();
	
private:

	void load(unsigned i);

	CpuidPrivate *d;
};

#endif
