#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "geometricfigure.h"
#include "sculptor.h"

/**
 * @brief Metodo para recortar em forma de elipsoide.
 */
class cutEllipsoid : public GeometricFigure
{
protected:
    int xcenter_,ycenter_,zcenter_;
    int _rx,_ry,_rz;
    int dx_,dy_,dz_;
public:
    cutEllipsoid(int dx,int dy,int dz,int xcenter,int ycenter,int zcenter,int rx,int ry,int rz);
    virtual ~cutEllipsoid();
    void draw(Sculptor &fig);
};

#endif // CUTELLIPSOID_H
