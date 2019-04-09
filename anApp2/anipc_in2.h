#ifndef ANIPC_IN2_H
#define ANIPC_IN2_H

#include <QObject>
#include <QThread>
#include <QString>
#include <QByteArray>

class anipc_in2 : public QThread
{
    Q_OBJECT
public:
    explicit anipc_in2(QObject *parent = nullptr);

signals:
    void showMessage(QByteArray data);

public slots:

protected:

    virtual void run();

public:

private:

};

#endif // ANIPC_IN2_H
