#ifndef GCS_LIBRARIES_POLICIES_API_HPP
#define GCS_LIBRARIES_POLICIES_API_HPP

#include <QtGlobal>

#if defined(_MSC_VER) || defined(__declspec)
#   define GCS_DLLEXPORT __declspec(dllexport)
#   define GCS_DLLIMPORT __declspec(dllimport)
#else
    #if __GNUC__ >= 4
        #define GCS_EXPORT      __attribute__ ((visibility ("default")))
        #define GCS_IMPORT      __attribute__ ((visibility ("default")))
        #define GCS_DLL_PUBLIC  __attribute__ ((visibility("default")))
        #define GCS_DLL_LOCAL   __attribute__ ((visibility("hidden")))
    #else
        #define GCS_EXPORT
        #define GCS_IMPORT
        #define GCS_DLL_PUBLIC
        #define GCS_DLL_LOCAL
    #endif
#endif

#ifdef __cplusplus
	#include <algorithm>

	#if !defined(GCS_NAMESPACE)

		# define GCS_PREPEND_NAMESPACE(name) ::name
		# define GCS_USE_NAMESPACE
		# define GCS_BEGIN_NAMESPACE
		# define GCS_END_NAMESPACE
		# define GCS_BEGIN_INCLUDE_NAMESPACE
		# define GCS_END_INCLUDE_NAMESPACE

		#ifndef GCS_BEGIN_MOC_NAMESPACE

			# define GCS_BEGIN_MOC_NAMESPACE

		#endif

		#ifndef GCS_END_MOC_NAMESPACE

			# define GCS_END_MOC_NAMESPACE

		#endif

		# define GCS_FORWARD_DECLARE_CLASS(name) class name;
		# define GCS_FORWARD_DECLARE_STRUCT(name) struct name;
		# define GCS_MANGLE_NAMESPACE(name) name

	#else /* user namespace */

		# define GCS_PREPEND_NAMESPACE(name) ::GCS_NAMESPACE::name
		# define GCS_USE_NAMESPACE using namespace ::GCS_NAMESPACE;
		# define GCS_BEGIN_NAMESPACE namespace GCS_NAMESPACE {
		# define GCS_END_NAMESPACE }
		# define GCS_BEGIN_INCLUDE_NAMESPACE }
		# define GCS_END_INCLUDE_NAMESPACE namespace GCS_NAMESPACE {

		#ifndef GCS_BEGIN_MOC_NAMESPACE
			# define GCS_BEGIN_MOC_NAMESPACE GCS_USE_NAMESPACE
		#endif

		#ifndef GCS_END_MOC_NAMESPACE
			# define GCS_END_MOC_NAMESPACE
		#endif

		# define GCS_FORWARD_DECLARE_CLASS(name) \
			GCS_BEGIN_NAMESPACE class name; GCS_END_NAMESPACE \
			using GCS_PREPEND_NAMESPACE(name);

		# define GCS_FORWARD_DECLARE_STRUCT(name) \
			GCS_BEGIN_NAMESPACE struct name; GCS_END_NAMESPACE \
			using GCS_PREPEND_NAMESPACE(name);

		# define GCS_MANGLE_NAMESPACE0(x) x
		# define GCS_MANGLE_NAMESPACE1(a, b) a##_##b
		# define GCS_MANGLE_NAMESPACE2(a, b) GCS_MANGLE_NAMESPACE1(a,b)
		# define GCS_MANGLE_NAMESPACE(name) GCS_MANGLE_NAMESPACE2( \
			GCS_MANGLE_NAMESPACE0(name), GCS_MANGLE_NAMESPACE0(GCS_NAMESPACE))

		namespace GCS_NAMESPACE {}

		# ifndef GCS_BOOTSTRAPPED
			# ifndef GCS_NO_USING_NAMESPACE
			   /*
				This expands to a "using GCS_NAMESPACE" also in _header files_.
				It is the only way the feature can be used without too much
				pain, but if people _really_ do not want it they can add
				DEFINES += GCS_NO_USING_NAMESPACE to their .pro files.
				*/
			   GCS_USE_NAMESPACE
			# endif
		# endif

	#endif /* user namespace */

#else /* __cplusplus */

	# define GCS_BEGIN_NAMESPACE
	# define GCS_END_NAMESPACE
	# define GCS_USE_NAMESPACE
	# define GCS_BEGIN_INCLUDE_NAMESPACE
	# define GCS_END_INCLUDE_NAMESPACE

#endif /* __cplusplus */


GCS_BEGIN_NAMESPACE

#if defined(GCS_SHARED) || !defined(GCS_STATIC)

	#  ifdef GCS_STATIC
		#    error "Both GCS_SHARED and GCS_STATIC defined, please make up your mind"
	#  endif

	#  ifndef GCS_SHARED
		#    define GCS_SHARED
	#  endif

	#  if defined(GCS_BUILD_CORE_LIB)
		#    define GCS_CORE_EXPORT GCS_DECL_EXPORT
	#  else
		#    define GCS_CORE_EXPORT GCS_DECL_IMPORT
	#  endif
#else
	#  define GCS_CORE_EXPORT
#endif

// template <typename T> static inline T *qGetPtrHelper(T *ptr) { return ptr; }
// template <typename Wrapper> static inline typename Wrapper::pointer qGetPtrHelper(const Wrapper &p) { return p.data(); }

// #define GCS_DECLARE_PRIVATE(Class) \
    // inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(qGetPtrHelper(d_ptr)); } \
    // inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(qGetPtrHelper(d_ptr)); } \
    // friend class Class##Private;

// #define GCS_DECLARE_PRIVATE_D(Dptr, Class) \
    // inline Class##Private* d_func() { return reinterpret_cast<Class##Private *>(Dptr); } \
    // inline const Class##Private* d_func() const { return reinterpret_cast<const Class##Private *>(Dptr); } \
    // friend class Class##Private;

// #define GCS_DECLARE_PUBLIC(Class)                                    \
    // inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    // inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    // friend class Class;

// #define GCS_D(Class) Class##Private * const d = d_func()
// #define GCS_Q(Class) Class * const q = q_func()

// #define DISABLE_COPY(Class) \
	// Class(const Class &) DECL_EQ_DELETE; \
	// Class &operator=(const Class &) DECL_EQ_DELETE;


#define NS_UNUSED(x) (void)(x)
#define NOOP(x) do {} while(0) //((void)0)

#endif

