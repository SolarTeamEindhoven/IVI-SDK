#include "stesoftkey.h"

#include "customextension.h"
#include <STESoftKeyDescriptor>

#include <QDebug>

STESoftKeyWayland::STESoftKeyWayland(bool hasSurface, struct ::ste_softkey* softkeyObj, STESoftKeyDescriptor* descriptor)
    : STESoftKey(descriptor)
    , QtWayland::ste_softkey(softkeyObj)
    , hasSurface(hasSurface)
{
    ;
}

bool STESoftKeyWayland::isVisual() const
{
    return hasSurface;
}

void STESoftKeyWayland::ste_softkey_state_changed(uint32_t s)
{
    auto newState = static_cast<QtWayland::ste_softkey::state>(s);
    switch(newState) {
    case state_active:
        state = State::Active;
        break;
    case state_inactive:
        state = State::InActive;
        break;
    case state_outofscope:
        state = State::OutOfScope;
        break;
    }
    emit stateChanged();
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
