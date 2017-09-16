#ifndef IVIDBUSMANAGER_H
#define IVIDBUSMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QMap>
#include <QtDBus/QDBusConnection>

#include "dbusmanager_interface.h"

QT_BEGIN_NAMESPACE

class IVIDBusVehicleData;
class IVIDBusVehicleSetting;

class IVIDbusManager : public QObject
{
    Q_OBJECT
public:
    explicit IVIDbusManager(QObject* parent = 0);

    static IVIDbusManager* instance();

    QDBusConnection connection();

    QStringList getAvailableVehicleDataKeys() const;
    QStringList getAvailableVehicleSettingKeys() const;

    IVIDBusVehicleData* getDBusVehicleData(const QString& key);
    IVIDBusVehicleSetting* getDBusVehicleSetting(const QString& key);

private:
    nl::solarteameindhoven::manager dbusManager;
    QMap<QString, IVIDBusVehicleData*> availableVehicleData;
    QMap<QString, IVIDBusVehicleSetting*> availableVehicleSetting;
};

QT_END_NAMESPACE

#endif // IVIDBUSMANAGER_H
