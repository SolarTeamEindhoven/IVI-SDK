#ifndef STESURFACE_H
#define STESURFACE_H

#include <QObject>
#include <QTimer>

#include <QtWaylandClient/private/qwayland-wayland.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylandshellsurface_p.h>

#include "qwayland-STE.h"

namespace QtWaylandClient {
class QWaylandExtendedSurface;
}

class STESoftKeyWayland;

class STESurface : public QtWaylandClient::QWaylandShellSurface, public QtWayland::ste_shell_surface
{
    Q_OBJECT

public:
    STESurface(struct ::ste_shell_surface* surface, QtWaylandClient::QWaylandWindow *window);
    ~STESurface();

    void setType(Qt::WindowType type, QtWaylandClient::QWaylandWindow *transientParent) Q_DECL_OVERRIDE;

    Q_ENUM(sizeState)
    Q_ENUM(visibilityState)
protected:
    void ste_shell_surface_configure(uint32_t width, uint32_t height, uint32_t sizeState) Q_DECL_OVERRIDE;
    void ste_shell_surface_visibilityState(uint32_t visibilityState) Q_DECL_OVERRIDE;
    void ste_shell_surface_broadcast_available_softkey(uint32_t softkey_id, const QString &hint) Q_DECL_OVERRIDE;

private:
    QtWaylandClient::QWaylandExtendedSurface* extendedWindow;

    void setMaximized() Q_DECL_OVERRIDE;
    void setFullscreen() Q_DECL_OVERRIDE;
    void setNormal() Q_DECL_OVERRIDE;
    void setMinimized() Q_DECL_OVERRIDE;
};

#endif // STESURFACE_H
