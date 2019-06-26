#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include "vector"
#include "geometricfigure.h"
#include "sculptor.h"

class Plotter : public QWidget
{
    Q_OBJECT

public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    Sculptor *s;
    vector<GeometricFigure*>fig;
    GeometricFigure *d;

private:
    vector<vector<Voxel>> m;
    int dx, dy, dz;//dimensoes do escultor
    int pr,pg,pb;
    int dim, plano;
    int x0,y0,z0;
    int xf,yf,zf,r_;
    int rx_,ry_,rz_;
    int altura,largura,mx,my,drive;
    bool verif;
signals:
    void moveX(int);
    void moveY(int);
    void clickX(int);
    void clickY(int);

public slots:
    void mudaCor();
    void SalvarDesenho();
    void SetColorR(int r);
    void SetColorG(int g);
    void SetColorB(int b);
    void SetX(int x);
    void SetY(int y);
    void SetZ(int z);
    void CreatorSculptor();
    void PlanoXZ();
    void PlanoXY();
    void PlanoYZ();
    void MovePlanX(int dim_X);
    void MovePlanY(int dim_Y);
    void MovePlanZ(int dim_Z);
    void NewDraw(string file);
    void DeleteSculptor();
    void Voxel();
    void Box();
    void Sphere();
    void Ellipsoid();
    void c_Voxel();
    void c_Box();
    void c_Sphere();
    void c_Ellipsoid();
    void Draw(int ver);
    void Box_X(int x);
    void Box_Y(int y);
    void Box_Z(int z);
    void Sphere(int r);
    void Ellipsoid_X(int rx);
    void Ellipsoid_Y(int ry);
    void Ellipsoid_Z(int rz);
};

#endif // PLOTTER_H
