#include "anipc.h"
#include <QMessageBox>

anipc::anipc(QObject *parent) : QObject(parent)
{

}

anipc::~anipc()
{

}

void anipc::readAll()
{
    QByteArray data = handle_->readAllStandardOutput();
    emit showMessage(data);
}

void anipc::onerrorOccurred(QProcess::ProcessError error)
{
    qDebug()<<"===anipc::onerrorOccurred" << error;
}


int anipc::start(const QString &program, const QString &arguments)
{
    /*
    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"ping 192.168.250.2");
    p.waitForStarted();
    p.waitForFinished();
    QString strTemp=QString::fromLocal8Bit(p.readAllStandardOutput());

    QMessageBox testMassage;
    testMassage.setText(strTemp);
    testMassage.exec();

    return 0;
    */

    int r=0;
    if (!handle_.isNull()) return r;

    handle_ = new QProcess();
    handle_->setProcessChannelMode(QProcess::SeparateChannels);
    handle_->setReadChannel(QProcess::StandardOutput);

    QObject::connect(handle_.operator ->(), &QProcess::errorOccurred, this, &anipc::onerrorOccurred);
    QObject::connect(handle_.operator ->(), &QProcess::readyReadStandardOutput, this, &anipc::readAll);
    QObject::connect(handle_.operator ->(), &QProcess::readyRead, this, &anipc::readAll);

    QStringList alist;
    alist.append(arguments);
    handle_->start(program, alist, QIODevice::ReadWrite);

    /*//cmd.exe
    QString cmd="cmd.exe";
    alist<<"/c"<<"ping 192.168.250.2";
    handle_->start(cmd, alist, QIODevice::ReadWrite);
    */
    if (!handle_->waitForStarted()){
        qDebug()<<"===anipc::start["<<program<<", "<<alist<<"] failed.";
    }

    return r;
}

int anipc::sendMessage(const QString &data)
{
    int r=0;

    if(handle_.isNull()) return -1;

    r = handle_->write(data.toLocal8Bit().constData(), data.length());
    if (r!=-1){
        if (handle_->waitForBytesWritten(5000)){
            qDebug()<<"===anipc::sendMessge["<<data<<"] success!";

        }
        else{
            qDebug()<<"===anipc::sendMessge["<<data<<"] timeout!";
        }
    }



    return r;
}
