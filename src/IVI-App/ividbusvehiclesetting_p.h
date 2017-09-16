#ifndef IVIDBUSVEHICLESETTING_P_H
#define IVIDBUSVEHICLESETTING_P_H

#include <QObject>

#include "dbusvehiclesetting_interface.h"

QT_BEGIN_NAMESPACE

class IVIVehicleSetting;

class IVIDBusVehicleSetting : public QObject
{
    Q_OBJECT
public:
    IVIDBusVehicleSetting(const QString& key, QObject* parent = 0);

    void regiivirVehicleSettingObject(IVIVehicleSetting* obj);
    void unregiivirVehicleSettingObject(IVIVehicleSetting* obj);

    QVariant getValue() const;
    void setValue(const QVariant&);

signals:
    void valueChanged(const QVariant& value);

private:
    QString key;
    QList<IVIVehicleSetting*> vehicleSettingObjects;
    nl::solarteameindhoven::vehiclesetting* dbusVehicleSetting;

    void dbusValueChanged(const QDBusVariant &value);
};

QT_END_NAMESPACE

#endif // IVIDBUSVEHICLESETTING_P_H
