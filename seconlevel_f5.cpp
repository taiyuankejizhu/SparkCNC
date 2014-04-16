#include "seconlevel_f5.h"
#include "sparkinfo.h"
#include "ui_seconlevel_f5.h"

seconlevel_f5::seconlevel_f5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seconlevel_f5)
{
    ui->setupUi(this);

    connect(ui->pushButton_F6,SIGNAL(clicked()),this ,SLOT(F6()));
    ui->pushButton_F6->setCheckable(true);

    connect(this ,SIGNAL(enter(int)),parent ,SLOT(funcbarUpdate(int)));
    connect(ui->pushButton_F8,SIGNAL(clicked()),this ,SLOT(F8()));

    setFocusPolicy(Qt::NoFocus);
}

void seconlevel_f5::F6()
{
    spark_info->reverseBool(B_LOCK);
}

void seconlevel_f5::F8()
{
    emit enter(28);
}

void seconlevel_f5::F0()
{

}

seconlevel_f5::~seconlevel_f5()
{
    delete ui;
}
