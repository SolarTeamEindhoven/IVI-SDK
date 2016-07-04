#include "stesoftkey.h"

#include <QtCore/QList>

QT_BEGIN_NAMESPACE

static QList<STESoftKey*> softKeyList;

STESoftKey::STESoftKey(STESoftKeyDescriptor* descriptor, QObject *parent)
    : QObject(parent)
    , descriptor(descriptor)
    , window(nullptr)
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

QWindow* STESoftKey::getVisuals() const
{
    return window;
}

void STESoftKey::setVisuals(QWindow* newWindow)
{
    if(window == newWindow)
        return;

    window = newWindow;
    // TODO: Emit...
}

const QList<STESoftKey*>& STESoftKey::getSoftKeyList()
{
    return softKeyList;
}

QT_END_NAMESPACE
