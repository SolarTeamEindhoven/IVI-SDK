#include "stevehicledata.h"

#include "stedbusmanager_p.h"
#include "stedbusvehicledata_p.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

STEVehicleData::STEVehicleData(QObject* parent)
    : QObject(parent)
    , key(QString::null)
    , dbusVehicleData(nullptr)
{

}

void STEVehicleData::setKey(const QString& newKey)
{
    if(key == newKey)
        return;

    bool wasAvailable = false;

    if(dbusVehicleData != nullptr)
    {
        qDebug() << "Deleting old DBUS object!";
        wasAvailable = true;
        dbusVehicleData->unregisterVehicleDataObject(this);
        disconnect();
    }

    key = newKey;

    qDebug() << "Creating new vehicle data object...";
    dbusVehicleData = STEDbusManager::instance()->getDBusVehicleData(key);
    if(dbusVehicleData != nullptr)
    {
        dbusVehicleData->registerVehicleDataObject(this);
        connect(dbusVehicleData, &STEDBusVehicleData::valueChanged, this, &STEVehicleData::valueChanged);
    }

    emit keyChanged();

    if(isAvailable() != wasAvailable)
        emit isAvailableChanged();
}

QVariant STEVehicleData::getValue()
{
    if(dbusVehicleData == nullptr)
        return QVariant();

    return dbusVehicleData->getValue();
}

QT_END_NAMESPACE
