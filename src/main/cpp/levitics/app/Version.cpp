#include <QObject>
#include <QRegExp>
#include <QStringList>
#include <QSysInfo>

#include <Version.hpp>


Version::Version() 
{
}

Version::Version(const Version& orig) 
{
}

Version::Version( const QString& version )
{
	m_version = version.trimmed();
    // const QStringList parts = m_version.split( QSL( ". ") );
	// const int index = parts.value( 3 ).indexOf( QRegExp( QSL( "[A-Z|a-z]" ) ) );
	
    // major = parts.value( 0 ).toInt();
    // minor = parts.value( 1 ).toInt();
	// micro = parts.value( 2 ).toInt();
	// patch = parts.value( 3 ).toInt();
	
	// if ( index != -1 ) 
	// {
        // build = parts.value( 3 ).mid( 0, index ).toInt();
        // extra = parts.value( 3 ).mid( index );
    // }
    // else 
	// {
        // build = parts.value( 3 ).toInt();
	// }
}

Version::~Version() 
{
}


int Version::getMajor()
{
    return GCS_VERSION_MAJOR;
}

int Version::getMinor()
{
    return GCS_VERSION_MINOR;
}

int Version::getPatch()
{
    return GCS_VERSION_PATCH;
}

QString Version::compilerString()
{
#if defined(Q_CC_CLANG) // must be before GNU, because clang claims to be GNU too
    QString isAppleString;
#if defined(__apple_build_version__) // Apple clang has other version numbers
    isAppleString = QLatin1String(" (Apple)");
#endif
    return QLatin1String("Clang " ) + QString::number(__clang_major__) + QLatin1Char('.')
            + QString::number(__clang_minor__) + isAppleString;
#elif defined(Q_CC_GNU)
    return QLatin1String("GCC " ) + QLatin1String(__VERSION__);
#elif defined(Q_CC_MSVC)
    if (_MSC_VER > 1999)
        return QLatin1String("MSVC <unknown>");
    if (_MSC_VER >= 1900) // 1900: MSVC 2015
        return QLatin1String("MSVC 2015");
    if (_MSC_VER >= 1800) // 1800: MSVC 2013 (yearly release cycle)
        return QLatin1String("MSVC ") + QString::number(2008 + ((_MSC_VER / 100) - 13));
    if (_MSC_VER >= 1500) // 1500: MSVC 2008, 1600: MSVC 2010, ... (2-year release cycle)
        return QLatin1String("MSVC ") + QString::number(2008 + 2 * ((_MSC_VER / 100) - 15));
#endif
    return QLatin1String("<unknown compiler>");
}	

QString Version::getABI()
{
    // return GCS_VERSION_ABI;
    
	return QObject::tr("Based on Qt %1 (%2, %3 bit)").arg(QLatin1String(qVersion()), compilerString(), QString::number(QSysInfo::WordSize));
}

bool Version::check()
{
	return (getMajor()==GCS_VERSION_MAJOR &&
		   getMinor()==GCS_VERSION_MINOR);
}
	
std::string Version::getString()
{
    std::ostringstream version;
    version << getMajor() << '.' << getMinor() << '.' << getPatch() << "" << __DATE__ << " " <<__TIME__;
    return version.str();
}

std::string Version::getRevision()
{
	return  GCS_VERSION_REVISION;
	//return  QString( " %1" ).arg( GCS_VERSION_REVISION, 1, 16 ).toUpper();
}

std::string Version::getRevString()
{
    std::ostringstream version;
    version << getString() << '.' << std::hex << getRevision() << std::dec;
    return version.str();
}

std::string Version::getSchema()
{
	return R"(
        {
            "title": "Version",
            "type": "object",
            "description": "Version information of the running application",
            "properties": {
                "major": { "type": "integer" },
                "minor": { "type": "integer" },
                "micro": { "type": "integer" },
                "patch": { "type": "integer" },
                "abi": { "type": "integer" },
                "revision": { "type": "string" }
			}
	   }
    )";
}
	
std::string Version::toJSON()
{
	return R"(
        {
            "major": ,
            "minor": ,
            "micro": ,
            "patch": ,
            "abi": ,
            "revision": ""
        }
    )";
}

int Version::compareVersion(const Version &rhs) const
{
	// size_t min = this->minor < rhs.minor;
	
	if ( *this == rhs ) 
	{
        return false;
	}
    else if ( major != rhs.major ) 
	{
        return major < rhs.major;
    }
    else if ( minor != rhs.minor ) 
	{
        return minor < rhs.minor;
    }
    else if ( patch != rhs.patch ) 
	{
        return patch < rhs.patch;
    }
    // else if ( build != rhs.build ) 
	// {
        // return build < rhs.build;
    // }
    else if ( m_extra.isEmpty() && !rhs.m_extra.isEmpty() ) 
	{
        return false;
    }
    // else if ( !extra.isEmpty() && rhs.extra.isEmpty() ) 
	// {
        // return true;
	// }	
	
}
	
