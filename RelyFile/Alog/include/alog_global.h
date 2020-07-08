#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ALOG_LIB)
#  define ALOG_EXPORT Q_DECL_EXPORT
# else
#  define ALOG_EXPORT Q_DECL_IMPORT
# endif
#else
# define ALOG_EXPORT
#endif
