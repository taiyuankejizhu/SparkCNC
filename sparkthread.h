#ifndef SPARKTHREAD_H
#define SPARKTHREAD_H

#include <QThread>

#define SEARCH 0        /*放电开始后首先下降到最深位置，并判断当电行*/
#define SPARKING 1      /*放电头与工件接触后放电一段时间，根据放电行中的工时参数*/
#define EJECT_UP 2      /*根据放电行参数中的排渣参数放电时间结束后上升一定高度*/
#define EJECT_DOWN 3    /*上升到位后再下降到与工件接触*/
#define JUMP_UP 4       /*根据是否打开跳高开关以及跳高次数是否满足上升一定高度*/
#define JUMP_DOWN 5     /*上升到位后下降到与工件接触*/
#define BOTTOM 6        /*根据是否打开修底开关进行修底工作*/
#define RETURN 7        /*放电加工结束后回到开始时的位置*/


class SparkThread : public QThread
{
    Q_OBJECT
public:
    explicit SparkThread(QObject *parent = 0);

    /*放电开始之前的坐标位置，放电结束后回到这个位置*/
    long x_start;
    long y_start;
    long z_start;

    char state;
    void run();
    virtual ~SparkThread();

signals:

public slots:
    void sparkChange();

};

#endif // SPARKTHREAD_H
