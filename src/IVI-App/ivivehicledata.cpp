#include "ivivehicledata.h"

#include "ividbusmanager_p.h"
#include "ividbusvehicledata_p.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

IVIVehicleData::IVIVehicleData(QObject* parent)
    : QObject(parent)
    , key(QString::null)
    , dbusVehicleData(nullptr)
{

}

void IVIVehicleData::setKey(const QString& newKey)
{
    if(key == newKey)
        return;

    bool wasAvailable = false;

    if(dbusVehicleData != nullptr)
    {
        qDebug() << "Deleting old DBUS object!";
        wasAvailable = true;
        dbusVehicleData->unregiivirVehicleDataObject(this);
        disconnect();
    }

    key = newKey;

    qDebug() << "Creating new vehicle data object...";
    dbusVehicleData = IVIDbusManager::instance()->getDBusVehicleData(key);
    if(dbusVehicleData != nullptr)
    {
        dbusVehicleData->regiivirVehicleDataObject(this);
        connect(dbusVehicleData, &IVIDBusVehicleData::valueChanged, this, &IVIVehicleData::valueChanged);
    }

    emit keyChanged();

    if(isAvailable() != wasAvailable)
        emit isAvailableChanged();
}

QVariant IVIVehicleData::getValue()
{
    if(dbusVehicleData == nullptr)
        return QVariant();

    return dbusVehicleData->getValue();
}

QT_END_NAMESPACE
