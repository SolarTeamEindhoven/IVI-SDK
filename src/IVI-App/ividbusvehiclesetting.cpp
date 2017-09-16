#include "ividbusvehiclesetting_p.h"

#include "ividbusmanager_p.h"

QT_BEGIN_NAMESPACE

IVIDBusVehicleSetting::IVIDBusVehicleSetting(const QString& key, QObject* parent)
    : QObject(parent)
    , key(key)
{}

void IVIDBusVehicleSetting::regiivirVehicleSettingObject(IVIVehicleSetting* obj)
{
    if(vehicleSettingObjects.contains(obj))
        return;

    if(vehicleSettingObjects.size() == 0)
    {
        QDBusConnection connection = IVIDbusManager::instance()->connection();
        dbusVehicleSetting = new nl::solarteameindhoven::vehiclesetting("nl.solarteameindhoven.ivi", "/VehicleSetting/" + key, connection, this);
        connect(dbusVehicleSetting, &nl::solarteameindhoven::vehiclesetting::valueChanged, this, &IVIDBusVehicleSetting::dbusValueChanged);
    }

    vehicleSettingObjects.append(obj);
}

void IVIDBusVehicleSetting::unregiivirVehicleSettingObject(IVIVehicleSetting* obj)
{
    vehicleSettingObjects.removeOne(obj);

    if(vehicleSettingObjects.size() == 0)
    {
        disconnect(dbusVehicleSetting, &nl::solarteameindhoven::vehiclesetting::valueChanged, this, &IVIDBusVehicleSetting::dbusValueChanged);

        bool shouldEmitValueUpdate = getValue() != QVariant();

        delete dbusVehicleSetting;

        if(shouldEmitValueUpdate)
            emit valueChanged(QVariant());
    }
}

QVariant IVIDBusVehicleSetting::getValue() const
{
    if(dbusVehicleSetting == nullptr)
        return QVariant();

    return dbusVehicleSetting->value().variant();
}

void IVIDBusVehicleSetting::setValue(const QVariant& v)
{
    if(dbusVehicleSetting == nullptr)
        return;

    return dbusVehicleSetting->setValue(QDBusVariant(v));
}

void IVIDBusVehicleSetting::dbusValueChanged(const QDBusVariant &value)
{
    emit valueChanged(value.variant());
}


QT_END_NAMESPACE
