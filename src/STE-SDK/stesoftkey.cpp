#include "stesoftkey.h"

#include <QtCore/QList>

QT_BEGIN_NAMESPACE

static QList<STESoftKey*> softKeyList;

STESoftKey::STESoftKey(STESoftKeyDescriptor* descriptor, QObject *parent)
    : QObject(parent)
    , descriptor(descriptor)
{
    softKeyList.append(this);
}

STESoftKey::~STESoftKey()
{
    softKeyList.removeOne(this);
}

STESoftKeyDescriptor* STESoftKey::getDescriptor()
{
    return descriptor;
}

qreal STESoftKey::getRotationAngle() const
{
    return 0; // TODO
}

int STESoftKey::getRotationTicks() const
{
    return 0; // TODO
}

const QList<STESoftKey*>& STESoftKey::getSoftKeyList()
{
    return softKeyList;
}

QT_END_NAMESPACE
