#include "scanthread.h"
#include "sparkinfo.h"
#include "qdebug.h"

ScanThread::ScanThread(QObject *parent) :
    QThread(parent)
{
    a_cycle = 0;
    b_cycle = 0;
}

void ScanThread::run()
{

    while(1){

        if(a_cycle == A_CYCLE){
            /*to do*/
            a_cycle = 0;
            qDebug()<<"a mark!";
        }

        if(b_cycle == B_CYCLE){
            /*to do*/
            b_cycle = 0;
            qDebug()<<"b mark!";
        }

        if(spark_info->b_array[B_SHUTDOWN])
            a_cycle++;
        if(spark_info->b_array[B_SLEEP])
            b_cycle++;

        msleep(200);
    }

    /*to do something*/
}
