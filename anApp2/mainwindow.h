#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "anipc_in.h"
#include "anipc_out.h"
#include "anipc_in2.h"

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
    void on_pushButton_send_clicked();
    void on_showMessage(QByteArray data);

private:
    Ui::MainWindow *ui;

    QPointer<anipc_in> in_;
    QPointer<anipc_out> out_;

    anipc_in2 in2_;

};

#endif // MAINWINDOW_H
