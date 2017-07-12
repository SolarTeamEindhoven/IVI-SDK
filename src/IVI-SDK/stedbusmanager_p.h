#ifndef STEDBUSMANAGER_H
#define STEDBUSMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QMap>
#include <QtDBus/QDBusConnection>

#include "dbusmanager_interface.h"

QT_BEGIN_NAMESPACE

class STEDBusVehicleData;

class STEDbusManager : public QObject
{
    Q_OBJECT
public:
    explicit STEDbusManager(QObject* parent = 0);

    static STEDbusManager* instance();

    QDBusConnection connection();

    QStringList getAvailableVehicleDataKeys() const;

    STEDBusVehicleData* getDBusVehicleData(const QString& key);

private:
    nl::solarteameindhoven::manager dbusManager;
    QMap<QString, STEDBusVehicleData*> availableVehicleData;
};

QT_END_NAMESPACE

#endif // STEDBUSMANAGER_H
