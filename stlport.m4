# AC_LIB_STLPORT - implement the --with-stlport / --with-stlport-headers=
#                  and --with-stlport-libs= flags
# Usage: AC_LIB_STLPORT[(DEFAULT)]
#   Where DEFAULT is either `yes' or `no'. If omitted, it defaults to
#   `yes'.
#
# If all tests succeed, CPPFLAGS will be *prepended* with 
# -nostdinc++ -I<directory>
# and LIBS will be appended with
# -l<library>
#
# directory defaults to /usr/include/stlport, but can be overridden with the
# --with-stlport-headers directive;
# library defaults to stlport, and can be overridden with the 
# --with-stlport-libs directive
#
#   $Id: stlport.m4,v 1.3 2006-02-15 12:15:42 vlavrinenko Exp $
#
#   This file is (c) 2001 Jasper Spaans, <jasper@spaans.ds9a.nl> 
#   Please send your comments, suggestions and bugfixes to the above
#   e-mail address.
#
#   This program is free software; you can redistribute it and/or modify it
#   under the terms of the GNU Lesser General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or (at
#   your option) any later version.
#
#   This program is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
#   General Public License for more details.
#
#   You should have received a copy of the GNU Lesser General Public License
#   along with this program; if not, write to the Free Software Foundation,
#   Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

AC_DEFUN([AC_LIB_STLPORT],
 [define([AC_LIB_STLPORT_DEFAULT], ifelse($1, no, no, yes))dnl
  AC_MSG_CHECKING(whether to use stlport libraries)
  AC_ARG_WITH(stlport, AC_HELP_STRING(--with-stlport,use sgi stlport headers and libraries),
  [ if test "x$withval" == xno ; then
      ac_stlport_use="no"
    fi],
      ac_stlport_use=AC_LIB_STLPORT_DEFAULT)
  AC_ARG_WITH(stlport-headers, AC_HELP_STRING(--with-stlport-headers,where to find stlport headers),
  [ if test "x$withval" == xno  ; then
      ac_stlport_use="no"
    else
      ac_stlport_headers="$with_stlport_headers"
    fi],
  [
     ac_stlport_headers="/usr/include/stlport"
  ])
  AC_ARG_WITH(stlport-libs, AC_HELP_STRING(--with-stlport-libs, where to find stlport libraries),
  [ if test "x$withval" == xno  ; then
      ac_stlport_use="no"
    else
      ac_stlport_libs="$with_stlport_libs"
    fi],
  [
     ac_stlport_libs="stlport"
  ])

  if test "$ac_stlport_use" == no  ; then
    AC_MSG_RESULT(no)
  else
    AC_MSG_RESULT(yes)
    AC_MSG_CHECKING(where to find stlport headers)
    ac_stlport_save_CPPFLAGS="$CPPFLAGS"
    ac_stlport_save_LIBS="$LIBS"
    CPPFLAGS="-I$ac_stlport_headers $CPPFLAGS"
    LIBS="-l$ac_stlport_libs $LIBS"
    if test "$MSYSTEM" == "MINGW32"; then
      CPPFLAGS="$CPPFLAGS -mthreads"
    fi
    AC_LANG_PUSH(C++)
    AC_TRY_COMPILE([#include <stl/_config.h>],,

    AC_MSG_RESULT($ac_stlport_headers)
    AC_MSG_CHECKING(where to find stlport libraries)
    AC_TRY_RUN([#include <stl/_config.h>
#include <iostream>
int 
main()
{
  std::cout << "" << std::ends;
  return(0);
}
],
    AC_SUBST(CPPFLAGS)
    AC_SUBST(LIBS)
    AC_MSG_RESULT($ac_stlport_libs),
    AC_MSG_ERROR(failed)),
  AC_MSG_ERROR(failed))
  fi
])
