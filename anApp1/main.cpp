#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //test
    const char qt_meta_stringdata_Object[] = {
        "Object\0Scorpio\0Author\0""1.0\0Version\0\0"
        "age\0ageChanged(int)\0score\0scoreChanged(int)\0"
        "onAgeChanged(int)\0onScoreChanged(int)\0"
        "int\0Level\0level\0Basic\0Middle\0Advanced\0"
        "Master\0"
    };

    return a.exec();
}
