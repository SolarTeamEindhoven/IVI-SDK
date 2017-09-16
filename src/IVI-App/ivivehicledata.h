#ifndef IVIVEHICLEDATA_H
#define IVIVEHICLEDATA_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <IVI-App/iviappglobal.h>

QT_BEGIN_NAMESPACE

class IVIDBusVehicleData;

class Q_IVI_APP_EXPORT IVIVehicleData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString key READ getKey WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(bool isAvailable READ isAvailable NOTIFY isAvailableChanged)
    Q_PROPERTY(QVariant value READ getValue NOTIFY valueChanged)

public:
    explicit IVIVehicleData(QObject* parent = 0);

    const QString& getKey() const {return key;}
    void setKey(const QString& key);
    bool isAvailable() const {return dbusVehicleData != nullptr;}

    QVariant getValue();

signals:
    void keyChanged();
    void isAvailableChanged();
    void valueChanged(const QVariant& value);

public slots:

private:
    QString key;
    IVIDBusVehicleData* dbusVehicleData;
};

QT_END_NAMESPACE

#endif // IVIVEHICLEDATA_H
