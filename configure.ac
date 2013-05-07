#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.57])
AC_INIT(1lineattime, 0.2, yazgazan@gmail.com)
AM_INIT_AUTOMAKE(1lineattime, 0.2)
AC_CONFIG_SRCDIR([src/main.c])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h unistd.h regex.h stdio.h term.h curses.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([regcomp strdup tgetent tgetstr])
AC_OUTPUT(Makefile src/Makefile)
