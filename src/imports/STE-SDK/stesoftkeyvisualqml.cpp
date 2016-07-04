#include "stesoftkeyvisualqml.h"

#include <STESoftKey>
#include <STESoftKeyProviderWrapper>

#include <QDebug>

STESoftKeyVisualQml::STESoftKeyVisualQml(QWindow* parent)
    : QQuickWindow(parent)
    , softkey(nullptr)
{
    setColor(QColor(0, 0, 0, 0));
    setFlags(flags() | Qt::BypassWindowManagerHint);
    connect(STESoftKeyProviderWrapper::getInstance(), &STESoftKeyProviderWrapper::softkeyDescriptorsChanged, this, &STESoftKeyVisualQml::updateSoftkeyProperty);
//    show();
}

void STESoftKeyVisualQml::setHintList(const QStringList& newHintList)
{
    if(hintList == newHintList)
        return;

    hintList = newHintList;
    emit hintListChanged();
    updateSoftkeyProperty();
}

void STESoftKeyVisualQml::updateSoftkeyProperty()
{
    qDebug() << "Updating softkey using hints:" << hintList.join("; ");

    STESoftKeyDescriptor* descriptor = selectSoftKey();

    if(descriptor == nullptr)
        return;

    if(softkey && descriptor == softkey->getDescriptor())
        return;

    qDebug() << "Using softkey:" << descriptor->hint;

    STESoftKey* newSoftkey = STESoftKeyProviderWrapper::getInstance()->createSoftKey(static_cast<QWindow*>(this), descriptor);

    if(newSoftkey == nullptr)
        return;

    if(softkey != nullptr)
    {
        disconnect(softkey, &STESoftKey::clicked, this, &STESoftKeyVisualQml::clicked);
        disconnect(softkey, &STESoftKey::rotated, this, &STESoftKeyVisualQml::rotated);
        disconnect(softkey, &STESoftKey::resizeHint, this, &STESoftKeyVisualQml::resizeSoftkey);
        softkey->deleteLater();
    }

    softkey = newSoftkey;
    connect(softkey, &STESoftKey::clicked, this, &STESoftKeyVisualQml::clicked);
    connect(softkey, &STESoftKey::rotated, this, &STESoftKeyVisualQml::rotated);
    connect(softkey, &STESoftKey::resizeHint, this, &STESoftKeyVisualQml::resizeSoftkey);
}

STESoftKeyDescriptor* STESoftKeyVisualQml::selectSoftKey()
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

void STESoftKeyVisualQml::resizeSoftkey(unsigned int width, unsigned int height)
{
    hintSize.setWidth(width);
    hintSize.setHeight(height);
    emit hintSizeChanged();
}
