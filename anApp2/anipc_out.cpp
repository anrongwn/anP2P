#include "anipc_out.h"
#include <QDebug>

anipc_out::anipc_out(QObject *parent) : QObject(parent)
{

}

anipc_out::~anipc_out()
{

}

int anipc_out::start()
{
    int r = 0;

    if(!fout_.isNull()) return r;

    fout_ = new QFile();
    if (!fout_->open(stdin, QIODevice::WriteOnly)){
        fout_.clear();
        return -1;
    }


    return r;
}

int anipc_out::sendMessge(const QString &data)
{
    int r = 0;

    if (fout_.isNull()) return -1;

    r = fout_->write(data.toLocal8Bit().constData(), data.length());
    if (r!=-1){
        if (fout_->waitForBytesWritten(5000)){
            qDebug()<<"===anipc_out::sendMessge["<<data<<"] success!";
        }
        else{
            qDebug()<<"===anipc_out::sendMessge["<<data<<"] timeout!";
        }
    }

    return r;
}
