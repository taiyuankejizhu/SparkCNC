#include "sparkthread.h"
#include "qdebug.h"
#include "sparkinfo.h"

SparkThread::SparkThread(QObject *parent) :
    QThread(parent)
{
}

void SparkThread::run()
{
    long tmp = 0;
    while(1){
        tmp = spark_info->l_array[L_DEEP_CURRENT];
        tmp += 1;
        spark_info->setLong(0 ,tmp);
        if(spark_info->l_array[L_DEEP_CURRENT] > spark_info->table.Shendu[spark_info->uint_array[UINT_CURRENT_ROM]]){
            if(spark_info->uint_array[UINT_CURRENT_ROM]<spark_info->uint_array[UINT_END_ROW])
                spark_info->setUInt(UINT_CURRENT_ROM ,++spark_info->uint_array[UINT_CURRENT_ROM]);
            else
                spark_info->setUInt(UINT_CURRENT_ROM ,spark_info->uint_array[UINT_END_ROW]);
        }
        msleep(200);
    }
}

SparkThread::~SparkThread()
{

}
