#ifndef GCS_CORE_VERSION_HPP
#define GCS_CORE_VERSION_HPP

#include <sstream>
#include <string>
#include <QString>
#include <QRegExp>
#include <QProcess>
#include <QUrl>
#include <QDesktopServices>
#include <Api.hpp>

/*!
 * @brief ReleaseLevel indicates the release level of this API
 *          This enum follows the release level convention used by python.
 * @ref https://docs.python.org/3/c-api/apiabiversion.html
 * @ref https://docs.python.org/3.7/c-api/apiabiversion.html
 * @ref https://hg.python.org/cpython/file/3.6/Include/patchlevel.h
 */
enum ReleaseLevel
{
    RELEASE_LEVEL_SNAPSHOOT    = 0xFF,    /**< API is not tested, work in progress. */
    RELEASE_LEVEL_ALPHA        = 0xA0,    /**< API is in alpha state, i.e. work in progress. */
    RELEASE_LEVEL_BETA         = 0xB0,    /**< API is in beta state, i.e. close to be finished. */
    RELEASE_LEVEL_CANDIDATE    = 0xC0,    /**< API is in release candidate state. */
    RELEASE_LEVEL_FINAL        = 0xF0,    /**< API is in final state, i.e. officially approved. */
};

#define VERSION_REVISION 0x
#define RELEASE_LEVEL	ReleaseLevel::RELEASE_LEVEL_FINAL
#define RELEASE_SERIAL	0
#define GIT_COMMIT_VERSION ""
        
/*!
 * @brief Version as a single 4-byte hex number, e.g. 0x010502B2 == 1.5.2b2.
 *        Use this for numeric comparisons, e.g. #if PY_VERSION_HEX >= ... 
 */
#define VERSION_HEX (                                                           \
    ( << 24)     |                                       \
    ( << 16)     |                                       \
    ( <<  8)     |                                       \
    (RELEASE_LEVEL <<  4)               |                                       \
    (RELEASE_SERIAL << 0)                                                       \
)

#define EQ_VERSION_GT( MAJOR, MINOR, PATCH )                                    \
(                                                                               \
    (>MAJOR) ||                                          \
    (==MAJOR &&                                          \
    (>MINOR ||                                           \
    (==MINOR &&                                          \
    >PATCH)))                                            \
)
 
#define EQ_VERSION_GE( MAJOR, MINOR, PATCH )                                    \
(                                                                               \
    (>MAJOR) ||                                          \
    (==MAJOR &&                                          \
    (>MINOR ||                                           \
    (==MINOR &&                                          \
    >=PATCH)))                                           \
)
 
#define EQ_VERSION_LT( MAJOR, MINOR, PATCH )                                    \
(                                                                               \
    (<MAJOR) ||                                          \
    (==MAJOR &&                                          \
    (<MINOR ||                                           \
    (==MINOR &&                                          \
    <PATCH)))                                            \
)
 
#define EQ_VERSION_LE( MAJOR, MINOR, PATCH )                                    \
(                                                                               \
    (<MAJOR) ||                                          \
    (==MAJOR &&                                          \
    (<MINOR ||                                           \
    (==MINOR &&                                          \
    =PATCH)))                                            \
)

    /*! 
     * @brief The current major version. 
     */
#   define GCS_VERSION_MAJOR 

    /*!
     * @brief  The current minor version. 
     */
#   define GCS_VERSION_MINOR 

    /*!
     * @brief  The current micro version. 
     */
#   define GCS_VERSION_MICRO 
                                
    /*!
     * @brief  The current patch level.
     */
#   define GCS_VERSION_PATCH 

    /*! 
     * @brief The current SCM revision. 
     */
#   define GCS_VERSION_REVISION ""


/*!
 * @brief  True if the current version is newer than the given one. 
 */
#   define GCS_VERSION_GT( MAJOR, MINOR, PATCH )                        \
    (                                                                           \
        (GCS_VERSION_MAJOR>MAJOR) ||                                    \
        (GCS_VERSION_MAJOR==MAJOR &&                                    \
        (GCS_VERSION_MINOR>MINOR ||                                     \
        (GCS_VERSION_MINOR==MINOR &&                                    \
        GCS_VERSION_PATCH>PATCH)))                                      \
    )

/*! 
 * @brief True if the current version is equal or newer to the given. 
 */
#   define GCS_VERSION_GE( MAJOR, MINOR, PATCH )                        \
    (                                                                           \
        (GCS_VERSION_MAJOR>MAJOR) ||                                    \
        (GCS_VERSION_MAJOR==MAJOR &&                                    \
        (GCS_VERSION_MINOR>MINOR ||                                     \
        (GCS_VERSION_MINOR==MINOR &&                                    \
        GCS_VERSION_PATCH>=PATCH)))                                     \
    )

/*!
 * @brief  True if the current version is older than the given one. 
 */
#   define GCS_VERSION_LT( MAJOR, MINOR, PATCH )                        \
    (                                                                           \
        (GCS_VERSION_MAJOR<MAJOR) ||                                    \
        (GCS_VERSION_MAJOR==MAJOR &&                                    \
        (GCS_VERSION_MINOR<MINOR  ||                                    \
        (GCS_VERSION_MINOR==MINOR &&                                    \
        GCS_VERSION_PATCH<PATCH)))                                      \
    )

/*!
 * @brief  True if the current version is older or equal to the given. 
 */
#   define GCS_VERSION_LE( MAJOR, MINOR, PATCH )                        \
    (                                                                           \
        (GCS_VERSION_MAJOR<MAJOR) ||                                    \
        (GCS_VERSION_MAJOR==MAJOR &&                                    \
        (GCS_VERSION_MINOR<MINOR  ||                                    \
        (GCS_VERSION_MINOR==MINOR &&                                    \
        GCS_VERSION_PATCH<=PATCH)))                                     \
    )


class Version {
public:
    Version();
    Version(const Version& orig);
	Version( const QString& version );
    virtual ~Version();
    
    /*!
     *  @return the current major version of . 
     */
    static int getMajor();

    /*! 
     * @return the current minor version of . 
     */
    static int getMinor();

    /*! 
     * @return the current patch level of . 
     */
    static int getPatch();

    /*! 
     * @return the current  version (MM.mm.pp). 
     */
    static std::string getString();

    /*! 
     * @return the SCM revision. 
     */
    static std::string getRevision();
	
	static QString compilerString();
    /*!
     *  @return the current binary interface version of . 
     */
    static QString  getABI();

    /*! 
     * @return the current  version plus the git SHA hash (MM.mm.pp.rev). 
     */
    static std::string getRevString(); 
    /*!
     * @brief Runtime check for ABI compatibility.
     *          Call from code using . Will fail if the executable
     *          was compiled against a version incompatible with the runtime version.
     * @return true if the link-time and compile-time DSO are compatible.
     */    
    static bool check();
    /*! 
     * @return JSON schema describing this object. 
     */
    static std::string getSchema();

    /*!
     *  @return JSON-encoded data for this object. 
     */
    static std::string toJSON();

protected:

	bool operator<(const Version &rhs) const
	{	
        return compareVersion(rhs) < 0; 
    }
    
	bool operator>(const Version &rhs) const
	{	
        return compareVersion(rhs) > 0; 
    }
    
	bool operator<=(const Version &rhs) const
	{	
        return compareVersion(rhs) <= 0; 
    }
    
	bool operator>=(const Version &rhs) const
	{	
        return compareVersion(rhs) >= 0; 
    }
    
	bool operator==(const Version &rhs) const
	{	
        return compareVersion(rhs) == 0; 
    }
    
	bool operator!=(const Version &rhs) const
	{	
        return compareVersion(rhs) != 0; 
    }

private:

    unsigned int major;
    unsigned int minor;
    unsigned int micro;
    unsigned int patch; 
    unsigned int tweak;
	QString m_extra;
	QString m_version;

    int compareVersion(const Version &rhs) const;
};

#endif

