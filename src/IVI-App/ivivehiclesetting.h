#ifndef IVIVEHICLESETTING_H
#define IVIVEHICLESETTING_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <IVI-App/iviappglobal.h>

QT_BEGIN_NAMESPACE

class IVIDBusVehicleSetting;

class Q_IVI_APP_EXPORT IVIVehicleSetting : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString key READ getKey WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(bool isAvailable READ isAvailable NOTIFY isAvailableChanged)
    Q_PROPERTY(QVariant value READ getValue WRITE setValue NOTIFY valueChanged)

public:
    explicit IVIVehicleSetting(QObject* parent = nullptr);

    const QString& getKey() const {return key;}
    void setKey(const QString& key);
    bool isAvailable() const {return dbusVehicleSetting != nullptr;}

    QVariant getValue() const;
    void setValue(const QVariant&);

signals:
    void keyChanged();
    void isAvailableChanged();
    void valueChanged(const QVariant& value);

public slots:

private:
    QString key;
    IVIDBusVehicleSetting* dbusVehicleSetting;
};

QT_END_NAMESPACE

#endif // IVIVEHICLESETTING_H
