#ifndef STESOFTKEYPROVIDERIMPLEMENTATION_H
#define STESOFTKEYPROVIDERIMPLEMENTATION_H

#include <IVI-SDK/STESoftKeyProvider>

class STESoftKeyProviderImplementation : public STESoftKeyProvider
{
    Q_OBJECT

public:
    explicit STESoftKeyProviderImplementation(QObject *parent = 0);

    QList<STESoftKeyDescriptor*> getSoftKeyDescriptors() const Q_DECL_OVERRIDE;
    STESoftKey* createSoftKey(QWindow* window, STESoftKeyDescriptor* descriptor) Q_DECL_OVERRIDE;

    void addDescriptor(STESoftKeyDescriptor* descriptor);

    static STESoftKeyProviderImplementation& getInstance();

private:
    QList<STESoftKeyDescriptor*> softKeyDescriptorList;
};

#endif // STESOFTKEYPROVIDERIMPLEMENTATION_H
