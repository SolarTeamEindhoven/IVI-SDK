#include "stesurface.h"

#include <QtWaylandClient/private/qwaylanddisplay_p.h>
#include <QtWaylandClient/private/qwaylandextendedsurface_p.h>

#include <QWindow>

#include <STEShellManager>

#include <iostream>

#include <QDebug>

#include "stesoftkey.h"
#include "stesoftkeyproviderimplementation.h"

STESurface::STESurface(struct ::ste_shell_surface* surface, QtWaylandClient::QWaylandWindow *window)
    : QWaylandShellSurface(window)
    , QtWayland::ste_shell_surface(surface)
    , extendedWindow(nullptr)
{
    if (window->display()->windowExtension())
    {
        std::cerr << "Creating extended surface..." << std::endl;
        extendedWindow = new QtWaylandClient::QWaylandExtendedSurface(window);
    }
}

STESurface::~STESurface()
{
    std::cerr << "Deleting STESurface" << std::endl;
    delete extendedWindow;
}

void STESurface::ste_shell_surface_configure(uint32_t width, uint32_t height, uint32_t state)
{
    // TODO: Little hack to keep insane big numbers (during initialization) out
    if(width > 1024*1024)
        return;
    if(height > 1024*1024)
        return;

    qWarning() << "Reconfiguring surface:" << width << '|' << height << '|' << state;
    window()->configure(0, width, height);
}

void STESurface::ste_shell_surface_visibilityState(uint32_t visibilityState)
{
    ;
}

void STESurface::ste_shell_surface_broadcast_available_softkey(uint32_t softkey_id, const QString &hint)
{
    qDebug() << "Available softkey with id:" << softkey_id << "and hint:" << hint;
    STESoftKeyDescriptor* descriptor = new STESoftKeyDescriptor();
    descriptor->id = softkey_id;
    descriptor->hint = hint;

    STESoftKeyProviderImplementation& softKeyProvider = STESoftKeyProviderImplementation::getInstance();
    softKeyProvider.addDescriptor(descriptor);

//    STESoftKeyWayland* softKey = new STESoftKeyWayland(this, softkey_id, hint);
//    emit STEShellManager::instance()->newSoftKey(softKey);
}

void STESurface::setType(Qt::WindowType type, QtWaylandClient::QWaylandWindow *transientParent)
{
    // TODO
    Q_UNUSED(type);
    Q_UNUSED(transientParent);
}

void STESurface::setMaximized()
{
    QtWayland::ste_shell_surface::resize(sizeState_maximal);
}

void STESurface::setFullscreen()
{
    ; // TODO
}

void STESurface::setNormal()
{
    QtWayland::ste_shell_surface::resize(sizeState_normal);
}

void STESurface::setMinimized()
{
    QtWayland::ste_shell_surface::resize(sizeState_minimal);
}
