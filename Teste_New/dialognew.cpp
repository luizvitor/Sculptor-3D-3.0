#include "dialognew.h"
#include "ui_dialognew.h"
//Caixa de dialogo para informa as dimenções do escultor 3D.
DialogNew::DialogNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNew)
{
    ui->setupUi(this);
}

DialogNew::~DialogNew()
{
    delete ui;
}

QString DialogNew::lear_Dimension_Y()
{
    return ui->lineEdit_Y->text();
}
QString DialogNew::lear_Dimension_X()
{
    return ui->lineEdit_X->text();
}
QString DialogNew::lear_Dimension_Z()
{
    return ui->lineEdit_Z->text();
}
