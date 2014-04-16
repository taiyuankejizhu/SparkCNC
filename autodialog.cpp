#include "autodialog.h"
#include "ui_autodialog.h"
#include "qdebug.h"

AutoDialog::AutoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutoDialog)
{
    ui->setupUi(this);
    this->setGeometry(0 ,320 ,670 ,220);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->buttonBox->button(ui->buttonBox->Ok)->setText(tr("确定(O)"));
    ui->buttonBox->button(ui->buttonBox->Cancel)->setText(tr("取消(C)"));
}

void AutoDialog::keyPressEvent(QKeyEvent *k)
{
    k->accept();
    switch(k->key())
    {
    case Qt::Key_Down:
        focusNextChild();
        break;
    case Qt::Key_Up:
        focusPreviousChild();
        break;
    case Qt::Key_F2:
        finished(1);
        break;
    case Qt::Key_F1:
    case Qt::Key_F3:
    case Qt::Key_F4:
    case Qt::Key_F5:
    case Qt::Key_F6:
    case Qt::Key_F7:
    case Qt::Key_F8:
        finished(0);
        break;
    default:
        break;
    }
}

AutoDialog::~AutoDialog()
{
    delete ui;
}
