#ifndef STESOFTKEYVISUALQML_H
#define STESOFTKEYVISUALQML_H

#include <QQuickWindow>

class STESoftKey;
class STESoftKeyDescriptor;

class STESoftKeyVisualQml : public QQuickWindow
{
    Q_OBJECT
    Q_PROPERTY(QStringList hintList READ getHintList WRITE setHintList NOTIFY hintListChanged)
    Q_PROPERTY(QSize hintSize READ getHintSize NOTIFY hintSizeChanged)

public:
    explicit STESoftKeyVisualQml(QWindow* parent = 0);

    const QStringList& getHintList() {return hintList;}
    void setHintList(const QStringList& hintList);

    QSize getHintSize() {return hintSize;}

Q_SIGNALS:
    void hintListChanged();
    void clicked();
    void rotated();
    void hintSizeChanged();

private:
    QStringList hintList;
    STESoftKey* softkey;
    QSize hintSize;

    void updateSoftkeyProperty();
    STESoftKeyDescriptor* selectSoftKey();
    void resizeSoftkey(unsigned int width, unsigned int height);
};

#endif // STESOFTKEYVISUALQML_H
