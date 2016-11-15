#ifndef RTMCORE_GLOBAL_H
#define RTMCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RTMCORE_LIBRARY)
#  define RTMCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define RTMCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RTMCORE_GLOBAL_H
