#ifndef SPARKINFO_H
#define SPARKINFO_H

#include <QObject>

#define B_SLOT 0            /*布尔数组的槽标记*/
#define UINT_SLOT 1         /*无符号整型数组的槽标记*/
#define L_SLOT 2            /*长整型数组的槽标记*/

#define B_LENGTH 15         /*布尔数组的长度*/
#define UINT_LENGTH 10      /*无符号整型数组的长度*/
#define L_LENGTH 20          /*长整型数组的长度*/

#define B_PUMP 0            /*冷却油泵的开关索引*/
#define B_POWER 1           /*副电源的开关索引*/
#define B_LOCK 2            /*机床锁定的开关索引*/
#define B_REVERSE 3         /*反加工的开关索引*/
#define B_START 4           /*放电加工的开关索引*/
#define B_TIME 5            /*当前时间的开关索引*/
#define B_BOTTOM 6          /*修底的开关索引*/
#define B_FIRE 7            /*火警的开关索引*/
#define B_OIL 8             /*油位报警的开关索引*/
#define B_DEEPHOLE 9        /*深孔报警的开关索引*/
#define B_XYLOCK 10         /*XY轴锁定的开关索引*/
#define B_SLEEP 11          /*屏幕睡眠的开关索引*/
#define B_SCREEN 12         /*屏幕状态的索引*/
#define B_SHUTDOWN 13       /*关机的开关索引*/
#define B_SOUND 14          /*按键声音的开关索引*/

#define UINT_VOLTAGE 0      /*放电电压值的索引*/
#define UINT_CURRENT 1      /*放电电流值的索引*/
#define UINT_SPEED 2        /*加工速度值的索引*/
#define UINT_JUMP_H 3       /*跳高值的索引*/
#define UINT_JUMP_T 4       /*跳高次数的索引*/
#define UINT_TAB_INDEX 5    /*当前表的索引*/
#define UINT_COOR_INDEX 6   /*当前坐标的索引*/
#define UINT_CURRENT_ROM 7  /*当前行的索引*/
#define UINT_START_ROW 8    /*开始行的索引*/
#define UINT_END_ROW 9      /*结束行的索引*/

#define L_DEEP_CURRENT 0    /*当前深度值的索引*/
#define L_DEEP_TARGET 1     /*目标深度值的索引*/
#define L_X_CURRENT 2       /*当前X轴位置的索引*/
#define L_Y_CURRENT 3       /*当前Y轴位置的索引*/
#define L_Z_CURRENT 4       /*当前Z轴位置的索引*/
#define L_X_OFFSET 5        /*当前X轴辅助位置的索引*/
#define L_Y_OFFSET 6        /*当前Y轴辅助位置的索引*/
#define L_Z_OFFSET 7        /*当前Z轴辅助位置的索引*/
#define L_X_ABSOLUTE 8      /*X轴绝对位置的索引*/
#define L_Y_ABSOLUTE 9      /*Y轴绝对位置的索引*/
#define L_Z_ABSOLUTE 10     /*Z轴绝对位置的索引*/
#define L_X_REMAIN 11       /*X轴剩余位置的索引*/
#define L_Y_REMAIN 12       /*Y轴剩余位置的索引*/
#define L_Z_REMAIN 13       /*Z轴剩余位置的索引*/
#define L_X_COUNTER 14      /*X轴光栅计数值的索引*/
#define L_Y_COUNTER 15      /*Y轴光栅计数值的索引*/
#define L_Z_COUNTER 16      /*Z轴光栅计数值的索引*/

struct Table
{
    int           Shendu[10];   /*深度*/
    unsigned int  Dianliu[10];  /*电流*/
    unsigned int  Maikuan[10];  /*脉宽*/
    unsigned int  Xiuzhi[10];   /*休止*/
    unsigned char Jianxi[10];   /*间隙*/
    unsigned char Sudu[10];     /*速度*/
    unsigned char Shenggao[10]; /*升高*/
    unsigned char Gongshi[10];  /*工时*/
    unsigned char Mianji[10];   /*面积*/
    unsigned char Jixin[10];    /*极性*/
    unsigned char Gaoya[10];    /*高压*/
    unsigned char Index[10];    /*索引*/
};

union TwoBytes
{
    char bytes[sizeof(unsigned short)];
    unsigned short ushort;
};

union FourBytes
{
    char bytes[sizeof(unsigned int)];
    unsigned int uint;
};

union SixBytes
{
    char bytes[3*sizeof(unsigned short)];
    unsigned short ushorts[3];
};

union EightBytes
{
    char bytes[sizeof(long)];
    long longs;
};

const Table table_init = {
    {1,5,10,15,20,30,40,50,55,60},
    {0,35*2,6,0,4,0,0,0,0,0},
    {1,999,200,0,20,0,0,0,0,},
    {3,999,100,0,30,0,0,0,0,},
    {30,120,55,0,50,0,0,0,0,},
    {1,8,3,0,5,0,0,0,0,},
    {0,99,6,0,0,0,0,0,0,0},
    {1,99,5,0,99,0,0,0,0,0},
    {1,99,1,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,3,1,0,2,0,0,0,0,0},
    {1,2,3,4,5,6,7,8,9,10},
};

const bool bool_init[] = {
        false ,false ,false ,false ,false ,
        true ,false ,false ,false ,false ,
        false ,false ,false ,false ,false ,
};

const unsigned int uint_init[] = {
        220, 0, 10, 0, 5, 0, 0, 0, 0, 0,
};

const long long_init[] = {
        0, 1, -7777500, -7777500, -7777500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

class SparkInfo : public QObject
{
    Q_OBJECT
public:
    explicit SparkInfo(QObject *parent = 0);
    void tableClear();
    void tableAuto(long ,unsigned int ,unsigned int ,unsigned int);
    bool b_array[B_LENGTH];
    unsigned int uint_array[UINT_LENGTH];
    long l_array[L_LENGTH];
    Table table;

private:
    void tableInit();

signals:
    /*放电开关信号*/
    void startChange();
    void boolChange();
    void longChange();
    void xyzChange(int);
    void uintChange();
    void tableChange();
    void tableIndexChange();
    void tableRowChange();

public slots:
    void setBool(unsigned int ,bool);
    void reverseBool(unsigned int);
    void setLong(unsigned int ,long);
    void setUInt(unsigned int , unsigned int);
    void updateTable();
};

extern SparkInfo *spark_info;

#endif // SPARKINFO_H
