#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Jupiter], [1.0], [jupiter-bugs@example.org])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])

#libtool
LT_PREREQ([2.2])
LT_INIT([dlopen])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
# AC_PROG_RANLIB
AC_PROG_CC_C_O

# Rules
AM_SILENT_RULES

# Checks for command-line options
AC_ARG_ENABLE([async-exec],
  [AS_HELP_STRING([--disable-async-exec],
    [disable async execution @<:@default: no@:>@])],
  [async_exec=${enableval}], [async_exec=yes])

# Checks for header files (2).
AC_CHECK_HEADERS([stdlib.h ltdl.h])

if test "x${async_exec}" = xyes; then
  have_pthreads=no
  AC_SEARCH_LIBS([pthread_create], [pthread], [have_pthreads=yes])

  if test "x${have_pthreads}" = xyes; then
    AC_CHECK_HEADERS([pthread.h], [], [have_pthreads=no])
  fi

  if test "x${have_pthreads}" = xno; then
    AC_MSG_WARN([
    ---------------------------------------------
      Unable to find pthreads on this system.
      Building a single-threaded version.
    ---------------------------------------------])
    async_exec=no
  fi
fi

if test "x${async_exec}" = xyes; then
  AC_DEFINE([ASYNC_EXEC], 1, [async execution enabled])
fi


# Checks for libraries.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.
AC_SEARCH_LIBS([lt_dlopen], [ltdl])


AC_CONFIG_FILES([Makefile
                 common/Makefile
                 include/Makefile
                 libjup/Makefile
                 src/Makefile
                 src/modules/hithere/Makefile])
AC_OUTPUT

echo \
" -----------------------------------------------
  ${PACKAGE_NAME} version ${PACKAGE_VERSION}

  Prefix: '${prefix}'.
  Compiler '${CC} ${CFLAGS} ${CPPFLAGS}'
  Libraries: '${LIBS}'

  Package features:
    Async Execution ${async_exec}

  Now type 'make @<:@<target>@:>@'
    where the optional <target> is:
      all                - build all binaries
      install            - install everything

-----------------------------------------------"
