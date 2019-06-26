#include "dialogopen.h"
#include "ui_dialogopen.h"
//Caixa de dialogo para informa o diretorio do arquivo para ler.
DialogOpen::DialogOpen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOpen)
{
    ui->setupUi(this);
}
DialogOpen::~DialogOpen()
{
    delete ui;
}
QString DialogOpen::learFile()
{
    return ui->lineEdit->text();
}
