#ifndef ANIPC_H
#define ANIPC_H

#include <QObject>
#include <QProcess>
#include <QProcessEnvironment>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QPointer>
#include <QDebug>

class anipc : public QObject
{
    Q_OBJECT
public:
    explicit anipc(QObject *parent = nullptr);
    ~anipc();

signals:
    void showMessage(QByteArray data);

public slots:
    void readAll();
    void onerrorOccurred(QProcess::ProcessError error);

public:
    int start(const QString &program, const QString &arguments);
    int sendMessage(const QByteArray &data);
private:
    QPointer<QProcess> handle_;
};

#endif // ANIPC_H
