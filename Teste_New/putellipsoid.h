#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "geometricfigure.h"
#include "sculptor.h"

class putEllipsoid : public GeometricFigure{
protected:
    int _xcenter,_ycenter,_zcenter,_rx,_ry,_rz;
    int r_,g_,b_,dx_,dy_,dz_;
    float alpha_;
public:
    putEllipsoid(int dx,int dy,int dz,int xcenter,int ycenter,int zcenter,int rx,int ry,int rz,int _r,int _g,int _b,float alpha);
    ~putEllipsoid();
    void draw(Sculptor &des);
};

#endif // PUTELLIPSOID_H
