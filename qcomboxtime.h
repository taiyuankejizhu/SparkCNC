#ifndef QCOMBOXTIME_H
#define QCOMBOXTIME_H

#include "qcombox.h"
#include <QWidget>
#include <QTimer>
#include <QTime>

class QcomboxTime :public Qcombox
{
    Q_OBJECT
public:
    explicit QcomboxTime(QWidget *parent = 0 ,QString l = "",bool b = false);

private:
    void initTime();
    void timeToString();
    bool flag;
    QTimer *timer ;
    QTime time ;
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

signals:

public slots:
    void valueUpdate();
    void updateTimer();
};

#endif // QCOMBOXTIME_H
