#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ALPHAQTUTIL_LIB)
#  define ALPHAQTUTIL_EXPORT Q_DECL_EXPORT
# else
#  define ALPHAQTUTIL_EXPORT Q_DECL_IMPORT
# endif
#else
# define ALPHAQTUTIL_EXPORT
#endif
