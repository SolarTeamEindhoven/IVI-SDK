#include "steshellmanager.h"

#include <QDebug>
#include "stedbusmanager_p.h"

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
