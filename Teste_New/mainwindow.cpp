#include "mainwindow.h"
#include "dialogopen.h"
#include "dialognew.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAbrirArquivo,SIGNAL(triggered(bool)),this,SLOT(lear()));
    connect(ui->actionNovo,SIGNAL(triggered(bool)),this,SLOT(NewDimensions()));
    connect(ui->actionCores,SIGNAL(triggered(bool)),ui->widget,SLOT(mudaCor()));
    connect(ui->actionSalvar,SIGNAL(triggered(bool)),ui->widget,SLOT(SalvarDesenho()));
    connect(ui->actionPlanXY,SIGNAL(triggered(bool)),ui->widget,SLOT(PlanoXY()));
    connect(ui->actionPlanXZ,SIGNAL(triggered(bool)),ui->widget,SLOT(PlanoXZ()));
    connect(ui->actionPlanYZ,SIGNAL(triggered(bool)),ui->widget,SLOT(PlanoYZ()));
    connect(ui->pushButton_Save,SIGNAL(clicked(bool)),this,SLOT(RouteX()));
    connect(ui->pushButton_Save,SIGNAL(clicked(bool)),this,SLOT(RouteY()));
    connect(ui->pushButton_Save,SIGNAL(clicked(bool)),this,SLOT(RouteZ()));
    connect(ui->pushButton_Creator,SIGNAL(clicked(bool)),ui->widget,SLOT(CreatorSculptor()));
    connect(ui->horizontalSlider_Red,SIGNAL(valueChanged(int)),ui->widget,SLOT(SetColorR(int)));
    connect(ui->horizontalSlider_Green,SIGNAL(valueChanged(int)),ui->widget,SLOT(SetColorG(int)));
    connect(ui->horizontalSlider_Blue,SIGNAL(valueChanged(int)),ui->widget,SLOT(SetColorB(int)));
    connect(ui->horizontalSlider_PlanX,SIGNAL(valueChanged(int)),ui->widget,SLOT(MovePlanX(int)));
    connect(ui->horizontalSlider_PlanY,SIGNAL(valueChanged(int)),ui->widget,SLOT(MovePlanY(int)));
    connect(ui->horizontalSlider_PlanZ,SIGNAL(valueChanged(int)),ui->widget,SLOT(MovePlanZ(int)));
    connect(ui->horizontalSlider_XBox,SIGNAL(valueChanged(int)),ui->widget,SLOT(Box_X(int)));
    connect(ui->horizontalSlider_YBox,SIGNAL(valueChanged(int)),ui->widget,SLOT(Box_Y(int)));
    connect(ui->horizontalSlider_ZBox,SIGNAL(valueChanged(int)),ui->widget,SLOT(Box_Z(int)));
    connect(ui->horizontalSlider_R,SIGNAL(valueChanged(int)),ui->widget,SLOT(Sphere(int)));
    connect(ui->horizontalSlider_RxEllipsoid,SIGNAL(valueChanged(int)),ui->widget,SLOT(Ellipsoid_X(int)));
    connect(ui->horizontalSlider_RyEllipsoid,SIGNAL(valueChanged(int)),ui->widget,SLOT(Ellipsoid_Y(int)));
    connect(ui->horizontalSlider_RzEllipsoid,SIGNAL(valueChanged(int)),ui->widget,SLOT(Ellipsoid_Z(int)));
    connect(ui->actionVoxel,SIGNAL(triggered(bool)),ui->widget,SLOT(Voxel()));
    connect(ui->actionCaixa,SIGNAL(triggered(bool)),ui->widget,SLOT(Box()));
    connect(ui->actionEsfera,SIGNAL(triggered(bool)),ui->widget,SLOT(Sphere()));
    connect(ui->actionElipsoide,SIGNAL(triggered(bool)),ui->widget,SLOT(Ellipsoid()));
    connect(ui->actionVoxelCorte,SIGNAL(triggered(bool)),ui->widget,SLOT(c_Voxel()));
    connect(ui->actionCaixaCorte,SIGNAL(triggered(bool)),ui->widget,SLOT(c_Box()));
    connect(ui->actionEsferaCorte,SIGNAL(triggered(bool)),ui->widget,SLOT(c_Sphere()));
    connect(ui->actionelipsoideCorte,SIGNAL(triggered(bool)),ui->widget,SLOT(c_Ellipsoid()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::RouteX(){
    int x;
    bool ok;
    QString sx;
    sx=ui->plainTextEdit->toPlainText();
    x=sx.toInt(&ok,10);
    ui->widget->SetX(x);
}
void MainWindow::RouteY(){
    int y;
    bool ok;
    QString sy;
    sy=ui->plainTextEdit_2->toPlainText();
    y=sy.toInt(&ok,10);
    ui->widget->SetY(y);
}
void MainWindow::RouteZ(){
    int z;
    bool ok;
    QString sz;
    sz=ui->plainTextEdit_3->toPlainText();
    z=sz.toInt(&ok,10);
    ui->widget->SetZ(z);
}
void MainWindow::lear(){
    QString aux;
    string aux2;
    DialogOpen lears;
    if(lears.exec()==QDialog::Accepted){
        aux=lears.learFile();
        aux2=aux.toStdString();
        ui->widget->DeleteSculptor();
        ui->widget->NewDraw(aux2);
    }
}
void MainWindow::NewDimensions(){
    DialogNew leds;
    int cx,cy,cz;
    bool ok1,ok2,ok3;
    QString ax,ay,az;
    if(leds.exec()==QDialog::Accepted){
        ax=leds.lear_Dimension_X();
        ay=leds.lear_Dimension_Y();
        az=leds.lear_Dimension_Z();
        cx=ax.toInt(&ok1,10);
        cy=ay.toInt(&ok2,10);
        cz=az.toInt(&ok3,10);
        ui->widget->SetX(cx);
        ui->widget->SetY(cy);
        ui->widget->SetZ(cz);
        ui->widget->CreatorSculptor();
    }
}
