#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "geometricfigure.h"
#include "sculptor.h"

/**
 * @brief Metodo para recortar em forma de esfera.
 */
class cutSphere : public GeometricFigure
{
protected:
    int _xcenter,_ycenter,_zcenter,_radius;
    int dx_,dy_,dz_;
public:
    cutSphere(int dx,int dy,int dz,int xcenter,int ycenter,int zcenter,int radius);
    ~cutSphere();
    void draw(Sculptor &des);
};

#endif // CUTSPHERE_H
