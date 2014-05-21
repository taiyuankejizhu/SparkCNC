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

    QLinearGradient lg1(0, height()/2, 0, height());
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

    QString s;

    int m = 0;
    long tmp = 0;
    long g = 10000000;
    char ch = '0';
    bool dot = false;
    bool first = false;

    tmp = spark_info->l_array[index];

    if(tmp < 0)
        s.append('-');

    for(m = 0;m < 7;m++){
        if(m == 4){
            if(!first){
                s.append('0');
                s.append('.');
                first = true;
            }
            else
                s.append('.');
            dot = true;
        }
        tmp = spark_info->l_array[index] % g;
        g = g / 10;
        tmp = tmp / g;
        tmp = abs(tmp);
        ch = tmp & 0xFF;
        ch = ch + 48;

        if(ch != '0'){
            first =true;
        }

        if(first)
            s.append(ch);
    }

    value = s;
    update();
}

QString Qcombox::getValue()
{
    return value;
}
