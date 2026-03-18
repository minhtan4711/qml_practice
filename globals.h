#ifndef GLOBALS_H
#define GLOBALS_H

#include <QObject>
#include <QQmlEngine>
#include <QRandomGenerator>

class Globals : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int num MEMBER m_num NOTIFY numChanged FINAL)
    Q_PROPERTY(GeneratorStatus status MEMBER m_status NOTIFY statusChanged FINAL)
public:
    static Globals *create(QQmlEngine *qmlEngine, QJSEngine *);
    Q_INVOKABLE void generateNumber();

    enum GeneratorStatus { Ready = 0, Loading };
    Q_ENUM(GeneratorStatus);

signals:
    void numChanged();
    void statusChanged();

private:
    explicit Globals(QObject *parent = nullptr);
    int m_num = 0;
    GeneratorStatus m_status = Ready;
};

#endif // GLOBALS_H
