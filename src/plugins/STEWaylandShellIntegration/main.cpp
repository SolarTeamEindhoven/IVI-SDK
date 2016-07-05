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

#include <qpa/qplatformintegrationplugin.h>
#include <QtWaylandClient/private/qwaylandintegration_p.h>
#include "customextension.h"

#include <QGuiApplication>
#include <QDebug>

#include <QtWaylandClient/private/qwaylandshellintegration_p.h>
#include <QtWaylandClient/private/qwaylandshellintegrationplugin_p.h>

#include "steshell.h"

/*
class Q_WAYLAND_CLIENT_EXPORT QWaylandIviShellIntegration : public QWaylandShellIntegration
{

};
//*/

static STEShellIntegration* extension_global = NULL;
/*
class QWaylandEglPlatformIntegration : public QWaylandIntegration
{

};
*/
class CustomIntegrationPlugin : public QtWaylandClient::QWaylandShellIntegrationPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QWaylandShellIntegrationFactoryInterface_iid FILE "STEWaylandShellIntegration.json")
    //    Q_PLUGIN_METADATA(IID QPlatformIntegrationFactoryInterface_iid FILE "client.json")

public:
    QtWaylandClient::QWaylandShellIntegration* create(const QString &key, const QStringList &paramList) Q_DECL_OVERRIDE;
};

QtWaylandClient::QWaylandShellIntegration* CustomIntegrationPlugin::create(const QString& key, const QStringList& paramList)
{
    Q_UNUSED(key);
    Q_UNUSED(paramList);

    qDebug() << "************* The Qt Custom Extension Example Plugin is active ************";

    extension_global = STEShellIntegration::getInstance();

    // We need a way for client apps to get hold of the extension. The proper API for this is
    // QPlatformNativeInterface, but that's a low-level API using void*. There will be a nice
    // client API at some point, but in the meantime, it is easier to use QObject::findChild().

//    extension_global->setParent(qApp);
//    extension_global->setObjectName("qt_example_custom_extension");

    return extension_global;

//    return new STEShellIntegration();

    /*
    Q_UNUSED(paramList);
    Q_UNUSED(system);

    qDebug() << "************* The Qt Custom Extension Example Plugin is active ************";

    QWaylandIntegration *integration = new QWaylandIntegration();

    extension_global = new STEShell(integration);

    // We need a way for client apps to get hold of the extension. The proper API for this is
    // QPlatformNativeInterface, but that's a low-level API using void*. There will be a nice
    // client API at some point, but in the meantime, it is easier to use QObject::findChild().

    extension_global->setParent(qApp);
    extension_global->setObjectName("qt_example_custom_extension");

    return integration;
    */
}

#include "main.moc"
