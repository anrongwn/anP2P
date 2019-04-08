#ifndef ANIPC_IN_H
#define ANIPC_IN_H

#include <QObject>
#include <QFile>
#include <QSocketNotifier>
#include <QByteArray>
#include <QString>
#include <QPointer>

class anipc_in : public QObject
{
    Q_OBJECT
public:
    explicit anipc_in(QObject *parent = nullptr);
    ~anipc_in();

signals:
    void showMessage(QByteArray data);

public slots:
    void recivMessage(int fd);

public:
    int start();

private:
    //QPointer<QFile> fin_;
    QPointer<QSocketNotifier> fin_notifier_;
};

#endif // ANIPC_IN_H
