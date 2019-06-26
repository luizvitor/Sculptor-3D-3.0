#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "geometricfigure.h"
#include "sculptor.h"

class putSphere : public GeometricFigure
{
protected:
    int _xcenter,_ycenter,_zcenter,_radius;
    int r_,g_,b_,dx_,dy_,dz_;
    float alpha_;
public:
    putSphere(int dx,int dy,int dz,int xcenter,int ycenter,int zcenter,int radius,int _r,int _g,int _b,float alpha);
    ~putSphere();
    void draw(Sculptor &des);
};

#endif // PUTSPHERE_H
