#include "stedbusvehiclesetting_p.h"

#include "stedbusmanager_p.h"

QT_BEGIN_NAMESPACE

STEDBusVehicleSetting::STEDBusVehicleSetting(const QString& key, QObject* parent)
    : QObject(parent)
    , key(key)
{}

void STEDBusVehicleSetting::registerVehicleSettingObject(STEVehicleSetting* obj)
{
    if(vehicleSettingObjects.contains(obj))
        return;

    if(vehicleSettingObjects.size() == 0)
    {
        QDBusConnection connection = STEDbusManager::instance()->connection();
        dbusVehicleSetting = new nl::solarteameindhoven::vehiclesetting("nl.solarteameindhoven.ivi", "/VehicleSetting/" + key, connection, this);
        connect(dbusVehicleSetting, &nl::solarteameindhoven::vehiclesetting::valueChanged, this, &STEDBusVehicleSetting::dbusValueChanged);
    }

    vehicleSettingObjects.append(obj);
}

void STEDBusVehicleSetting::unregisterVehicleSettingObject(STEVehicleSetting* obj)
{
    vehicleSettingObjects.removeOne(obj);

    if(vehicleSettingObjects.size() == 0)
    {
        disconnect(dbusVehicleSetting, &nl::solarteameindhoven::vehiclesetting::valueChanged, this, &STEDBusVehicleSetting::dbusValueChanged);

        bool shouldEmitValueUpdate = getValue() != QVariant();

        delete dbusVehicleSetting;

        if(shouldEmitValueUpdate)
            emit valueChanged(QVariant());
    }
}

QVariant STEDBusVehicleSetting::getValue() const
{
    if(dbusVehicleSetting == nullptr)
        return QVariant();

    return dbusVehicleSetting->value().variant();
}

void STEDBusVehicleSetting::setValue(const QVariant& v)
{
    if(dbusVehicleSetting == nullptr)
        return;

    return dbusVehicleSetting->setValue(QDBusVariant(v));
}

void STEDBusVehicleSetting::dbusValueChanged(const QDBusVariant &value)
{
    emit valueChanged(value.variant());
}


QT_END_NAMESPACE
