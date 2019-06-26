#include "plottercolor.h"
#include <QBrush>
#include <QPen>
#include <QPainter>

//Classe feita para selecionar as cores para desenhar.
PlotterColor::PlotterColor(QWidget *parent) : QWidget(parent){
    r=255;g=255;b=255;

}
void PlotterColor::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    //propriedades da caneta
    pen.setColor(QColor(0,0,0));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);

    //propriedades do pincel
    brush.setColor(QColor(r,g,b));
    brush.setStyle(Qt::SolidPattern);

    //dando a caneta ao pintor
    painter.setPen(pen);
    //dando o pincel ao pintor
    painter.setBrush(brush);
    //desenhando um retangulo
    painter.drawRect(0,0,width(),height());

    pen.setColor(QColor(0,255,0));
    pen.setWidth(1);

    painter.setPen(pen);
}
void PlotterColor::ColorR(int r_){
    r=r_;
    repaint();
}
void PlotterColor::ColorG(int g_){
    g=g_;
    repaint();
}
void PlotterColor::ColorB(int b_){
    b=b_;
    repaint();
}
