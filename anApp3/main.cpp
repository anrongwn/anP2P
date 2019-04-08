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

    QTextStream in(fileno(stdin));

    forever{
        QString data = in.readLine();
        if (!data.isEmpty()){
            qDebug() << data;
        }
    }

    return a.exec();
}
