#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_recv->setReadOnly(true);

    in_ = new anipc_in(nullptr);
    out_ = new anipc_out(nullptr);

    QObject::connect(in_.operator ->(), &anipc_in::showMessage, this, &MainWindow::on_showMessage);

    in_->start();
    out_->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_send_clicked()
{
    QString text = ui->textEdit_send->toPlainText();
    int r =0;
    r = out_->sendMessge(text);
    /*if (r==-1){
        qDebug() << "===MainWindow::on_pushButton_send_clicked()-sendMessage["<<text<<"] failed!";
    }*/
}

void MainWindow::on_showMessage(QByteArray data)
{
    QString text(data);

    ui->textEdit_recv->append(text);

}
