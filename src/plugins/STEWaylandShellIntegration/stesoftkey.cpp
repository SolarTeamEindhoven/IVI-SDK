#include "stesoftkey.h"

#include "customextension.h"
#include <STESoftKeyDescriptor>

#include <QDebug>

STESoftKeyWayland::STESoftKeyWayland(struct ::ste_softkey* softkeyObj, STESoftKeyDescriptor* descriptor)
    : STESoftKey(descriptor)
    , QtWayland::ste_softkey(softkeyObj)
{
    ;
}

void STESoftKeyWayland::setSurface()
{
//    struct ::wl_surface* surface_wl = nullptr;
//    set_surface(surface_wl);
}

void STESoftKeyWayland::ste_softkey_state_changed(uint32_t state)
{
//    emit stateChanged(state);
}

void STESoftKeyWayland::ste_softkey_click()
{
    emit clicked();
}

void STESoftKeyWayland::ste_softkey_rotated(int32_t ticks, int32_t angle)
{
    emit rotated();
//    emit rotated(ticks, angle);
}

void STESoftKeyWayland::ste_softkey_size_hint(uint32_t width, uint32_t height)
{
    emit resizeHint(width, height);
}
