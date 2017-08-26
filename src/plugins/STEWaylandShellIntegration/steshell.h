#ifndef STESHELL_H
#define STESHELL_H

#include <qglobal.h>

#include <QtWaylandClient/private/qwaylandshellintegration_p.h>
#include <QMutex>

#include "customextension.h"
#include "stesoftkeyproviderimplementation.h"

class STESurface;

class STEShellIntegration : public QtWaylandClient::QWaylandShellIntegration
{
public:
    STEShellIntegration();
    virtual bool initialize(QtWaylandClient::QWaylandDisplay *display) Q_DECL_OVERRIDE;
    virtual QtWaylandClient::QWaylandShellSurface* createShellSurface(QtWaylandClient::QWaylandWindow *window) Q_DECL_OVERRIDE;

    STEShell* getShell() {return shell;}

    STESurface* getSTESurface(QWindow* window) const;

    void registerWindowAsSoftKey(QWindow* window);

    static STEShellIntegration* getInstance();

private:
    STEShell* shell;
    uint32_t lastSurfaceId;
    QMutex mutex;
    QList<QWindow*> softKeyWindows;
    QMap<QtWaylandClient::QWaylandWindow*, STESurface*> shellSurfaces;
    QMutex mutex2;

    uint32_t getNextUniqueSurfaceId();

    static void registrySTE(void *data, struct wl_registry *registry, uint32_t id,  const QString &interface, uint32_t version);
};

#endif // STESHELL_H
