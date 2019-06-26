#ifndef PLOTTERCOLOR_H
#define PLOTTERCOLOR_H

#include <QWidget>

class PlotterColor : public QWidget
{
    Q_OBJECT
protected:
    int r,g,b;
public:
    explicit PlotterColor(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void ColorR(int r_);
    void ColorG(int g_);
    void ColorB(int b_);
};

#endif // PLOTTERCOLOR_H
