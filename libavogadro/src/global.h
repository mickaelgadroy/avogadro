/**********************************************************************
  global.h - Setup some default defines.

  Copyright (C) 2006 by Geoffrey R. Hutchison
  Copyright (C) 2006 by Donald E. Curtis

  This file is part of the Avogadro molecular editor project.
  For more information, see <http://avogadro.sourceforge.net/>

  Some code is based on Open Babel
  For more information, see <http://openbabel.sourceforge.net/>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation version 2 of the License.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 ***********************************************************************/

#ifndef __GLOBAL_H
#define __GLOBAL_H

#ifdef WIN32
# ifndef NOMINMAX
#  define NOMINMAX 1
# endif
#endif

#ifdef WIN32
# define A_DECL_IMPORT __declspec(dllimport)
# define A_DECL_EXPORT __declspec(dllexport)
#else
# define A_DECL_IMPORT
# define A_DECL_EXPORT
#endif

#ifndef A_EXPORT
# ifdef avogadro_lib_EXPORTS
#  define A_EXPORT A_DECL_EXPORT
# else
#  define A_EXPORT A_DECL_IMPORT
# endif
#else
# define A_EXPORT
#endif

#endif  // __GLOBAL_H
