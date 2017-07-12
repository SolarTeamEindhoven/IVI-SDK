#include "stedbusmanager_p.h"

#include "stedbusvehicledata_p.h"

QT_BEGIN_NAMESPACE

static STEDbusManager* dbusManagerInstance = nullptr;

STEDbusManager::STEDbusManager(QObject* parent)
    : QObject(parent)
    , dbusManager("nl.solarteameindhoven.ivi", "/Manager", QDBusConnection::sessionBus(), this)
{
}

STEDbusManager* STEDbusManager::instance()
{
    if(dbusManagerInstance == nullptr)
        dbusManagerInstance = new STEDbusManager();

    return dbusManagerInstance;
}

QDBusConnection STEDbusManager::connection()
{
    return dbusManager.connection();
}

QStringList STEDbusManager::getAvailableVehicleDataKeys() const
{
    return dbusManager.vehicle_data_keys();
}

STEDBusVehicleData* STEDbusManager::getDBusVehicleData(const QString& key)
{
    auto it = availableVehicleData.find(key);

    if(it != availableVehicleData.end())
        return it.value();

    if( getAvailableVehicleDataKeys().contains(key) )
    {
        STEDBusVehicleData* vehicleData = new STEDBusVehicleData(key, this);
        availableVehicleData.insert(key, vehicleData);
        return vehicleData;
    }

    return nullptr;
}

QT_END_NAMESPACE
