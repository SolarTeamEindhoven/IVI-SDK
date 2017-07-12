#include <QGuiApplication>
#include <QQuickWindow>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickWindow::setDefaultAlphaBuffer(true);

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///app.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.show();

    return app.exec();
}
