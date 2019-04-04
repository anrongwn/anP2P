#ifndef ANIPC_OUT_H
#define ANIPC_OUT_H

#include <QObject>
#include <QFile>
#include <QSocketNotifier>
#include <QByteArray>
#include <QString>
#include <QPointer>

class anipc_out : public QObject
{
    Q_OBJECT
public:
    explicit anipc_out(QObject *parent = nullptr);
    ~anipc_out();
signals:

public slots:

public:
    int start();
    int sendMessge(const QString &data);
private:
    QPointer<QFile> fout_;
};

#endif // ANIPC_OUT_H
