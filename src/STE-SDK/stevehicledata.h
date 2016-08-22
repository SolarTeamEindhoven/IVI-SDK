#ifndef STEVEHICLEDATA_H
#define STEVEHICLEDATA_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <STE-SDK/qtstesdkglobal.h>

QT_BEGIN_NAMESPACE

class STEDBusVehicleData;

class Q_STE_SDK_EXPORT STEVehicleData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString key READ getKey WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(bool isAvailable READ isAvailable NOTIFY isAvailableChanged)
    Q_PROPERTY(QVariant value READ getValue NOTIFY valueChanged)

public:
    explicit STEVehicleData(QObject* parent = 0);

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
    STEDBusVehicleData* dbusVehicleData;
};

QT_END_NAMESPACE

#endif // STEVEHICLEDATA_H
