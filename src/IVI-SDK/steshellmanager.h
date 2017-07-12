#ifndef STESHELLMANAGER_H
#define STESHELLMANAGER_H

#include <QtCore/QObject>

#include <IVI-SDK/qtstesdkglobal.h>

QT_BEGIN_NAMESPACE

class STESoftKey;

class Q_IVI_SDK_EXPORT STEShellManager : public QObject
{
    Q_OBJECT
public:
    explicit STEShellManager(QObject *parent = 0);

    static STEShellManager* instance();

Q_SIGNALS:
    void newSoftKey(STESoftKey* softkey);
};

QT_END_NAMESPACE

#endif // STESHELLMANAGER_H
