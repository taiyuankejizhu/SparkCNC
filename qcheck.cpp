#include "qcheck.h"
#include "sparkinfo.h"
#include <QPainter>
#include <QMouseEvent>
#include <QFontMetricsF>
#include <QApplication>

Qcheck::Qcheck(QWidget *parent) :
    QWidget(parent)
{
    pad   = 2 ;
    check = false ;
    label = "";
    index = 0;
    f_color = QColor(255,0,0);
    b_color = QColor(255,255,255);
    t_color = QColor(0,255,0);
    l_color = QColor(0,0,0);
    r_color = QColor(0,0,0);
}

Qcheck::Qcheck(QWidget *parent ,QString l,unsigned int i):
    QWidget(parent)
{
    pad   = 2 ;
    check = false ;
    label = l;
    index = i;
    f_color = QColor(255,0,0);
    b_color = QColor(255,255,255);
    t_color = QColor(0,255,0);
    l_color = QColor(0,0,0);
    r_color = QColor(0,0,0);
}

void Qcheck::drawBackground(QPainter *painter)
{
    painter->save();

    QLinearGradient lg1(0, 0, 0, height());
    lg1.setColorAt(0, QColor(255, 255, 255));
    lg1.setColorAt(1, QColor(0, 0, 0));

    painter->setPen(r_color);
    painter->setBrush(r_color);
    painter->fillRect(0,0,width(),height(),lg1);

    painter->setPen(b_color);
    painter->setBrush(b_color);
    painter->fillRect(pad,pad,width()-2*pad,height()-2*pad,b_color);

    painter->restore();
}

void Qcheck::drawWidget(QPainter *painter)
{
    painter->save();

    painter->setPen(f_color);
    painter->setBrush(f_color);
    if(check)
        painter->fillRect(pad+(width()-2*pad)/2+1,pad,(width()-2*pad)/2,height()-2*pad,t_color);
        //painter->fillRect(pad,pad,(width()-2*pad)/2,height()-2*pad,f_color);
    else
        painter->fillRect(pad+(width()-2*pad)/2+1,pad,(width()-2*pad)/2,height()-2*pad,f_color);

    painter->setPen(l_color);
    painter->setBrush(l_color);

    QFont font = qApp->font();
    font.setPointSize(12);
    painter->setFont(font);

    QFontMetricsF fm(font);
    double w = fm.size(Qt::TextSingleLine,label).width();
    double h = fm.size(Qt::TextSingleLine,label).height();

    painter->translate(width()/4, height()/2);
    painter->drawText(-w/2 ,h/2-pad ,label);

    if(check)
    {
        w = fm.size(Qt::TextSingleLine,tr("开")).width();
        h = fm.size(Qt::TextSingleLine,tr("开")).height();
        painter->drawText(width()/2-w/2 ,h/2-pad ,tr("开"));
    }
    else
    {
        w = fm.size(Qt::TextSingleLine,tr("关")).width();
        h = fm.size(Qt::TextSingleLine,tr("关")).height();
        painter->drawText(width()/2-w/2 ,h/2-pad ,tr("关"));
    }

    painter->restore();
}

void Qcheck::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    drawBackground(&painter);
    drawWidget(&painter);
}

void Qcheck::mousePressEvent(QMouseEvent *ev)
{
        ev->accept();
        update();
}

void Qcheck::mouseReleaseEvent(QMouseEvent *ev)
{
        ev->accept();
        update();
}

void Qcheck::updateCheck()
{
    check = spark_info->b_array[index];
    update();
}
