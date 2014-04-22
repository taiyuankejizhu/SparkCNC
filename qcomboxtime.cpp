#include "qcomboxtime.h"

/*根据Qt编译器的版本判断目标机的类型*/

#if(QT_VERSION == 0x040704)
    #define X86
#else
    #define ARM
#endif

QcomboxTime::QcomboxTime(QWidget *parent,QString l,bool b) :
    Qcombox(parent , l )
{
    flag = b;

    memset(current.bytes , 0 ,sizeof current);
    memset(target.bytes , 0 ,sizeof target);

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer ,SIGNAL(timeout()) ,this ,SLOT(valueUpdate()));

    initTime();
    timeToString();
}

void QcomboxTime::initTime()
{
    if(flag){
        time = QTime::currentTime();
        current.uints[HOURS] = time.hour();
        current.uints[MINUTES] = time.minute();
        current.uints[SECONDS] = time.second();
    }
    else{
        current.uints[HOURS] = 0;
        current.uints[MINUTES] = 0;
        current.uints[SECONDS] = 0;
#ifdef ARM
        FM25V02_READ(CURRENT_TIME , current.bytes ,sizeof current);
        FM25V02_READ(TARGET_TIME , target.bytes ,sizeof target);
#endif
    }
}

void QcomboxTime::valueUpdate()
{
    if(flag){
        time = QTime::currentTime();
        current.uints[HOURS] = time.hour();
        current.uints[MINUTES] = time.minute();
        current.uints[SECONDS] = time.second();
    }
    else{
        if(++current.uints[SECONDS] > 60){
            current.uints[SECONDS] = 0;
            if(++current.uints[MINUTES] > 60){
                current.uints[MINUTES] = 0;
                current.uints[HOURS]++;
                /*放电时间溢出*/
                if(current.uints[HOURS] > target.uints[HOURS]){
                    spark_info->reverseBool(B_START);
                }
            }
#ifdef ARM
        FM25V02_WRITE(CURRENT_TIME , current.bytes, sizeof current);
#endif
        }
    }
    timeToString();
    update();
}

void QcomboxTime::timeToString()
{
    QString str,tmp;
    tmp.setNum(current.uints[HOURS]);
    if(current.uints[HOURS] < 10){
        if(flag)
            str = '0';
    }
    else if(current.uints[HOURS] < 100&&current.uints[HOURS] >= 10){
    }
    str += tmp;
    str += ':';

    tmp.setNum(current.uints[MINUTES]);
    if(current.uints[MINUTES] < 10){
        str += '0';
    }
    str += tmp;
    str += ':';

    tmp.setNum(current.uints[SECONDS]);
    if(current.uints[SECONDS] < 10){
        str += '0';
    }
    str += tmp;
    value = str;
}

void QcomboxTime::updateTimer()
{
    if(flag){
        if(spark_info->b_array[B_TIME])
            timer->start();
        else
            timer->stop();
    }
    else{
        if(spark_info->b_array[B_START])
            timer->start();
        else
            timer->stop();
    }
}
