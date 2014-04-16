#include "seconlevel_f6.h"
#include "ui_seconlevel_f6.h"

seconlevel_f6::seconlevel_f6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seconlevel_f6)
{
    ui->setupUi(this);

    connect(this ,SIGNAL(enter(int)),parent ,SLOT(funcbarUpdate(int)));
    connect(ui->pushButton_F8,SIGNAL(clicked()),this ,SLOT(F8()));

    setFocusPolicy(Qt::NoFocus);
}

void seconlevel_f6::F8()
{
    emit enter(28);
}

void seconlevel_f6::F0()
{

}

seconlevel_f6::~seconlevel_f6()
{
    delete ui;
}
