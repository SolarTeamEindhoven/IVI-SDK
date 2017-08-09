#ifndef STEDBUSVEHICLESETTING_P_H
#define STEDBUSVEHICLESETTING_P_H

#include <QObject>

#include "dbusvehiclesetting_interface.h"

QT_BEGIN_NAMESPACE

class STEVehicleSetting;

class STEDBusVehicleSetting : public QObject
{
    Q_OBJECT
public:
    STEDBusVehicleSetting(const QString& key, QObject* parent = 0);

    void registerVehicleSettingObject(STEVehicleSetting* obj);
    void unregisterVehicleSettingObject(STEVehicleSetting* obj);

    QVariant getValue() const;
    void setValue(const QVariant&);

signals:
    void valueChanged(const QVariant& value);

private:
    QString key;
    QList<STEVehicleSetting*> vehicleSettingObjects;
    nl::solarteameindhoven::vehiclesetting* dbusVehicleSetting;

    void dbusValueChanged(const QDBusVariant &value);
};

QT_END_NAMESPACE

#endif // STEDBUSVEHICLESETTING_P_H
