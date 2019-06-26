#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "geometricfigure.h"

class putVoxel : public GeometricFigure
{
protected:
    int x_,y_,z_;
    int r_,g_,b_;
    float alpha_;
public:
    putVoxel(int x,int y,int z,int _r,int _g,int _b,float alpha);
    ~putVoxel();
    void draw(Sculptor &des);
};

#endif // PUTVOXEL_H
