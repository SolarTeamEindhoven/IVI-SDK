#include "stesoftkeyqml.h"

#include <STESoftKey>
#include <STESoftKeyProviderWrapper>

STESoftKeyQml::STESoftKeyQml(QObject *parent)
    : QObject(parent)
    , softkey(nullptr)
{
    connect(STESoftKeyProviderWrapper::getInstance(), &STESoftKeyProviderWrapper::softkeyDescriptorsChanged, this, &STESoftKeyQml::updateSoftkeyProperty);
}

void STESoftKeyQml::setHintList(const QStringList& newHintList)
{
    if(hintList == newHintList)
        return;

    hintList = newHintList;
    emit hintListChanged();
    updateSoftkeyProperty();
}

qreal STESoftKeyQml::getRotationAngle() const
{
    if(softkey == nullptr)
        return 0;

    return softkey->getRotationAngle();
}

int STESoftKeyQml::getRotationTicks() const
{
    if(softkey == nullptr)
        return 0;

    return softkey->getRotationTicks();
}

STESoftKey::State STESoftKeyQml::getState() const
{
    if(softkey == nullptr)
        return STESoftKey::State::Invalid;

    return softkey->getState();
}

void STESoftKeyQml::updateSoftkeyProperty()
{
    STESoftKeyDescriptor* descriptor = selectSoftKey();

    if(descriptor == nullptr)
        return;

    if(softkey && descriptor == softkey->getDescriptor())
        return;

    STESoftKey* newSoftkey = STESoftKeyProviderWrapper::getInstance()->createSoftKey(descriptor);

    if(newSoftkey == nullptr)
        return;

    if(softkey != nullptr)
    {
        disconnect(softkey, &STESoftKey::clicked, this, &STESoftKeyQml::clicked);
        disconnect(softkey, &STESoftKey::rotated, this, &STESoftKeyQml::rotated);
        disconnect(softkey, &STESoftKey::stateChanged, this, &STESoftKeyQml::stateChanged);
        softkey->deleteLater();
    }

    softkey = newSoftkey;
    connect(softkey, &STESoftKey::clicked, this, &STESoftKeyQml::clicked);
    connect(softkey, &STESoftKey::rotated, this, &STESoftKeyQml::rotated);
    connect(softkey, &STESoftKey::stateChanged, this, &STESoftKeyQml::stateChanged);
}

STESoftKeyDescriptor* STESoftKeyQml::selectSoftKey()
{
    STESoftKeyProviderWrapper* softkeyProvider = STESoftKeyProviderWrapper::getInstance();

    QList<STESoftKeyDescriptor*> softKeyDescriptorList = softkeyProvider->getSoftKeyDescriptors();

    foreach(QString hint, hintList)
    {
        foreach(STESoftKeyDescriptor* descriptor, softKeyDescriptorList)
        {
            if(hint == descriptor->hint)
                return descriptor;
        }
    }

    return nullptr;
}
