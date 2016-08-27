#ifndef STEAPP_H
#define STEAPP_H

#include <QtQuickTemplates2/private/qquickcontrol_p.h>

QT_BEGIN_NAMESPACE

class STESoftKey;

class STEApp : public QQuickControl //QQuickItem
{
    Q_OBJECT
//    Q_PROPERTY(QQmlListProperty<STESoftKey> softKeyList READ getSoftKeyList NOTIFY softKeyListChanged)

public:
    explicit STEApp(QQuickItem* parent = Q_NULLPTR);
    ~STEApp();

//    QQmlListProperty<STESoftKey> getSoftKeyList();

    static const QList<STEApp*>& getAppList();

//Q_SIGNALS:
//    void softKeyListChanged();
};

QT_END_NAMESPACE

#endif // STEAPP_H
