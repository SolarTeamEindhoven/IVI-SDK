#ifndef STEDBUSVEHICLEDATA_H
#define STEDBUSVEHICLEDATA_H

#include <QObject>
#include <QList>

#include "dbusvehicledata_interface.h"

class STEVehicleData;

class STEDBusVehicleData : public QObject
{
    Q_OBJECT

public:
    explicit STEDBusVehicleData(const QString& key, QObject* parent = 0);

    void registerVicleDataObject(STEVehicleData* obj);
    void unregisterVicleDataObject(STEVehicleData* obj);

    QVariant getValue();

signals:
    void valueChanged(const QVariant& value);

private:
    QString key;
    QList<STEVehicleData*> vehicleDataObjects;
    nl::solarteameindhoven::vehicledata* dbusVehicleData;

    void dbusValueChanged(const QDBusVariant &value);
};

#endif // STEDBUSVEHICLEDATA_H
