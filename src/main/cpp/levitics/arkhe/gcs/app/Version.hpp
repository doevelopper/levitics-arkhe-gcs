
#ifndef GCS_CORE_VERSION_HPP
#define GCS_CORE_VERSION_HPP

#include <sstream>
#include <string>
#include <QString>
#include <QRegExp>
#include <QProcess>
#include <QUrl>
#include <QDesktopServices>
#include <levitics/app/GitRevision.hpp>
#include <levitics/app/Api.hpp>

/*!
 * @brief ReleaseLevel indicates the release level of this API
 *          This enum follows the release level convention used by python.
 * @ref https://docs.python.org/3/c-api/apiabiversion.html
 * @ref https://docs.python.org/3.7/c-api/apiabiversion.html
 * @ref https://hg.python.org/cpython/file/3.6/Include/patchlevel.h
 */
enum ReleaseLevel
{
    RELEASE_LEVEL_SNAPSHOOT    = 0xD , /**< API is not tested, work in progress. */
    RELEASE_LEVEL_ALPHA        = 0xA , /**< API is in alpha state, i.e. work in progress. */
    RELEASE_LEVEL_BETA         = 0xB , /**< API is in beta state, i.e. close to be finished. */
    RELEASE_LEVEL_CANDIDATE    = 0xC , /**< API is in release candidate state. */
    RELEASE_LEVEL_FINAL        = 0xF , /**< API is in final state, i.e. officially approved. */
};

#define RELEASE_LEVEL   ReleaseLevel::RELEASE_LEVEL_ALPHA
#define RELEASE_SERIAL  0

/*!
 * @brief Version as a single 4-byte hex number, e.g. 0x010502B2 == 1.5.2b2.
 *        Use this for numeric comparisons, e.g. #if VERSION_HEX >= ...
 */
#define VERSION_HEX (                                                           \
        (1 << 24)     |                                       \
        (5 << 16)     |                                       \
        (2 <<  8)     |                                       \
        (RELEASE_LEVEL <<  4)               |                                       \
        (RELEASE_SERIAL << 0)                                                       \
        )

#define EQ_VERSION_GT( MAJOR , MINOR , PATCH )                                    \
    (                                                                               \
        (1 > MAJOR) ||                                          \
        (1 == MAJOR &&                                          \
         (5 > MINOR ||                                           \
          (5 == MINOR &&                                          \
           2 > PATCH)))                                            \
    )

#define EQ_VERSION_GE( MAJOR , MINOR , PATCH )                                    \
    (                                                                               \
        (1 > MAJOR) ||                                          \
        (1 == MAJOR &&                                          \
         (5 > MINOR ||                                           \
          (5 == MINOR &&                                          \
           2 >= PATCH)))                                           \
    )

#define EQ_VERSION_LT( MAJOR , MINOR , PATCH )                                    \
    (                                                                               \
        (1 < MAJOR) ||                                          \
        (1 == MAJOR &&                                          \
         (5 < MINOR ||                                           \
          (5 == MINOR &&                                          \
           2 < PATCH)))                                            \
    )

#define EQ_VERSION_LE( MAJOR , MINOR , PATCH )                                    \
    (                                                                               \
        (1 < MAJOR) ||                                          \
        (1 == MAJOR &&                                          \
         (5 < MINOR ||                                           \
          (5 == MINOR &&                                          \
           2 = PATCH)))                                            \
    )

/*!
 * @brief The current major version.
 */
#define VERSION_MAJOR 1

/*!
 * @brief  The current minor version.
 */
#define VERSION_MINOR 5

/*!
 * @brief  The current patch level.
 */
#define VERSION_TWEAK 1101

/*!
 * @brief  The current micro version.
 */
#define VERSION_PATCH 2

/*!
 * @brief The current SCM revision.
 */
#define SHAH_VERSION_REVISION HASH


/*!
 * @brief  True if the current version is newer than the given one.
 */
#define VERSION_GT( MAJOR , MINOR , PATCH )                        				\
    (                                                                           \
        (VERSION_MAJOR > MAJOR) ||                                    			\
        (VERSION_MAJOR == MAJOR &&                                    			\
         (VERSION_MINOR > MINOR ||                                     			\
          (VERSION_MINOR == MINOR &&                                    		\
           VERSION_PATCH > PATCH)))                                      		\
    )

/*!
 * @brief True if the current version is equal or newer to the given.
 */
#define VERSION_GE( MAJOR , MINOR , PATCH )                        				\
    (                                                                           \
        (VERSION_MAJOR > MAJOR) ||                                    			\
        (VERSION_MAJOR == MAJOR &&                                    			\
         (VERSION_MINOR > MINOR ||                                     			\
          (VERSION_MINOR == MINOR &&                                    		\
           VERSION_PATCH >= PATCH)))                                     		\
    )

/*!
 * @brief  True if the current version is older than the given one.
 */
#define VERSION_LT( MAJOR , MINOR , PATCH )                        				\
    (                                                                           \
        (VERSION_MAJOR < MAJOR) ||                                  			\
        (VERSION_MAJOR == MAJOR &&                                  			\
         (VERSION_MINOR < MINOR  ||                                 			\
          (VERSION_MINOR == MINOR &&                                			\
           VERSION_PATCH < PATCH)))                                 			\
    )

/*!
 * @brief  True if the current version is older or equal to the given.
 */
#define VERSION_LE( MAJOR , MINOR , PATCH )                        				\
    (                                                                           \
        (VERSION_MAJOR < MAJOR) ||                                    			\
        (VERSION_MAJOR == MAJOR &&                                    			\
         (VERSION_MINOR < MINOR  ||                                    			\
          (VERSION_MINOR == MINOR &&                                    		\
           VERSION_PATCH <= PATCH)))                                     		\
    )


class Version {
public:

    Version();
    Version(const Version &orig);
    Version( const QString &version );
    virtual ~Version();

    /*!
     *  @return the current major version of .
     */
    static int getMajor ();

    /*!
     * @return the current minor version of .
     */
    static int getMinor ();

    /*!
     * @return the current patch level of .
     */
    static int getPatch ();

    /*!
     * @return the current  version (MM.mm.pp).
     */
    static std::string getString ();

    /*!
     * @return the SCM revision.
     */
    static std::string getRevision ();

    static QString compilerString ();
    /*!
     *  @return the current binary interface version of .
     */
    static QString  getABI ();

    /*!
     * @return the current  version plus the git SHA hash (MM.mm.pp.rev).
     */
    static std::string getRevString ();
    /*!
     * @brief Runtime check for ABI compatibility.
     *          Call from code using . Will fail if the executable
     *          was compiled against a version incompatible with the runtime version.
     * @return true if the link-time and compile-time DSO are compatible.
     */
    static bool check ();
    /*!
     * @return JSON schema describing this object.
     */
    static std::string getSchema ();

    /*!
     *  @return JSON-encoded data for this object.
     */
    static std::string toJSON ();

protected:

    bool operator < (const Version &rhs) const
    {
        return compareVersion(rhs) < 0;
    }

    bool operator > (const Version &rhs) const
    {
        return compareVersion(rhs) > 0;
    }

    bool operator <= (const Version &rhs) const
    {
        return compareVersion(rhs) <= 0;
    }

    bool operator >= (const Version &rhs) const
    {
        return compareVersion(rhs) >= 0;
    }

    bool operator == (const Version &rhs) const
    {
        return compareVersion(rhs) == 0;
    }

    bool operator != (const Version &rhs) const
    {
        return compareVersion(rhs) != 0;
    }

private:

    unsigned int major;
    unsigned int minor;
    unsigned int patch;
    unsigned int tweak;
    QString m_extra;
    QString m_version;

    int compareVersion (const Version &rhs) const;
};

#endif
