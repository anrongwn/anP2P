#include "anipc_in2.h"
#include <QDebug>
#include <Windows.h>

anipc_in2::anipc_in2(QObject *parent) : QThread(parent)
{

}

void anipc_in2::run()
{
    HANDLE hStdin = INVALID_HANDLE_VALUE;
    hStdin = ::GetStdHandle(STD_INPUT_HANDLE);
    if (INVALID_HANDLE_VALUE==hStdin){
        qDebug()<<"===GetStdHandle(STD_INPUT_HANDLE)=INVALID_HANDLE_VALUE";
        return;
    }

    int message_len = 0;
    DWORD nreaded = 0;
    char message[65536] = { 0 };

    forever {
        if ( QThread::currentThread()->isInterruptionRequested() ) {
            return;
        }

        //读长度
        int r = ::ReadFile(hStdin, (void*)&message_len, sizeof(int), &nreaded, NULL);
        if ((FALSE == r) || (nreaded <= 0)) {
            continue;
        }

        //读数据
        nreaded = 0;
        r = ::ReadFile(hStdin, (void*)message, message_len, &nreaded, NULL);
        message[message_len] = '\0';

        //
        emit showMessage(QByteArray(message, message_len));
        qDebug()<<"===anipc_in2::run(),emit showMessage tid="<<QThread::currentThreadId();

    }
}


