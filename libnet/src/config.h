/* include/config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
#undef AC_APPLE_UNIVERSAL_BUILD

/* Define if /dev/dlpi is a directory. */
#undef DLPI_DEV_PREFIX

/* Define if /dev/dlpi is available. */
#undef HAVE_DEV_DLPI

/* Define if the <sys/dlpi.h> header exists. */
#undef HAVE_DLPI

/* Define to 1 if you have the `gethostbyname2' function. */
#undef HAVE_GETHOSTBYNAME2

/* Define to 1 if you have the `getifaddrs' function. */
#undef HAVE_GETIFADDRS

/* Define if we are building on HP/UX. */
#undef HAVE_HPUX11

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the `nsl' library (-lnsl). */
#undef HAVE_LIBNSL

/* Define to 1 if you have the `packet' library (-lpacket). */
#undef HAVE_LIBPACKET

/* Define to 1 if you have the `resolv' library (-lresolv). */
#undef HAVE_LIBRESOLV

/* Define to 1 if you have the `socket' library (-lsocket). */
#undef HAVE_LIBSOCKET

/* Define to 1 if you have the `wpcap' library (-lwpcap). */
#undef HAVE_LIBWPCAP

/* Define if you have the Linux /proc filesystem. */
#undef HAVE_LINUX_PROCFS

/* Define to 1 if you have the <linux/socket.h> header file. */
#undef HAVE_LINUX_SOCKET_H

/* Define to 1 if you have the <memory.h> header file. */
#undef HAVE_MEMORY_H

/* Define to 1 if you have the <net/ethernet.h> header file. */
#undef HAVE_NET_ETHERNET_H

/* Define to 1 if you have the <net/pfilt.h> header file. */
#undef HAVE_NET_PFILT_H

/* Define to 1 if you have the <net/raw.h> header file. */
#undef HAVE_NET_RAW_H

/* Define if we're running on a Linux system with PF_PACKET sockets. */
#undef HAVE_PACKET_SOCKET

/* Define if the sockaddr structure includes a sa_len member. */
#undef HAVE_SOCKADDR_SA_LEN

/* define if socklen_t is defined */
#undef HAVE_SOCKLEN_T

/* Define if we are running on Solaris. */
#undef HAVE_SOLARIS

/* Define if our version of Solaris supports IPv6. */
#undef HAVE_SOLARIS_IPV6

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#undef HAVE_STRING_H

/* Define to 1 if you have the <sys/bufmod.h> header file. */
#undef HAVE_SYS_BUFMOD_H

/* Define to 1 if you have the <sys/dlpi_ext.h> header file. */
#undef HAVE_SYS_DLPI_EXT_H

/* Define to 1 if you have the <sys/dlpi.h> header file. */
#undef HAVE_SYS_DLPI_H

/* Define to 1 if you have the <sys/net/nit.h> header file. */
#undef HAVE_SYS_NET_NIT_H

/* Define to 1 if you have the <sys/sockio.h> header file. */
#undef HAVE_SYS_SOCKIO_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* We are running on a big-endian machine. */
#undef LIBNET_BIG_ENDIAN

/* Define if our build OS supports the BSD APIs */
#undef LIBNET_BSDISH_OS

/* Define if libnet should byteswap data. */
#undef LIBNET_BSD_BYTE_SWAP

/* We are running on a little-endian machine. */
#undef LIBNET_LIL_ENDIAN

/* Define if snprintf() is unavailable on our system. */
#undef NO_SNPRINTF

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Define if our version of Solaris has broken checksums. */
#undef STUPID_SOLARIS_CHECKSUM_BUG

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# undef _ALL_SOURCE
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# undef _GNU_SOURCE
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# undef _POSIX_PTHREAD_SEMANTICS
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# undef _TANDEM_SOURCE
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# undef __EXTENSIONS__
#endif


/* Version number of package */
#undef VERSION

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
#  undef WORDS_BIGENDIAN
# endif
#endif

/* Define as necessary to "unhide" header symbols. */
#undef _BSD_SOURCE

/* Define to 1 if on MINIX. */
#undef _MINIX

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
#undef _POSIX_1_SOURCE

/* Define to 1 if you need to in order for `stat' and other things to work. */
#undef _POSIX_SOURCE

/* Define for Solaris 2.5.1 so the uint32_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
#undef _UINT32_T

/* Define for Solaris 2.5.1 so the uint64_t typedef from <sys/synch.h>,
   <pthread.h>, or <semaphore.h> is not used. If the typedef were allowed, the
   #define below would cause a syntax error. */
#undef _UINT64_T

/* Define as necessary to "unhide" header symbols. */
#undef __BSD_SOURCE

/* Define if we should favor the BSD APIs when possible in Linux. */
#undef __FAVOR_BSD

/* Define to the type of an unsigned integer type of width exactly 16 bits if
   such a type exists and the standard includes do not define it. */
#undef uint16_t

/* Define to the type of an unsigned integer type of width exactly 32 bits if
   such a type exists and the standard includes do not define it. */
#undef uint32_t

/* Define to the type of an unsigned integer type of width exactly 64 bits if
   such a type exists and the standard includes do not define it. */
#undef uint64_t
