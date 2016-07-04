#ifndef QSTESOFTKEY_H
#define QSTESOFTKEY_H

#include <QtCore/QObject>

#include <STE-SDK/qtstesdkglobal.h>

QT_BEGIN_NAMESPACE

class STESoftKeyDescriptor;
class QWindow;

class Q_STE_SDK_EXPORT STESoftKey : public QObject
{
    Q_OBJECT

public:
    STESoftKeyDescriptor* getDescriptor();
    qreal getRotationAngle() const;
    int getRotationTicks() const;
    QWindow* getVisuals() const;

    void setVisuals(QWindow* window);

    static const QList<STESoftKey*>& getSoftKeyList();

Q_SIGNALS:
    void clicked();
    void rotated();
    void resizeHint(unsigned int width, unsigned int height);

protected:
    explicit STESoftKey(STESoftKeyDescriptor* descriptor, QObject *parent = nullptr);
    ~STESoftKey();

private:
    STESoftKeyDescriptor* descriptor;
    QWindow* window;
};

Q_DECLARE_METATYPE(STESoftKey*)

QT_END_NAMESPACE

#endif // QSTESOFTKEY_H
