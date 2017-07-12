#ifndef QSTESOFTKEY_H
#define QSTESOFTKEY_H

#include <QtCore/QObject>

#include <IVI-SDK/qtstesdkglobal.h>

QT_BEGIN_NAMESPACE

class STESoftKeyDescriptor;
class QWindow;

class Q_IVI_SDK_EXPORT STESoftKey : public QObject
{
    Q_OBJECT

public:
    STESoftKeyDescriptor* getDescriptor();
    qreal getRotationAngle() const;
    int getRotationTicks() const;
    virtual bool isVisual() const = 0;

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
};

Q_DECLARE_METATYPE(STESoftKey*)

QT_END_NAMESPACE

#endif // QSTESOFTKEY_H
