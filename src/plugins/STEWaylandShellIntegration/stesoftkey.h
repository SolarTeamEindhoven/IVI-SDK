#ifndef STESOFTKEY_H
#define STESOFTKEY_H

#include <QObject>
#include <STESoftKey>

#include "qwayland-STE.h"

class STEShell;

class STESoftKeyWayland : public STESoftKey,  public QtWayland::ste_softkey
{
    Q_OBJECT

public:
    STESoftKeyWayland(struct ::ste_softkey* softkeyObj, STESoftKeyDescriptor* descriptor);

public slots:
    void setSurface();

protected:
    void ste_softkey_state_changed(uint32_t state) Q_DECL_OVERRIDE;
    void ste_softkey_click() Q_DECL_OVERRIDE;
    void ste_softkey_rotated(int32_t ticks, int32_t angle) Q_DECL_OVERRIDE;
    void ste_softkey_size_hint(uint32_t width, uint32_t height) Q_DECL_OVERRIDE;

private:
    bool initialized;
};

#endif // STESOFTKEY_H
