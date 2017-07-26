#ifndef STESOFTKEYQML_H
#define STESOFTKEYQML_H

#include <QObject>
#include <QQmlListProperty>

#include <IVI-SDK/STESoftKey>

class STESoftKeyDescriptor;

class STESoftKeyQml : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList hintList READ getHintList WRITE setHintList NOTIFY hintListChanged)
    Q_PROPERTY(qreal rotationAngle READ getRotationAngle NOTIFY rotated)
    Q_PROPERTY(int rotationTicks READ getRotationTicks NOTIFY rotated)
    Q_PROPERTY(STESoftKey::State state READ getState NOTIFY stateChanged)

public:
    explicit STESoftKeyQml(QObject *parent = 0);

    const QStringList& getHintList() {return hintList;}
    void setHintList(const QStringList& hintList);

    qreal getRotationAngle() const;
    int getRotationTicks() const;
    STESoftKey::State getState() const;

Q_SIGNALS:
    void hintListChanged();
    void clicked();
    void rotated();
    void stateChanged();

private:
    QStringList hintList;
    STESoftKey* softkey;

    void updateSoftkeyProperty();
    STESoftKeyDescriptor* selectSoftKey();
};

#endif // STESOFTKEYQML_H
