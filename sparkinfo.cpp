#include "sparkinfo.h"
#include "qdebug.h"

SparkInfo::SparkInfo(QObject *parent) :
    QObject(parent)
{
    memcpy(b_array , bool_init ,sizeof b_array);
    memcpy(uint_array , uint_init ,sizeof uint_array);
    memcpy(l_array , long_init ,sizeof l_array);
    tableInit();

    /*当前表的索引改变时，更新表的数据*/
    connect(this ,SIGNAL(tableIndexChange()) ,this ,SLOT(updateTable()));
}

void SparkInfo::tableInit()
{
    int i = 0;
    /*默认的数据表*/
    if(uint_array[UINT_TAB_INDEX] == 0){
        for(; i < 10; i++){
            table.Shendu[i] = table_init.Shendu[i];
            table.Dianliu[i] = table_init.Dianliu[i];
            table.Maikuan[i] = table_init.Maikuan[i];
            table.Xiuzhi[i] = table_init.Xiuzhi[i];
            table.Jianxi[i] = table_init.Jianxi[i];
            table.Sudu[i] = table_init.Sudu[i];
            table.Shenggao[i] = table_init.Shenggao[i];
            table.Gongshi[i] = table_init.Gongshi[i];
            table.Mianji[i] = table_init.Mianji[i];
            table.Jixin[i] = table_init.Jixin[i];
            table.Gaoya[i] = table_init.Gaoya[i];
            table.Index[i] = table_init.Index[i];
        }
    }
    else
        updateTable();
}

/*清空数据表数据*/
void SparkInfo::tableClear()
{
    int i = 0;
    for(; i < 10; i++){
        table.Shendu[i] = 0;
        table.Dianliu[i] = 0;
        table.Maikuan[i] = 0;
        table.Xiuzhi[i] = 0;
        table.Jianxi[i] = 0;
        table.Sudu[i] = 0;
        table.Shenggao[i] = 0;
        table.Gongshi[i] = 0;
        table.Mianji[i] = 0;
        table.Jixin[i] = 0;
        table.Gaoya[i] = 0;
        table.Index[i] = 0 ;
    }
}

void SparkInfo::updateTable()
{
    emit tableChange();
}

void SparkInfo::reverseBool(unsigned int i)
{
    if(i < B_LENGTH){
        if(b_array[i])
            b_array[i] = false;
        else
            b_array[i] = true;
        emit boolChange();
    }
}

void SparkInfo::setLong(unsigned int i,long l)
{
    if(i < L_LENGTH){
        l_array[i] = l;
        emit longChange();
    }
}

void SparkInfo::setUInt(unsigned int i, unsigned int u)
{
    unsigned int tmp;

    if(i < UINT_LENGTH){
        uint_array[i] = u;
        if(i == UINT_TAB_INDEX){
            uint_array[UINT_CURRENT_ROM] = 0;
            uint_array[UINT_START_ROW] = 0;
            uint_array[UINT_END_ROW] = 0;
            emit tableIndexChange();
            emit tableRowChange();
        }
        /*保证当前行号在开始行和结束行之间*/
        else if(i==UINT_CURRENT_ROM){
            if(uint_array[UINT_CURRENT_ROM] < uint_array[UINT_START_ROW]){
                uint_array[UINT_CURRENT_ROM] = uint_array[UINT_START_ROW];
            }
            else if(uint_array[UINT_CURRENT_ROM] > uint_array[UINT_END_ROW]){
                uint_array[UINT_CURRENT_ROM] = uint_array[UINT_END_ROW];
            }
            emit tableRowChange();
        }
        /*保证开始行号小于结束行号*/
        else if(i == UINT_START_ROW||i == UINT_END_ROW){
            if(uint_array[UINT_START_ROW] > uint_array[UINT_END_ROW]){
                tmp = uint_array[UINT_START_ROW];
                uint_array[UINT_START_ROW] = uint_array[UINT_END_ROW];
                uint_array[UINT_END_ROW] = tmp;
            }
            emit tableRowChange();
        }
        else
            emit uintChange();
    }
}
