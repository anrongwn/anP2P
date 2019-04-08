#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QSocketNotifier>
#include <QTextStream>
#include <QByteArray>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList arg = QCoreApplication::arguments();
    qDebug() << arg;


    //QTextStream in(stdin);
    QTextStream out(stdout,  QIODevice::WriteOnly);

    out <<"i love you!!!"<<endl;
    out << arg.at(0) <<endl;
    out << arg.at(1) <<endl;

    a.exec();
    return 0;

}
