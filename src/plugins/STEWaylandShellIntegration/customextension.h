/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Wayland module
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef CUSTOMEXTENSION_H
#define CUSTOMEXTENSION_H

#include <qpa/qwindowsysteminterface.h>
#include <QtWaylandClient/private/qwayland-wayland.h>
#include "qwayland-STE.h"

class QWaylandDisplay;
class QWaylandIntegration;

class STEShell : public QObject, QtWayland::ste_shell, public QtWayland::wl_registry
{
    Q_OBJECT
public:
    //STEShell(QWaylandIntegration *wayland_integration);
    STEShell(struct ::wl_registry *registry, int id, int version);

    using QtWayland::ste_shell::create_ste_shell_surface;
    using QtWayland::ste_shell::create_ste_softkey;
    using QtWayland::ste_shell::create_ste_softkey_with_surface;

public slots:
    void sendRequest(const QString &text, int value);

signals:
    void eventReceived(const QString &text, uint value);

private:
    QWaylandDisplay *m_display;

    void registry_global(uint32_t id, const QString &interface, uint32_t version) Q_DECL_OVERRIDE;

};

#endif // CUSTOMEXTENSION_H
