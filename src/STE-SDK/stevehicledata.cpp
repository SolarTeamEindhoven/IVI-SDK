#include "stevehicledata.h"

#include "stedbusmanager_p.h"
#include "stedbusvehicledata_p.h"

QT_BEGIN_NAMESPACE

STEVehicleData::STEVehicleData(QObject* parent)
    : QObject(parent)
{

}

void STEVehicleData::setKey(const QString& newKey)
{
    if(key == newKey)
        return;

    bool wasAvailable = false;

    if(dbusVehicleData != nullptr)
    {
        wasAvailable = true;
        dbusVehicleData->unregisterVicleDataObject(this);
        disconnect();
    }

    key = newKey;

    dbusVehicleData = STEDbusManager::instance()->getDBusVehicleData(key);
    dbusVehicleData->registerVicleDataObject(this);
    connect(dbusVehicleData, &STEDBusVehicleData::valueChanged, this, &STEVehicleData::valueChanged);

    emit keyChanged();

    if(isAvailable() != wasAvailable)
        emit isAvailableChanged();
}

const QVariant& STEVehicleData::getValue()
{
    if(dbusVehicleData == nullptr)
        return QVariant();

    return dbusVehicleData->getValue();
}

QT_END_NAMESPACE
