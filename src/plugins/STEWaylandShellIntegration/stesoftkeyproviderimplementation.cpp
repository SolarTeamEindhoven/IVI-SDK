#include "stesoftkeyproviderimplementation.h"

#include <QtWaylandClient/private/qwaylandwindow_p.h>

#include "stesoftkey.h"
#include "steshell.h"

STESoftKeyProviderImplementation STESoftKeyProviderImplementation::instance;

STESoftKeyProviderImplementation::STESoftKeyProviderImplementation(QObject *parent)
    : STESoftKeyProvider(parent)
{
    ;
}

QList<STESoftKeyDescriptor*> STESoftKeyProviderImplementation::getSoftKeyDescriptors() const
{
    return softKeyDescriptorList;
}

STESoftKey* STESoftKeyProviderImplementation::createSoftKey(QWindow* window, STESoftKeyDescriptor* descriptor)
{
    if(descriptor == nullptr)
        return nullptr;

    STEShellIntegration* shellIntegration = STEShellIntegration::getInstance();
    STEShell* shell = shellIntegration->getShell();

    if(window == nullptr)
    {
        struct ::ste_softkey* softkey = shell->create_ste_softkey(descriptor->id);
        return new STESoftKeyWayland(false, softkey, descriptor);
    }
    else
    {
        QPlatformWindow* platformWindow = window->handle();
        QtWaylandClient::QWaylandWindow* waylandWindow = static_cast<QtWaylandClient::QWaylandWindow*>(platformWindow);
        struct ::wl_surface* surface = static_cast<QtWayland::wl_surface *>(waylandWindow)->object();
        struct ::ste_softkey* softkey = shell->create_ste_softkey_with_surface(descriptor->id, surface);
        return new STESoftKeyWayland(true, softkey, descriptor);
    }
}

void STESoftKeyProviderImplementation::addDescriptor(STESoftKeyDescriptor* descriptor)
{
    softKeyDescriptorList.append(descriptor);
    emit softKeyDescriptorsChanged();
}
