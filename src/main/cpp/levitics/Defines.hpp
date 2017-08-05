#ifndef GCS_DEFINES_HPP
#define GCS_DEFINES_HPP

/*
#ifdef __APPLE__
#  include </core/platform/DefinesDarwin.hpp>
#elif defined (__linux__)
#  include </core/platform/DefinesLinux.hpp>
#elif defined (_WIN32)
#  include </core/platform/DefinesWin32.hpp>
#else
#  error Unknown OS
#  define GCS_PLATFORM_POSIX
#endi

/* #undef HAVE_FEATURES_H */
/* #undef HAVE_SYS_SYSCALL_H */
/* #undef HAVE_SYS_WAIT_H */
/* #undef HAVE_STDINT_H */
/* #undef HAVE_STRING_H */
/* #undef SIZEOF_INT */
/* #undef SIZEOF_VOIDP */
/* #undef SIZEOF_UINT */
/* #undef SIZEOF_LONG */
/* #undef SIZEOF_LONG_LONG */
/* #undef TM_IN_SYS_TIME */
/* #undef HAVE_DLFCN_H */
/* #undef HAVE_FCNTL */
/* #undef HAVE_SYS_SOCKET_H */
/* #undef HAVE_INTTYPES_H */
/* #undef HAVE_SYS_SOCKET_H */
/* #undef HAVE_GETHOSTNAME */
/* #undef HAVE_GETTIMEOFDAY */
/* #undef HAVE_CLOCK_NANOSLEEP */
/* #undef HAVE_CLOCK_GETTIME */
/* #undef HAVE_MEMORY_H */
/* #undef HAVE_MMAP */
/* #undef HAVE_MLOCKALL */
/* #undef HAVE_NETDB_H */
/* #undef HAVE_SCHED_H */
/* #undef HAVE_SETENV */
/* #undef HAVE_SETGROUPS */
/* #undef HAVE_SETPRIORITY */
/* #undef HAVE_STRFTIME */
/* #undef HAVE_SYS_IOCTL_H */
/* #undef HAVE_SYS_RESOURCE_H */
/* #undef HAVE_USLEEP */
/* #undef SIZEOF_SIZE_T */
/* #undef size_t */
/* #undef SIZEOF_VOID_P */
/* #undef HAVE_LIB_GMOCK */
/* #undef HAVE_LIBPTHREAD */
/* #undef HAVE_SYS_TYPES_H */
/* #undef HAVE_LIB_GFLAGS */
/* #undef HAVE_SYSLOG_H */
/* #undef HAVE_SYS_STAT_H */
/* #undef HAVE_SYS_SYSCALL_H */
/* #undef HAVE_SYS_TIME_H */
/* #undef HAVE_UNWIND_H */
/* #undef HAVE_UNISTD_H */
/* #undef HAVE_MALLOC_H */
/* #undef HAVE_SYS_MOUNT_H */
/* #undef HAVE_BCOPY */
/* #undef HAVE_PTHREAD_H */
/* #undef HAVE_SIGALTSTACK */
/* #undef HAVE_SIGACTION */
/* #undef HAVE_RWLOCK */
/* #undef HAVE_LINUX_WIRELESS_H */
/* #undef HAVE_NET_IF_H */
/* #undef HAVE_NET_IF_MEDIA_H */
/* #undef HAVE_GETIFADDRS */
/* #undef HAVE_FREEIFADDRS */

#ifdef HAVE_STDINT_H
    #include <stdint.h>
#endif
#ifdef HAVE_SYS_SOCKET_H
#  include <sys/socket.h>
#endif
#ifdef HAVE_INTTYPES_H 
#  include  <inttypes.h>
#endif
#ifdef HAVE_SYS_SOCKET_H 
#  include  <sys/socket.h>
#endif
#ifdef HAVE_UNISTD_H
#  include  <unistd.h> 
#endif

#endif
