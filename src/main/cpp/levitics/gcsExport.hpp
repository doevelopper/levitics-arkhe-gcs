#ifndef GCSEXPORT_HPP
#define GCSEXPORT_HPP

	#include <QtGlobal>

	#if defined(Q_OS_WIN)
	#  if defined(GCS_API_EXPORTS)
	#    define GCS_EXPORT Q_DECL_EXPORT
	#  else
	#    define GCS_EXPORT Q_DECL_IMPORT
	#  endif
	#endif

	#if !defined(GCS_EXPORT)
		#if defined(BUILD_SHARED)
			#define GCS_EXPORT Q_DECL_EXPORT
		#else
			#define GCS_EXPORT
		#endif
	#endif

#endif

