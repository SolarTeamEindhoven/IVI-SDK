#include "stesoftkeyprovider.h"

#include <QDebug>

static STESoftKeyProviderWrapper softKeyProviderWrapper;
static STESoftKeyProvider* globalInstance = nullptr;

STESoftKeyProviderWrapper::STESoftKeyProviderWrapper(QObject *parent)
    : QObject(parent)
{
    ;
}

QList<STESoftKeyDescriptor*> STESoftKeyProviderWrapper::getSoftKeyDescriptors() const
{
    if(globalInstance == nullptr)
        return QList<STESoftKeyDescriptor*>();

    return globalInstance->getSoftKeyDescriptors();
}

STESoftKey* STESoftKeyProviderWrapper::createSoftKey(STESoftKeyDescriptor* descriptor)
{
    if(globalInstance == nullptr)
        return nullptr;

    return globalInstance->createSoftKey(nullptr, descriptor);
}

STESoftKey* STESoftKeyProviderWrapper::createSoftKey(QWindow* window, STESoftKeyDescriptor* descriptor)
{
    if(globalInstance == nullptr)
        return nullptr;

    return globalInstance->createSoftKey(window, descriptor);
}

STESoftKeyProviderWrapper* STESoftKeyProviderWrapper::getInstance()
{
    return &softKeyProviderWrapper;
}

STESoftKeyProvider* STESoftKeyProviderWrapper::getSoftKeyProvider()
{
    return globalInstance;
}

void STESoftKeyProviderWrapper::setSoftKeyProvider(STESoftKeyProvider* instance)
{
    if(globalInstance == instance)
        return;

    if(globalInstance != nullptr)
    {
        disconnect(globalInstance, &STESoftKeyProvider::softKeyDescriptorsChanged, this, &STESoftKeyProviderWrapper::softkeyDescriptorsChanged);
        qWarning() << "SoftKey provider already set!";
    }

    globalInstance = instance;

    connect(instance, &STESoftKeyProvider::softKeyDescriptorsChanged, this, &STESoftKeyProviderWrapper::softkeyDescriptorsChanged);
    if(!instance->getSoftKeyDescriptors().isEmpty())
        emit softkeyDescriptorsChanged();
}
