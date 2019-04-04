#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    QString text(data);

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
    int r =0;
    r = ipc_->sendMessage(text);
    /*if (r==-1){
        qDebug() << "===MainWindow::on_pushButton_send_clicked()-sendMessage["<<text<<"] failed!";
    }*/
}
