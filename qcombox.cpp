#include "qcombox.h"
#include "sparkinfo.h"
#include <QPainter>
#include <QMouseEvent>
#include <QFontMetricsF>
#include <QApplication>

Qcombox::Qcombox(QWidget *parent ,QString l ,unsigned int i):
    QWidget(parent)
{
    pad   = 2 ;
    value = "" ;
    label = l;
    index = i;
    f_color = QColor(64,64,64);
    b_color = QColor(255,255,255);
    l_color = QColor(255,255,255);
    r_color = QColor(0,0,0);
}

void Qcombox::drawBackground(QPainter *painter)
{
    painter->save();

    painter->setPen(r_color);
    painter->setBrush(r_color);
    painter->fillRect(0,0,width(),height(),r_color);

    painter->setPen(b_color);
    painter->setBrush(b_color);
    painter->fillRect(pad,pad,width()-2*pad,height()-2*pad,b_color);

    painter->restore();
}

void Qcombox::drawWidget(QPainter *painter)
{
    painter->save();

    painter->setPen(f_color);
    painter->setBrush(f_color);

    painter->fillRect(pad,pad,width()-2*pad,(height()-2*pad)/2,f_color);

    /*Paint the label name*/
    painter->translate(width()/2, height()/4);
    painter->setPen(l_color);
    painter->setBrush(l_color);

    QFont font = qApp->font();
    font.setPointSize(12);
    painter->setFont(font);

    QFontMetricsF fm(font);
    double w = fm.size(Qt::TextSingleLine,label).width();
    double h = fm.size(Qt::TextSingleLine,label).height();

    painter->drawText(-w/2 ,h/2-pad ,label);

    /*Paint the label value*/
    //painter->translate(width()/2, (height()*3)/4);

    painter->setPen(r_color);
    painter->setBrush(r_color);

    w = fm.size(Qt::TextSingleLine,value).width();
    h = fm.size(Qt::TextSingleLine,value).height();
    painter->drawText(-w/2 ,h/2 + height()/2-pad ,value);

    painter->restore();
}

void Qcombox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    drawBackground(&painter);
    drawWidget(&painter);
}

void Qcombox::mousePressEvent(QMouseEvent *ev)
{
        ev->accept();
        update();
}

void Qcombox::mouseReleaseEvent(QMouseEvent *ev)
{
        ev->accept();
        update();
}

void Qcombox::updateValue()
{
    long tmp = 0;
    tmp = spark_info->l_array[index];
    value = QString::number(tmp);
    update();
}

QString Qcombox::getValue()
{
    return value;
}
