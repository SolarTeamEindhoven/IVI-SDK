#ifndef STESOFTKEYPROVIDER_H
#define STESOFTKEYPROVIDER_H

#include <QObject>

#include <IVI-SDK/qtstesdkglobal.h>

QT_BEGIN_NAMESPACE

class STESoftKey;
class QWindow;

struct Q_IVI_SDK_EXPORT STESoftKeyDescriptor
{
    uint32_t id;
    QString hint;
};

class Q_IVI_SDK_EXPORT STESoftKeyProvider : public QObject
{
    Q_OBJECT
public:
    explicit STESoftKeyProvider(QObject *parent = 0) : QObject(parent) {}

    virtual QList<STESoftKeyDescriptor*> getSoftKeyDescriptors() const = 0;
    virtual STESoftKey* createSoftKey(QWindow* window, STESoftKeyDescriptor* descriptor) = 0;

Q_SIGNALS:
    void softKeyDescriptorsChanged();
};

class Q_IVI_SDK_EXPORT STESoftKeyProviderWrapper : public QObject
{
    Q_OBJECT
public:
    explicit STESoftKeyProviderWrapper(QObject *parent = 0);

    QList<STESoftKeyDescriptor*> getSoftKeyDescriptors() const;
    STESoftKey* createSoftKey(STESoftKeyDescriptor* descriptor);
    STESoftKey* createSoftKey(QWindow* window, STESoftKeyDescriptor* descriptor);

    static STESoftKeyProviderWrapper* getInstance();

    STESoftKeyProvider* getSoftKeyProvider();
    void setSoftKeyProvider(STESoftKeyProvider* instance);

Q_SIGNALS:
    void softkeyDescriptorsChanged();
};

QT_END_NAMESPACE

#endif // STESOFTKEYPROVIDER_H
