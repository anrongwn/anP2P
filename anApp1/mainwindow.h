#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "anipc.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showMessage(QByteArray data);

    void on_pushButton_open_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;
    QPointer<anipc> ipc_;
};

#endif // MAINWINDOW_H
