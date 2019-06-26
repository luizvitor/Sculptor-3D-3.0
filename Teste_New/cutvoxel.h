#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "geometricfigure.h"

/**
 * @brief Metodo para recortar um unico elemento.
 */
class cutVoxel : public GeometricFigure
{
protected:
    int x0_,y0_,z0_;
public:
    cutVoxel(int x,int y,int z);
    ~cutVoxel();
    void draw(Sculptor &des);
};

#endif // CUTVOXEL_H
