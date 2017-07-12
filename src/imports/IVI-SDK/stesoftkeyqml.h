#ifndef STESOFTKEYQML_H
#define STESOFTKEYQML_H

#include <QObject>
#include <QQmlListProperty>

class STESoftKey;
class STESoftKeyDescriptor;

class STESoftKeyQml : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList hintList READ getHintList WRITE setHintList NOTIFY hintListChanged)

public:
    explicit STESoftKeyQml(QObject *parent = 0);

    const QStringList& getHintList() {return hintList;}
    void setHintList(const QStringList& hintList);

Q_SIGNALS:
    void hintListChanged();
    void clicked();
    void rotated();

private:
    QStringList hintList;
    STESoftKey* softkey;

    void updateSoftkeyProperty();
    STESoftKeyDescriptor* selectSoftKey();
};

#endif // STESOFTKEYQML_H
