#ifndef PUTBOX_H
#define PUTBOX_H

#include "geometricfigure.h"
#include "sculptor.h"

class putBox : public GeometricFigure
{
protected:
    int x1_,y1_,z1_,x0_,y0_,z0_;
    int r_,g_,b_,dx_,dy_,dz_;
    float alpha_;
public:
    putBox(int dx,int dy,int dz,int x0,int y0,int z0,int x1,int y1,int z1,int _r,int _g,int _b,float alpha);
    ~putBox();
    void draw(Sculptor &des);
};

#endif // PUTBOX_H
