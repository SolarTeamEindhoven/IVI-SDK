#ifndef STEDBUSVEHICLEDATA_H
#define STEDBUSVEHICLEDATA_H

#include <QObject>
#include <QList>

#include "dbusvehicledata_interface.h"

QT_BEGIN_NAMESPACE

class STEVehicleData;

class STEDBusVehicleData : public QObject
{
    Q_OBJECT

public:
    explicit STEDBusVehicleData(const QString& key, QObject* parent = 0);

    void registerVehicleDataObject(STEVehicleData* obj);
    void unregisterVehicleDataObject(STEVehicleData* obj);

    QVariant getValue();

signals:
    void valueChanged(const QVariant& value);

private:
    QString key;
    QList<STEVehicleData*> vehicleDataObjects;
    nl::solarteameindhoven::vehicledata* dbusVehicleData;

    void dbusValueChanged(const QDBusVariant &value);
};

QT_END_NAMESPACE

#endif // STEDBUSVEHICLEDATA_H
