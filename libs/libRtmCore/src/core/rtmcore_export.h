#ifndef RTMCORE_EXPORT_H
#define RTMCORE_EXPORT_H

#include <QtCore/qglobal.h>

#if defined(RTMCORE_LIBRARY)
#  define RTMCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define RTMCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // RTMCORE_EXPORT_H
