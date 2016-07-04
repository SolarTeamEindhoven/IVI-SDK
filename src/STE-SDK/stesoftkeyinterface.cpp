#include "stesoftkeyinterface.h"

#include <STE-SDK/STESoftKey>

STESoftKeyInterface::STESoftKeyInterface(QObject *parent)
    : QObject(parent)
    , softkey(nullptr)
{

}

STESoftKey* STESoftKeyInterface::getSoftkey() const
{
    return softkey;
}

void STESoftKeyInterface::setSoftkey(STESoftKey* newSoftkey)
{
    if(softkey == newSoftkey)
        return;

    if(softkey != nullptr)
    {
        disconnect(softkey, &STESoftKey::clicked, this, &STESoftKeyInterface::clicked);
        disconnect(softkey, &STESoftKey::rotated, this, &STESoftKeyInterface::rotated);
    }

    softkey = newSoftkey;

    if(softkey != nullptr)
    {
        connect(softkey, &STESoftKey::clicked, this, &STESoftKeyInterface::clicked);
        connect(softkey, &STESoftKey::rotated, this, &STESoftKeyInterface::rotated);
        softkey->doInitialize();
    }

    emit softkeyChanged();
}

QString STESoftKeyInterface::getHint() const
{
    if(softkey == nullptr)
    {
        qWarning() << "Softkey not set on softkey interface!";
        return QString::null;
    }

    return softkey->getHint();
}

qreal STESoftKeyInterface::getRotationAngle() const
{
    if(softkey == nullptr)
    {
        qWarning() << "Softkey not set on softkey interface!";
        return qQNaN();
    }

    return softkey->getRotationAngle();
}

int STESoftKeyInterface::getRotationTicks() const
{
    if(softkey == nullptr)
    {
        qWarning() << "Softkey not set on softkey interface!";
        return 0;
    }

    return softkey->getRotationTicks();
}
