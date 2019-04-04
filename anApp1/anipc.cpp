#include "anipc.h"

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


int anipc::start(const QString &program, const QString &arguments)
{
    int r=0;
    if (!handle_.isNull()) return r;

    handle_ = new QProcess();
    QObject::connect(handle_.operator ->(), &QProcess::readyReadStandardOutput, this, &anipc::readAll);

    QStringList alist;
    alist.append(arguments);
    handle_->start(program, alist);

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
