#include "plotter.h"
#include "geometricfigure.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QColorDialog>
#include <QColor>
#include <QString>
#include <QDebug>
#include <QMouseEvent>

Plotter::Plotter(QWidget *parent) : QWidget(parent){
   //plano e dimenções iniciais do painel de desenho.
    plano=XY;
    s=new Sculptor(10,10,10);
    dx=10;dy=10;dz=10;dim=0;drive=1;
}
void Plotter::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    int tam1=0,tam2=0;
    int ax,by;
    //propriedades da caneta
    pen.setColor(QColor(0,0,0));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);

    //propriedades do pincel
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    //dando a caneta ao pintor
    painter.setPen(pen);
    //dando o pincel ao pintor
    painter.setBrush(brush);
    //objeto que retorna um plano do escultor.
    m=s->readPlano(dim,plano);
    if(plano==XY){
        tam1=width()/dx;
        tam2=height()/dy;
        ax=tam1*dx;
        by=tam2*dy;
        altura = tam2;
        largura = tam1;
        //forma de desenhar a matriz que vai ser desenhada para o plano XY.
        for(int i =0; i<ax; i= i+tam1){
            for(int j =0; j<by; j = j+tam2){
                painter.drawRect(i,j,tam1,tam2);
            }
        }
        for(int i=0; i<dx;i++){
            for(int j=0; j<dy;j++){
                if(m[i][j].isOn){
                    brush.setColor(QColor(m[i][j].red,m[i][j].green,m[i][j].blue));
                    brush.setStyle(Qt::SolidPattern);
                    painter.setBrush(brush);
                    int xcenter =i*tam1;
                    int ycenter =j*tam2;
                    painter.drawEllipse(xcenter,ycenter,tam1,tam2);
                }
            }
        }
    }
    if(plano==ZX){
        tam1=width()/dx;
        tam2=height()/dz;
        ax=tam1*dx;
        by=tam2*dz;
        altura = tam2;
        largura = tam1;
        //forma de desenhar a matriz que vai ser desenhada para o plano ZX.
        for(int i =0; i<ax; i= i+tam1){
            for(int j =0; j<by; j = j+tam2){
                painter.drawRect(i,j,tam1,tam2);
            }
        }
        for(int i=0; i<dx;i++){
            for(int j=0; j<dz;j++){
                if(m[i][j].isOn){
                    brush.setColor(QColor(m[i][j].red,m[i][j].green,m[i][j].blue));
                    brush.setStyle(Qt::SolidPattern);
                    painter.setBrush(brush);
                    int xcenter =i*tam1;
                    int ycenter =j*tam2;
                    painter.drawEllipse(xcenter,ycenter,tam1,tam2);
                }
            }
        }
    }
    if(plano==YZ){
        tam1=width()/dz;
        tam2=height()/dy;
        ax=tam1*dz;
        by=tam2*dy;
        altura = tam2;
        largura = tam1;
        //forma de desenhar a matriz que vai ser desenhada para o plano YZ.
        for(int i =0; i<ax; i= i+tam1){
            for(int j =0; j<by; j = j+tam2){
                painter.drawRect(i,j,tam1,tam2);
            }
        }
        for(int i=0; i<m.size();i++){
            for(int j=0; j<m[0].size();j++){
                if(m[i][j].isOn){
                    brush.setColor(QColor(m[i][j].red,m[i][j].green,m[i][j].blue));
                    brush.setStyle(Qt::SolidPattern);
                    painter.setBrush(brush);
                    int xcenter =i*tam1;
                    int ycenter =j*tam2;
                    painter.drawEllipse(xcenter,ycenter,tam1,tam2);
                }
            }
        }
    }
}
void Plotter::mousePressEvent(QMouseEvent *event){
    //Metodo utilizado para desenhar com o butão do mouse ativado.
    int bx,by;
    bx=(event->x());
    by=(event->y());
    if(event->button() == Qt::LeftButton ){
        verif=true;
        if(((bx>=0)&&(bx<=width()))&&((by>=0)&&(by<=height()))){
        emit clickX(event->x());
        emit clickY(event->y());
        mx = (event->x())/largura;
        my = (event->y())/altura;
        if(plano == XY){
            x0=mx;
            y0=my;
            z0=dim;
        }
        else if(plano == YZ){
            z0=my;
            y0=mx;
            x0=dim;
        }
        else if(plano == ZX){
            x0=mx;
            z0=my;
            y0=dim;
        }
        Draw(drive);
       }
    }
}
void Plotter::mouseMoveEvent(QMouseEvent *event){
    //Metodo utilizado para desenhar com o butão do mouse ativado.
    int bx,by;
    bx=(event->x());
    by=(event->y());
    if(verif){
        emit moveX(event->x());
        emit moveY(event->y());
        mx = (event->x())/largura;
        my = (event->y())/altura;
        if(((bx>=0)&&(bx<=width()))&&((by>=0)&&(by<=height()))){
            if(plano == XY){
                x0=mx;
                y0=my;
                z0=dim;
            }
            else if(plano == YZ){
                z0=my;
                y0=mx;
                x0=dim;
            }
            else if(plano == ZX){
                x0=mx;
                z0=my;
                y0=dim;
            }
            Draw(drive);
        }
    }
}
void Plotter::mouseReleaseEvent(QMouseEvent *event){
    verif=false;
}
void Plotter::mudaCor(){
    //Mudança de cor utilizando uma caixa de dialogo extra, para as cores.
    QColor cor;
    QColorDialog d;
    d.exec();
    cor=d.selectedColor();
    pr=cor.red();
    pg=cor.green();
    pb=cor.blue();
    repaint();
}
void Plotter::SalvarDesenho(){
    //Salvar o desenho em arquivo OFF e VECT.
    string arqOFF="arqOFF";
    string arqVECT="arqVECT";
    s->writeVECT(arqVECT);
    s->writeOFF(arqOFF);
}
void Plotter::SetColorR(int r){
    pr=r;
    repaint();
}
void Plotter::SetColorG(int g){
    pg=g;
    repaint();
}
void Plotter::SetColorB(int b){
    pb=b;
    repaint();
}
void Plotter::SetX(int x){
    dx=x;
}
void Plotter::SetY(int y){
    dy=y;
}
void Plotter::SetZ(int z){
    dz=z;
}
void Plotter::CreatorSculptor(){
    //Utilizaddo para criar o escultor 3D.
    s->~Sculptor();
    s=new Sculptor(dx,dy,dz);
    repaint();
}
//Metodos para selecionar o plano.
void Plotter::PlanoXZ(){
    plano=ZX;
    repaint();
}
void Plotter::PlanoXY(){
    plano=XY;
    repaint();
}
void Plotter::PlanoYZ(){
    plano=YZ;
    repaint();
}
//Metodos para mover os planos.
void Plotter::MovePlanX(int dim_X){
    if(plano==YZ){
        dim=dx*(dim_X/100.0);
        repaint();
    }
}
void Plotter::MovePlanY(int dim_Y){
    if(plano==ZX){
        dim=dy*(dim_Y/100.0);
        repaint();
    }
}
void Plotter::MovePlanZ(int dim_Z){
    if(plano==XY){
        dim=dz*(dim_Z/100.0);
        repaint();
    }
}
//Metodo para ler um arquivo e desenha-lo.
void Plotter::NewDraw(string file){
    ifstream fin;
    string f;
    stringstream aux;
    fin.open(file);
    if(!fin.is_open()){
        cout << "arquivo nao foi aberto\n";
        exit(0);
    }
    while(fin.good()){
        getline(fin,f);
        aux.clear();
        aux.str(f);
        aux>>f;
        if(f.compare("dim")==0){
            aux>>dx>>dy>>dz;
            s=new Sculptor(dx,dy,dz);
        }
        else if(f.compare("putvoxel")==0){
            int x0,y0,z0;
            int r,g,b;
            float alpha;
            aux>>x0>>y0>>z0>>r>>g>>b>>alpha;
            fig.push_back(new putVoxel(x0,y0,z0,r,g,b,alpha));
        }
        else if(f.compare("putbox")==0){
            int x0,y0,z0,x1,y1,z1;
            int r,g,b;
            float alpha;
            aux>>x0>>y0>>z0>>x1>>y1>>z1>>r>>g>>b>>alpha;
            fig.push_back(new putBox(dx,dy,dz,x0,y0,z0,x1,y1,z1,r,g,b,alpha));
        }
        else if(f.compare("putsphere")==0){
            int x0,y0,z0,radius;
            int r,g,b;
            float alpha;
            aux>>x0>>y0>>z0>>radius>>r>>g>>b>>alpha;;
            fig.push_back(new putSphere(dx,dy,dz,x0,y0,z0,radius,r,g,b,alpha));
        }
        else if(f.compare("putellipsoid")==0){
            int x0,y0,z0,rx,ry,rz;
            int r,g,b;
            float alpha;
            aux>>x0>>y0>>z0>>rx>>ry>>rz>>r>>g>>b>>alpha;
            fig.push_back(new putEllipsoid(dx,dy,dz,x0,y0,z0,rx,ry,rz,r,g,b,alpha));
        }
        else if(f.compare("cutvoxel")==0){
            int x0,y0,z0;
            aux>>x0>>y0>>z0;
            fig.push_back(new cutVoxel(x0,y0,z0));
        }
        else if(f.compare("cutbox")==0){
            int x0,y0,z0,x1,y1,z1;
            aux>>x0>>y0>>z0>>x1>>y1>>z1;
            fig.push_back(new cutBox(dx,dy,dz,x0,y0,z0,x1,y1,z1));
        }
        else if(f.compare("cutsphere")==0){
            int x0,y0,z0,radius;
            aux>>x0>>y0>>z0>>radius;
            fig.push_back(new cutSphere(dx,dy,dz,x0,y0,z0,radius));
        }
        else if(f.compare("cutellipsoid")==0){
            int x0,y0,z0,rx,ry,rz;
            aux>>x0>>y0>>z0>>rx>>ry>>rz;
            fig.push_back(new cutEllipsoid(dx,dy,dz,x0,y0,z0,rx,ry,rz));
        }
    }
    for(int i=0; i<fig.size(); i++){
        fig[i]->draw(*s);
    }
    repaint();
}
//Limpar o desenho.
void Plotter::DeleteSculptor(){
    s->~Sculptor();
    fig.clear();
}
//Formas de determinar qual forma o usuario vai desenhar.
void Plotter::Voxel(){
    drive=1;
}
void Plotter::Box(){
    drive=2;
}
void Plotter::Sphere(){
    drive=3;
}
void Plotter::Ellipsoid(){
    drive=4;
}
void Plotter::c_Voxel(){
    drive=5;
}
void Plotter::c_Box(){
    drive=6;
}
void Plotter::c_Sphere(){
    drive=7;
}
void Plotter::c_Ellipsoid(){
    drive=8;
}
//Metedo para desenhar as formas que o usuario selecionar.
void Plotter::Draw(int ver){
    if(ver==1){
        if(plano==XY){
            d=new putVoxel(x0,y0,z0,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new putVoxel(x0,y0,z0,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new putVoxel(x0,y0,z0,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==2){
        if(plano==XY){
            d=new putBox(dx,dy,dz,x0,y0,z0,xf+x0,yf+y0,zf+z0,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new putBox(dx,dy,dz,x0,y0,z0,xf+x0,yf+y0,zf+z0,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new putBox(dx,dy,dz,x0,y0,z0,xf+x0,yf+y0,zf+z0,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==3){
        if(plano==XY){
            d=new putSphere(dx,dy,dz,x0,y0,z0,r_,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new putSphere(dx,dy,dz,x0,y0,z0,r_,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new putSphere(dx,dy,dz,x0,y0,z0,r_,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==4){
        if(plano==XY){
            d=new putEllipsoid(dx,dy,dz,x0,y0,z0,rx_,ry_,rz_,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new putEllipsoid(dx,dy,dz,x0,y0,z0,rx_,ry_,rz_,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new putEllipsoid(dx,dy,dz,x0,y0,z0,rx_,ry_,rz_,pr,pg,pb,0.8);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==5){
        if(plano==XY){
            d=new cutVoxel(x0,y0,z0);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new cutVoxel(x0,y0,z0);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new cutVoxel(x0,y0,z0);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==6){
        if(plano==XY){
            d=new cutBox(dx,dy,dz,x0,y0,z0,xf+x0,yf+y0,zf+z0);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new cutBox(dx,dy,dz,x0,y0,z0,xf+x0,yf+y0,zf+z0);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new cutBox(dx,dy,dz,x0,y0,z0,xf+x0,yf+y0,zf+z0);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==7){
        if(plano==XY){
            d=new cutSphere(dx,dy,dz,x0,y0,z0,r_);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new cutSphere(dx,dy,dz,x0,y0,z0,r_);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new cutSphere(dx,dy,dz,x0,y0,z0,r_);
            d->draw(*s);
            repaint();
        }
    }
    if(ver==8){
        if(plano==XY){
            d=new cutEllipsoid(dx,dy,dz,x0,y0,z0,rx_,ry_,rz_);
            d->draw(*s);
            repaint();
        }
        if(plano==ZX){
            d=new cutEllipsoid(dx,dy,dz,x0,y0,z0,rx_,ry_,rz_);
            d->draw(*s);
            repaint();
        }
        if(plano==YZ){
            d=new cutEllipsoid(dx,dy,dz,x0,y0,z0,rx_,ry_,rz_);
            d->draw(*s);
            repaint();
        }
    }
}
//Metodos para determinar as dimenções do desenho.
void Plotter::Box_X(int x){
    xf=dx*(x/100.0);
    repaint();
}
void Plotter::Box_Y(int y){
    yf=dy*(y/100.0);
}
void Plotter::Box_Z(int z){
    zf=dz*(z/100.0);
    repaint();
}
void Plotter::Sphere(int r){
    r_=dx*(r/100.0);
    repaint();
}
void Plotter::Ellipsoid_X(int rx){
    rx_=dx*(rx/100.0);
    repaint();
}
void Plotter::Ellipsoid_Y(int ry){
    ry_=dy*(ry/100.0);
    repaint();
}
void Plotter::Ellipsoid_Z(int rz){
    rz_=dz*(rz/100.0);
    repaint();
}
