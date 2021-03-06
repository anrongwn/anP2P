#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDataStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit_reciv->setReadOnly(true);
    ui->lineEdit_exe->setText(QString(R"(D:\MyTest\2019_Qt\build-anP2P-Desktop_Qt_5_12_1_MSVC2017_32bit-Debug\anApp2\debug\anApp2.exe)"));
    ui->lineEdit_pa1->setText("wangjr");

    ipc_ = new anipc(nullptr);
    QObject::connect(ipc_.operator ->(), &anipc::showMessage, this, &MainWindow::on_showMessage);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_showMessage(QByteArray data){

    QString text =QString::fromLocal8Bit(data);//防止中文乱码

    ui->textEdit_reciv->append(text);
}

void MainWindow::on_pushButton_open_clicked()
{
    QString program, arg;
    program=ui->lineEdit_exe->text();
    arg=ui->lineEdit_pa1->text();

    int r =0;
    r = ipc_->start(program, arg);
}

void MainWindow::on_pushButton_send_clicked()
{
    QString text = ui->textEdit_send->toPlainText();
    text+="\r\n";
    int r =0;
    int len = text.toLocal8Bit().length();
    QByteArray data;
    data.append((char*)&len, sizeof(int));
    data.append(text.toLocal8Bit().data(), text.toLocal8Bit().length());

    //len = data.length();

    r = ipc_->sendMessage(data);
    /*if (r==-1){
        qDebug() << "===MainWindow::on_pushButton_send_clicked()-sendMessage["<<text<<"] failed!";
    }*/
}
