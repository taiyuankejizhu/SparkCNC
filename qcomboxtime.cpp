#include "qcomboxtime.h"
#include "sparkinfo.h"

QcomboxTime::QcomboxTime(QWidget *parent,QString l,bool b) :
    Qcombox(parent , l )
{
    flag = b;

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
        hours = time.hour();
        minutes = time.minute();
        seconds = time.second();
    }
    else{
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
}

void QcomboxTime::valueUpdate()
{
    if(flag){
        time = QTime::currentTime();
        hours = time.hour();
        minutes = time.minute();
        seconds = time.second();
    }
    else{
        if(++seconds > 60){
            seconds = 0;
            if(++minutes > 60){
                minutes = 0;
                hours++;
            }
        }
    }
    timeToString();
    update();
}

void QcomboxTime::timeToString()
{
    QString str,tmp;
    tmp.setNum(hours);
    if(hours < 10){
        if(flag)
            str = '0';
    }
    else if(hours < 100&&hours >= 10){
    }
    str += tmp;
    str += ':';

    tmp.setNum(minutes);
    if(minutes < 10){
        str += '0';
    }
    str += tmp;
    str += ':';

    tmp.setNum(seconds);
    if(seconds < 10){
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
