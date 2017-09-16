#include "ivivehiclesetting.h"

#include "ividbusmanager_p.h"
#include "ividbusvehiclesetting_p.h"

QT_BEGIN_NAMESPACE

IVIVehicleSetting::IVIVehicleSetting(QObject *parent)
    : QObject(parent)
    , dbusVehicleSetting(nullptr)
{}

void IVIVehicleSetting::setKey(const QString& newKey)
{
    if(key == newKey)
        return;

    bool wasAvailable = false;

    if(dbusVehicleSetting != nullptr)
    {
        qDebug() << "Deleting old DBUS object!";
        wasAvailable = true;
        dbusVehicleSetting->unregiivirVehicleSettingObject(this);
        disconnect();
    }

    key = newKey;

    qDebug() << "Creating new vehicle data object...";
    dbusVehicleSetting = IVIDbusManager::instance()->getDBusVehicleSetting(key);
    if(dbusVehicleSetting != nullptr)
    {
        dbusVehicleSetting->regiivirVehicleSettingObject(this);
        connect(dbusVehicleSetting, &IVIDBusVehicleSetting::valueChanged, this, &IVIVehicleSetting::valueChanged);
    }

    emit keyChanged();

    if(isAvailable() != wasAvailable)
        emit isAvailableChanged();
}

QVariant IVIVehicleSetting::getValue() const
{
    if(dbusVehicleSetting == nullptr)
        return QVariant();

    return dbusVehicleSetting->getValue();
}

void IVIVehicleSetting::setValue(const QVariant& v)
{
    if(dbusVehicleSetting == nullptr)
        return;

    dbusVehicleSetting->setValue(v);
}

QT_END_NAMESPACE
