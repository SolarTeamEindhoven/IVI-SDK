#include "steshellmanager.h"

#include <QDebug>
#include "stedbusmanager_p.h"

QT_BEGIN_NAMESPACE

static STEShellManager shellManagerInstance;

STEShellManager::STEShellManager(QObject *parent)
    : QObject(parent)
{

}

STEShellManager* STEShellManager::instance()
{
    qDebug() << "Available vehicle data keys:" << STEDbusManager::instance()->getAvailableVehicleDataKeys();

    return &shellManagerInstance;
}

QT_END_NAMESPACE
