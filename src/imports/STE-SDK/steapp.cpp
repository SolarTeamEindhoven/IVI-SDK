#include "steapp.h"

#include <QtQml/QQmlListProperty>

#include <STE-SDK/STESoftKey>
#include <STE-SDK/STEShellManager>

static QList<STEApp*> STEAppList;

STEApp::STEApp(QQuickItem *parent)
    : QQuickControl(parent)
{
    STEAppList.append(this);

    connect(STEShellManager::instance(), &STEShellManager::newSoftKey, this, &STEApp::softKeyListChanged);
    // TODO: Connect some signal to STEApp::softKeyListChanged signal
}

STEApp::~STEApp()
{
    STEAppList.removeOne(this);
}

static int count(QQmlListProperty<STESoftKey>*)
{
    return STESoftKey::getSoftKeyList().count();
}

static STESoftKey* at(QQmlListProperty<STESoftKey>*, int index)
{
    return STESoftKey::getSoftKeyList().at(index);
}

QQmlListProperty<STESoftKey> STEApp::getSoftKeyList()
{
    return QQmlListProperty<STESoftKey>(this, nullptr, count, at);
}

const QList<STEApp*>& STEApp::getAppList()
{
    return STEAppList;
}
