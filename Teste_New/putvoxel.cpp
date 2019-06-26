#include "putvoxel.h"

putVoxel::putVoxel(int x, int y, int z, int _r, int _g, int _b, float alpha){
    x_=x;y_=y;z_=z;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;
}
putVoxel::~putVoxel(){

}
void putVoxel::draw(Sculptor &des){
    des.setColor(r_,g_,b_,alpha_);
    des.putVoxel(x_,y_,z_);
}
