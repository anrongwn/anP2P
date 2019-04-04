#include "anipc_in.h"
#include <QDebug>

anipc_in::anipc_in(QObject *parent) : QObject(parent)
{
}

anipc_in::~anipc_in()
{

}

void anipc_in::recivMessage(int fd)
{
    if (fd!=fin_->handle()) return;

    QByteArray data = fin_->readAll();

    qDebug() << "===anipc_in::recivMessage [" << data << "]";

    emit showMessage(data);
}

int anipc_in::start()
{
    int r = 0;
    if (!fin_.isNull()) return r;

    fin_ = new QFile();
    if  (!fin_->open(stdin, QIODevice::ReadOnly)) return -1;

    fin_notifier_ = new QSocketNotifier(fin_->handle(), QSocketNotifier::Read);
    QObject::connect(fin_notifier_.operator ->(), &QSocketNotifier::activated, this, &anipc_in::recivMessage);


    return r;
}
