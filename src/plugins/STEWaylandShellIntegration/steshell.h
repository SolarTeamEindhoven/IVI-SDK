#ifndef STESHELL_H
#define STESHELL_H

#include <qglobal.h>

#include <QtWaylandClient/private/qwaylandshellintegration_p.h>

#include "customextension.h"
#include "stesoftkeyproviderimplementation.h"

class STEShellIntegration : public QtWaylandClient::QWaylandShellIntegration
{
public:
    STEShellIntegration();
    virtual bool initialize(QtWaylandClient::QWaylandDisplay *display) Q_DECL_OVERRIDE;
    virtual QtWaylandClient::QWaylandShellSurface* createShellSurface(QtWaylandClient::QWaylandWindow *window) Q_DECL_OVERRIDE;

    STEShell* getShell() {return shell;}

    void registerWindowAsSoftKey(QWindow* window);

    static STEShellIntegration* getInstance();

private:
    STEShell* shell;
    uint32_t lastSurfaceId;
    QMutex mutex;
    QList<QWindow*> softKeyWindows;

    uint32_t getNextUniqueSurfaceId();

    static void registrySTE(void *data, struct wl_registry *registry, uint32_t id,  const QString &interface, uint32_t version);
    static STEShellIntegration* instance;
};

#endif // STESHELL_H
