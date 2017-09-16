#ifndef IVIAPPGLOBAL_H
#define IVIAPPGLOBAL_H

#include <QtCore/qglobal.h>

QT_BEGIN_NAMESPACE

#ifndef Q_IVI_APP_EXPORT
#  ifndef QT_STATIC
#    if defined(QT_BUILD_IVI_APP_LIB)
#      define Q_IVI_APP_EXPORT Q_DECL_EXPORT
#    else
#      define Q_IVI_APP_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_IVI_APP_EXPORT
#  endif
#endif

QT_END_NAMESPACE

#endif // IVIAPPGLOBAL_H
