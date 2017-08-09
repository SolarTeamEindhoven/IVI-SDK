#include "stedbusvehicledata_p.h"

#include "stedbusmanager_p.h"

QT_BEGIN_NAMESPACE

STEDBusVehicleData::STEDBusVehicleData(const QString& key, QObject* parent)
    : QObject(parent)
    , key(key)
{

}

void STEDBusVehicleData::registerVehicleDataObject(STEVehicleData* obj)
{
    if(vehicleDataObjects.contains(obj))
        return;

    if(vehicleDataObjects.size() == 0)
    {
        QDBusConnection connection = STEDbusManager::instance()->connection();
        dbusVehicleData = new nl::solarteameindhoven::vehicledata("nl.solarteameindhoven.ivi", "/VehicleData/" + key, connection, this);
        connect(dbusVehicleData, &nl::solarteameindhoven::vehicledata::valueChanged, this, &STEDBusVehicleData::dbusValueChanged);
    }

    vehicleDataObjects.append(obj);
}

void STEDBusVehicleData::unregisterVehicleDataObject(STEVehicleData* obj)
{
    vehicleDataObjects.removeOne(obj);

    if(vehicleDataObjects.size() == 0)
    {
        disconnect(dbusVehicleData, &nl::solarteameindhoven::vehicledata::valueChanged, this, &STEDBusVehicleData::dbusValueChanged);

        bool shouldEmitValueUpdate = getValue() != QVariant();

        delete dbusVehicleData;

        if(shouldEmitValueUpdate)
            emit valueChanged(QVariant());
    }
}

QVariant STEDBusVehicleData::getValue()
{
    if(dbusVehicleData == nullptr)
        return QVariant();

    return dbusVehicleData->value().variant();
}

void STEDBusVehicleData::dbusValueChanged(const QDBusVariant &value)
{
    emit valueChanged(value.variant());
}

QT_END_NAMESPACE
