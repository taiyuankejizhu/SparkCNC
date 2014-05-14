#include "scanthread.h"
#include "sparkinfo.h"
#include "fpga.h"
#include "qdebug.h"

ScanThread::ScanThread(QObject *parent) :
    QThread(parent)
{
    a_cycle = 0;
    b_cycle = 0;

    io_0 = 0x10;
    io_1 = 0x80;
    io_2 = 0x00;
    io_3 = 0x00;
    io_4 = 0x00;

}

void ScanThread::run()
{
    /*初始化IO*/
    IO0_Write(io_0);
    IO1_Write(io_1);
    IO2_Write(io_2);
    IO3_Write(io_3);
    IO4_Write(io_4);

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

        /*布尔数组发生更新，重新输出IO*/
        if(spark_info->b_array[B_UPDATE]){

            if(spark_info->b_array[B_SOUND])
                io_0 |= 0x08;
            else
                io_0 &= 0xf7;

            if(spark_info->b_array[B_PUMP])
                io_1 |= 0x10;
            else
                io_1 &= 0xef;

            if(spark_info->b_array[B_POWER])
                io_1 |= 0x80;
            else
                io_1 &= 0x7f;

            /*更新IO端口*/
            IO0_Write(io_0);
            IO1_Write(io_1);

            spark_info->b_array[B_UPDATE] = false;
        }
        else{

        }

        msleep(200);
    }

    /*to do something*/
}
