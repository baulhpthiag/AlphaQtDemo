#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ALPHAQTUTILTEMP_LIB)
#  define ALPHAQTUTILTEMP_EXPORT Q_DECL_EXPORT
# else
#  define ALPHAQTUTILTEMP_EXPORT Q_DECL_IMPORT
# endif
#else
# define ALPHAQTUTILTEMP_EXPORT
#endif
