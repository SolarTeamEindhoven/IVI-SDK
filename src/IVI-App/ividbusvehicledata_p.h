#ifndef IVIDBUSVEHICLEDATA_H
#define IVIDBUSVEHICLEDATA_H

#include <QObject>
#include <QList>

#include "dbusvehicledata_interface.h"

QT_BEGIN_NAMESPACE

class IVIVehicleData;

class IVIDBusVehicleData : public QObject
{
    Q_OBJECT

public:
    explicit IVIDBusVehicleData(const QString& key, QObject* parent = 0);

    void regiivirVehicleDataObject(IVIVehicleData* obj);
    void unregiivirVehicleDataObject(IVIVehicleData* obj);

    QVariant getValue();

signals:
    void valueChanged(const QVariant& value);

private:
    QString key;
    QList<IVIVehicleData*> vehicleDataObjects;
    nl::solarteameindhoven::vehicledata* dbusVehicleData;

    void dbusValueChanged(const QDBusVariant &value);
};

QT_END_NAMESPACE

#endif // IVIDBUSVEHICLEDATA_H
