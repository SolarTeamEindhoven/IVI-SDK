#include "stevehiclesetting.h"

#include "stedbusmanager_p.h"
#include "stedbusvehiclesetting_p.h"

QT_BEGIN_NAMESPACE

STEVehicleSetting::STEVehicleSetting(QObject *parent)
    : QObject(parent)
    , dbusVehicleSetting(nullptr)
{}

void STEVehicleSetting::setKey(const QString& newKey)
{
    if(key == newKey)
        return;

    bool wasAvailable = false;

    if(dbusVehicleSetting != nullptr)
    {
        qDebug() << "Deleting old DBUS object!";
        wasAvailable = true;
        dbusVehicleSetting->unregisterVehicleSettingObject(this);
        disconnect();
    }

    key = newKey;

    qDebug() << "Creating new vehicle data object...";
    dbusVehicleSetting = STEDbusManager::instance()->getDBusVehicleSetting(key);
    if(dbusVehicleSetting != nullptr)
    {
        dbusVehicleSetting->registerVehicleSettingObject(this);
        connect(dbusVehicleSetting, &STEDBusVehicleSetting::valueChanged, this, &STEVehicleSetting::valueChanged);
    }

    emit keyChanged();

    if(isAvailable() != wasAvailable)
        emit isAvailableChanged();
}

QVariant STEVehicleSetting::getValue() const
{
    if(dbusVehicleSetting == nullptr)
        return QVariant();

    return dbusVehicleSetting->getValue();
}

void STEVehicleSetting::setValue(const QVariant& v)
{
    if(dbusVehicleSetting == nullptr)
        return;

    dbusVehicleSetting->setValue(v);
}

QT_END_NAMESPACE
