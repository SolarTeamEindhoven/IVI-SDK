#include "ividbusvehicledata_p.h"

#include "ividbusmanager_p.h"

QT_BEGIN_NAMESPACE

IVIDBusVehicleData::IVIDBusVehicleData(const QString& key, QObject* parent)
    : QObject(parent)
    , key(key)
{

}

void IVIDBusVehicleData::regiivirVehicleDataObject(IVIVehicleData* obj)
{
    if(vehicleDataObjects.contains(obj))
        return;

    if(vehicleDataObjects.size() == 0)
    {
        QDBusConnection connection = IVIDbusManager::instance()->connection();
        dbusVehicleData = new nl::solarteameindhoven::vehicledata("nl.solarteameindhoven.ivi", "/VehicleData/" + key, connection, this);
        connect(dbusVehicleData, &nl::solarteameindhoven::vehicledata::valueChanged, this, &IVIDBusVehicleData::dbusValueChanged);
    }

    vehicleDataObjects.append(obj);
}

void IVIDBusVehicleData::unregiivirVehicleDataObject(IVIVehicleData* obj)
{
    vehicleDataObjects.removeOne(obj);

    if(vehicleDataObjects.size() == 0)
    {
        disconnect(dbusVehicleData, &nl::solarteameindhoven::vehicledata::valueChanged, this, &IVIDBusVehicleData::dbusValueChanged);

        bool shouldEmitValueUpdate = getValue() != QVariant();

        delete dbusVehicleData;

        if(shouldEmitValueUpdate)
            emit valueChanged(QVariant());
    }
}

QVariant IVIDBusVehicleData::getValue()
{
    if(dbusVehicleData == nullptr)
        return QVariant();

    return dbusVehicleData->value().variant();
}

void IVIDBusVehicleData::dbusValueChanged(const QDBusVariant &value)
{
    emit valueChanged(value.variant());
}

QT_END_NAMESPACE
