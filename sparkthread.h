#ifndef SPARKTHREAD_H
#define SPARKTHREAD_H

#include <QThread>

class SparkThread : public QThread
{
    Q_OBJECT
public:
    explicit SparkThread(QObject *parent = 0);
    void run();
    virtual ~SparkThread();

signals:

public slots:

};

#endif // SPARKTHREAD_H
