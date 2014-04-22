#include "sparkthread.h"
#include "qdebug.h"
#include "sparkinfo.h"

SparkThread::SparkThread(QObject *parent) :
    QThread(parent)
{
}

void SparkThread::run()
{
    while(spark_info->b_array[B_START]){

        if(spark_info->l_array[L_DEEP_CURRENT] >= spark_info->table.Shendu[spark_info->uint_array[UINT_CURRENT_ROM]]){

            if(spark_info->uint_array[UINT_CURRENT_ROM] < spark_info->uint_array[UINT_END_ROW]){
                spark_info->setUInt(UINT_CURRENT_ROM ,++spark_info->uint_array[UINT_CURRENT_ROM]);
                spark_info->setLong(L_DEEP_TARGET ,spark_info->table.Shendu[spark_info->uint_array[UINT_CURRENT_ROM]]);
            }
            else{
                spark_info->setUInt(UINT_CURRENT_ROM ,spark_info->uint_array[UINT_END_ROW]);
                spark_info->setLong(L_DEEP_TARGET ,spark_info->table.Shendu[spark_info->uint_array[UINT_CURRENT_ROM]]);

                spark_info->reverseBool(B_START);
                break;
            }

        }

        spark_info->setLong(L_DEEP_CURRENT ,++spark_info->l_array[L_DEEP_CURRENT]);

        msleep(200);
    }
}

/*放电进程监听spark_info全局变量的开始结束信号*/
void SparkThread::sparkChange()
{
    if(spark_info->b_array[B_START]&&!isRunning()){
        start();
    }
    else if(!spark_info->b_array[B_START]&&isRunning()){
    }
}

SparkThread::~SparkThread()
{

}
