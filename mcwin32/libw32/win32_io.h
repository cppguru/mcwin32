#ifndef LIBW32_WIN32_IO_H_INCLUDED
#define LIBW32_WIN32_IO_H_INCLUDED
#include <edidentifier.h>
__CIDENT_RCSID(gr_libw32_win32_io_h,"$Id: win32_io.h,v 1.20 2021/06/20 06:42:02 cvsuser Exp $")
__CPRAGMA_ONCE

/* -*- mode: c; indent-width: 4; -*- */
/*
 * win32 io functionality.
 *
 * Copyright (c) 2007, 2012 - 2021 Adam Young.
 * All rights reserved.
 *
 * This file is part of the Midnight Commander.
 *
 * The Midnight Commander is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * The Midnight Commander is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ==end==
 */

#undef DATADIR                                  /* namespace issue */

#if defined(_MSC_VER)
#if (_MSC_VER != 1200)                          /* MSVC 6 */
#if (_MSC_VER != 1400)                          /* MSVC 8/2005 */
#if (_MSC_VER != 1500)                          /* MSVC 9/2008 */
#if (_MSC_VER != 1600)                          /* MSVC 10/2010 */
#if (_MSC_VER != 1900)                          /* MSVC 19/2015 */
#if (_MSC_VER <  1910 || _MSC_VER > 1916)       /* MSVC 19.10 .. 16/2017 */
#if (_MSC_VER > 1929)                           /* MSVC 19.20 / 2019.09 */
#error unistd.h: untested MSVC Version (2005 -- 2019.08) only ...
	 //see: https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B
#endif //2019
#endif //2017
#endif //2015
#endif //2010
#endif //2008
#endif //2005
#endif //_MSC_VER

#pragma  warning(disable:4115)

#elif defined(__WATCOMC__)
#if (__WATCOMC__ < 1200)
#error old WATCOM Version, upgrade to OpenWatcom ...
#endif

#elif defined(__MINGW32__)
#else
#error win32_io.h: unknown/unsupported compiler
#endif

#if !defined(_WIN32_WINCE)                      /* require winsock2.h */
#ifndef _WIN32_WINNT
#define _WIN32_WINNT        0x601               /* latest features */
#elif (_WIN32_WINNT) < 0x400
#pragma message("unistd: _WIN32_WINNT < 0400")
#endif
#endif  /*_WIN32_WINCE*/

#include <win32_include.h>

#include <sys/cdefs.h>                          /* __BEGIN_DECLS, __PDECL */

__BEGIN_DECLS

/*fcntl.h*/
#if !defined(F_GETTL)
#define F_GETFL         1
#define F_SETFL         2
#endif

LIBW32_API int          fcntl (int fildes, int ctrl, int);
LIBW32_API int          w32_fcntl (int fildes, int ctrl, int);
LIBW32_API int          w32_fsync (int fildes);

/*io.h*/
struct stat;

LIBW32_API int          w32_open (const char *path, int, ...);
LIBW32_API int          w32_openA (const char *path, int, int);
LIBW32_API int          w32_openW (const wchar_t *path, int, int);

LIBW32_API int          w32_stat (const char *path, struct stat *sb);
LIBW32_API int          w32_statA (const char *path, struct stat *sb);
LIBW32_API int          w32_statW (const wchar_t *path, struct stat *sb);
LIBW32_API int          w32_lstat (const char *path, struct stat *sb);
LIBW32_API int          w32_lstatA (const char *path, struct stat *sb);
LIBW32_API int          w32_lstatW (const wchar_t *path, struct stat *sb);

LIBW32_API int          w32_read (int fildes, void *buf, size_t nbyte);
LIBW32_API int          w32_write (int fildes, const void *buf, size_t nbyte);

LIBW32_API int          w32_close (int fildes);
LIBW32_API const char * w32_strerror (int errnum);

LIBW32_API int          w32_mkstemp (char *path);
LIBW32_API int          w32_mkstempA (char *path);
LIBW32_API int          w32_mkstempW (wchar_t *path);

LIBW32_API int          w32_mkstemps (char *path, int suffixlen);
LIBW32_API int          w32_mkstempsA (char *path, int suffixlen);
LIBW32_API int          w32_mkstempsW (wchar_t *path, int suffixlen);

LIBW32_API int          w32_mkstempx (char *path);
LIBW32_API int          w32_mkstempxA (char *path);
LIBW32_API int          w32_mkstempxW (wchar_t *path);

LIBW32_API int          w32_link (const char *path1, const char *path2);
LIBW32_API int          w32_linkA (const char *path1, const char *path2);
LIBW32_API int          w32_linkW (const wchar_t *path1, const wchar_t *path2);

LIBW32_API int          w32_unlink (const char *fname);
LIBW32_API int          w32_unlinkA (const char *fname);
LIBW32_API int          w32_unlinkW (const wchar_t *fname);

LIBW32_API int          w32_rename (const char *ofile, const char *nfile);
LIBW32_API int          w32_renameA (const char *ofile, const char *nfile);
LIBW32_API int          w32_renameW (const wchar_t *ofile, const wchar_t *nfile);

LIBW32_API char *       w32_getcwd (char *buffer, int size);
LIBW32_API char *       w32_getcwdA (char *buffer, int size);
LIBW32_API wchar_t *    w32_getcwdW (wchar_t *buffer, int size);

LIBW32_API char *       w32_getcwdd (char drive, char *path, int size);
LIBW32_API char *       w32_getcwddA (char drive, char *path, int size);
LIBW32_API wchar_t *    w32_getcwddW (char drive, wchar_t *path, int size);

LIBW32_API int          w32_getdrive (void);
LIBW32_API int          w32_getsystemdrive (void);
LIBW32_API int          w32_getlastdrive (void);

LIBW32_API int          w32_mkdir (const char *path, int mode);
LIBW32_API int          w32_mkdirA (const char *path, int mode);
LIBW32_API int          w32_mkdirW (const wchar_t *path, int mode);

LIBW32_API int          w32_chdir (const char *path);
LIBW32_API int          w32_chdirA (const char *path);
LIBW32_API int          w32_chdirW (const wchar_t *path);

LIBW32_API int          w32_rmdir (const char *path);
LIBW32_API int          w32_rmdirA (const char *path);
LIBW32_API int          w32_rmdirW (const wchar_t *path);

/*support functions*/

#define SHORTCUT_TRAILING   0x01
#define SHORTCUT_COMPONENT  0x02

LIBW32_API int          w32_lnkexpandA (const char *name, char *buf, size_t buflen, unsigned flags);
LIBW32_API int          w32_lnkexpandW (const wchar_t *name, wchar_t *buf, size_t buflen, unsigned flags);

LIBW32_API const char * w32_strslash (const char *path);
LIBW32_API const wchar_t *w32_wcsslash (const wchar_t *path);

LIBW32_API int          w32_errno_set (void);
LIBW32_API int          w32_errno_setas (unsigned nerrno);
LIBW32_API int          w32_errno_cnv (unsigned rc);
LIBW32_API int          w32_neterrno_set (void);

__END_DECLS

#endif /*LIBW32_WIN32_IO_H_INCLUDED*/
