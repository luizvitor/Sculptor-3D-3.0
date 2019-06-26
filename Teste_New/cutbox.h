#ifndef CUTBOX_H
#define CUTBOX_H

#include "geometricfigure.h"
#include "sculptor.h"
/**
 * @brief Metodo para recortar em forma de caixa.
 */
class cutBox : public GeometricFigure
{
protected:
    int x1_,y1_,z1_,x0_,y0_,z0_;
    int dx_,dy_,dz_;
public:
    cutBox(int dx,int dy,int dz,int x0,int y0,int z0,int x1,int y1,int z1);
    ~cutBox();
    void draw(Sculptor &des);
};

#endif // CUTBOX_H
