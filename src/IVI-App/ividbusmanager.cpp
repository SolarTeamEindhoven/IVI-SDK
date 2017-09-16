#include "ividbusmanager_p.h"

#include "ividbusvehicledata_p.h"
#include "ividbusvehiclesetting_p.h"

QT_BEGIN_NAMESPACE

static IVIDbusManager* dbusManagerInstance = nullptr;

IVIDbusManager::IVIDbusManager(QObject* parent)
    : QObject(parent)
    , dbusManager("nl.solarteameindhoven.ivi", "/Manager", QDBusConnection::sessionBus(), this)
{
}

IVIDbusManager* IVIDbusManager::instance()
{
    if(dbusManagerInstance == nullptr)
        dbusManagerInstance = new IVIDbusManager();

    return dbusManagerInstance;
}

QDBusConnection IVIDbusManager::connection()
{
    return dbusManager.connection();
}

QStringList IVIDbusManager::getAvailableVehicleDataKeys() const
{
    return dbusManager.vehicle_data_keys();
}

QStringList IVIDbusManager::getAvailableVehicleSettingKeys() const
{
    return dbusManager.vehicle_setting_keys();
}

IVIDBusVehicleData* IVIDbusManager::getDBusVehicleData(const QString& key)
{
    auto it = availableVehicleData.find(key);

    if(it != availableVehicleData.end())
        return it.value();

    if( getAvailableVehicleDataKeys().contains(key) )
    {
        IVIDBusVehicleData* vehicleData = new IVIDBusVehicleData(key, this);
        availableVehicleData.insert(key, vehicleData);
        return vehicleData;
    }

    return nullptr;
}

IVIDBusVehicleSetting* IVIDbusManager::getDBusVehicleSetting(const QString& key)
{
    auto it = availableVehicleSetting.find(key);

    if(it != availableVehicleSetting.end())
        return it.value();

    if( getAvailableVehicleDataKeys().contains(key) )
    {
        IVIDBusVehicleSetting* vehicleSetting = new IVIDBusVehicleSetting(key, this);
        availableVehicleSetting.insert(key, vehicleSetting);
        return vehicleSetting;
    }

    return nullptr;
}

QT_END_NAMESPACE
