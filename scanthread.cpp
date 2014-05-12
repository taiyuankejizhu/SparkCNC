#include "scanthread.h"
#include "sparkinfo.h"
#include "fpga.h"
#include "qdebug.h"

ScanThread::ScanThread(QObject *parent) :
    QThread(parent)
{
    a_cycle = 0;
    b_cycle = 0;
}

void ScanThread::run()
{
    TwoBytes two;
    memset(two.bytes , 0 ,sizeof two);

    while(1){

        if(a_cycle == A_CYCLE){
            /*to do*/
            a_cycle = 0;
        }

        if(b_cycle == B_CYCLE){
            /*to do*/
            b_cycle = 0;
        }

        if(spark_info->b_array[B_SHUTDOWN])
            a_cycle++;
        if(spark_info->b_array[B_SLEEP])
            b_cycle++;

        if(spark_info->b_array[B_PUMP]){
            memset(two.bytes , 0xff ,sizeof two);
            FPGA_Write(DATA_OFFSET,two.bytes,1);
        }
        else{
            memset(two.bytes , 0x00 ,sizeof two);
            FPGA_Write(DATA_OFFSET,two.bytes,1);
        }

        msleep(10);
    }

    /*to do something*/
}
