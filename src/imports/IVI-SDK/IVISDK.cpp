#include <QtQml/QQmlExtensionPlugin>
#include <IVI-SDK/STESoftKey>
#include <IVI-SDK/STEVehicleData>

#include "steapp.h"
#include "stesoftkeyqml.h"
#include "stesoftkeyvisualqml.h"

class IVISDKModule : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface/1.0")
public:
    void registerTypes(const char *uri)
    {
        Q_ASSERT(QLatin1String(uri) == QLatin1String("solarteameindhoven.sdk"));

        qmlRegisterType<STEApp>(uri, 1, 0, "App");
        qmlRegisterType<STESoftKeyQml>(uri, 1, 0, "SoftKey");
        qmlRegisterType<STESoftKeyVisualQml>(uri, 1, 0, "SoftKeyVisual");
        qmlRegisterType<STEVehicleData>(uri, 1, 0, "VehicleData");
    }

    void initializeEngine(QQmlEngine *engine, const char *uri)
    {
        Q_UNUSED(uri);
        Q_UNUSED(engine);
    }
};

#include "IVISDK.moc"
