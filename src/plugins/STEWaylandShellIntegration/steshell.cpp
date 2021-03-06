#include "steshell.h"

#include <QtWaylandClient/private/qwaylanddisplay_p.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>

#include <STESoftKey>
#include <STESoftKeyProviderWrapper>

#include "stesurface.h"
#include "stesoftkeyproviderimplementation.h"

#include <QDebug>

STEShellIntegration::STEShellIntegration()
    : shell(NULL)
    , lastSurfaceId(0)
{
    STESoftKeyProviderWrapper::getInstance()->setSoftKeyProvider(&STESoftKeyProviderImplementation::getInstance());
}

bool STEShellIntegration::initialize(QtWaylandClient::QWaylandDisplay *display)
{
    display->addRegistryListener(&STEShellIntegration::registrySTE, this);

    return QtWaylandClient::QWaylandShellIntegration::initialize(display);
}

QtWaylandClient::QWaylandShellSurface* STEShellIntegration::createShellSurface(QtWaylandClient::QWaylandWindow* waylandWindow)
{
    if (!shell)
    {
        qDebug() << "No shell...";
        return Q_NULLPTR;
    }

    foreach(QWindow* window, softKeyWindows)
    {
        qDebug() << "Checking:" << window << "?=" << waylandWindow->window();
        if(window == waylandWindow->window())
        {
            qDebug() << "Surface is a sotfkey surface!!!";
        }
    }

    /*
    uint32_t surfaceId = getNextUniqueSurfaceId();
    if (surfaceId == 0)
    {
        std::cerr << "Invalid surface id..." << std::endl;
        return Q_NULLPTR;
    }
    */

    qDebug() << "Sending create call...";
    struct ste_shell_surface* surface = shell->create_ste_shell_surface(waylandWindow->object());
//    struct ivi_surface *surface = shell->surface_create(surfaceId, window->object());
    //if (!m_iviController)
    {
        mutex2.lock();
        STESurface* shellSurface = nullptr;

        auto it = shellSurfaces.find(waylandWindow);
        if(it != shellSurfaces.end())
        {
            qDebug() << "Already created a Shell surface for this particular window previously!!!";
            shellSurface = *it;
        }

        shellSurface = new STESurface(surface, waylandWindow);
        shellSurfaces.insert(waylandWindow, shellSurface);

        mutex2.unlock();
        return shellSurface;
    }

    /*
    if (window->window()->type() == Qt::Popup) {
        QPoint transientPos = window->geometry().topLeft(); // this is absolute
        QWaylandWindow *parent = window->transientParent();
        if (parent && parent->decoration()) {
            transientPos -= parent->geometry().topLeft();
            transientPos.setX(transientPos.x() + parent->decoration()->margins().left());
            transientPos.setY(transientPos.y() + parent->decoration()->margins().top());
        }
        QSize size = window->window()->geometry().size();
        iviSurface->ivi_controller_surface::set_destination_rectangle(transientPos.x(),
                                                                      transientPos.y(),
                                                                      size.width(),
                                                                      size.height());
    }

    return surface;
    */
}

STESurface* STEShellIntegration::getSTESurface(QWindow* window) const
{
    QPlatformWindow* platformWindow = window->handle();
    QtWaylandClient::QWaylandWindow* unsafe_waylandWindow = static_cast<QtWaylandClient::QWaylandWindow*>(platformWindow);
    auto it = shellSurfaces.find(unsafe_waylandWindow);
    if(it == shellSurfaces.end())
        return nullptr;
    else
        return it.value();
}

void STEShellIntegration::registerWindowAsSoftKey(QWindow* window)
{
    softKeyWindows.append(window);
}

STEShellIntegration* STEShellIntegration::getInstance()
{
    static STEShellIntegration shellIntegration;
    return &shellIntegration;
}

uint32_t STEShellIntegration::getNextUniqueSurfaceId()
{
    return 0;

    /*
    const uint32_t PID_MAX_EXPONENTIATION = 22; // 22 bit shift operation
    const uint32_t ID_LIMIT = 2 ^ (32 - PID_MAX_EXPONENTIATION); // 10 bit is uniqeu id
    QMutexLocker locker(&mutex);

    if (lastSurfaceId == 0)
    {
        QByteArray env = qgetenv("QT_STE_SURFACE_ID");
        bool ok;
        lastSurfaceId = env.toUInt(&ok, 10);
        if (ok)
            m_useEnvSurfaceId = true;
        else
            m_lastSurfaceId = getpid();

        return m_lastSurfaceId;
    }

    if (m_useEnvSurfaceId) {
        m_lastSurfaceId++;
    } else {
        m_surfaceNumber++;
        if (m_surfaceNumber >= ID_LIMIT) {
            qWarning("IVI surface id counter overflow\n");
            return 0;
        }
        m_lastSurfaceId += (m_surfaceNumber << PID_MAX_EXPONENTIATION);
    }

    return m_lastSurfaceId;
    */
}

void STEShellIntegration::registrySTE(void *data, struct wl_registry *registry, uint32_t id,  const QString &interface, uint32_t version)
{
    STEShellIntegration* shellIntegration = static_cast<STEShellIntegration*>(data);

    if (interface == QStringLiteral("ste_shell"))
        shellIntegration->shell = new STEShell(registry, id, version);
}

