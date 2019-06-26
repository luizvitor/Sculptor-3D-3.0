#include "putellipsoid.h"
#include <QDebug>

putEllipsoid::putEllipsoid(int dx,int dy,int dz,int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, int _r, int _g, int _b, float alpha){
    _xcenter=xcenter;_ycenter=ycenter;_zcenter=zcenter;_rx=rx;_ry=ry;_rz=rz;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;dx_=dx;dy_=dy;dz_=dz;
}
putEllipsoid::~putEllipsoid(){

}
void putEllipsoid::draw(Sculptor &des){
    double rx_=_rx/1.0,ry_=_ry/1.0,rz_=_rz/1.0;
    double dist;
    des.setColor(r_,g_,b_,alpha_);
    for(int i=0; i<dx_; i++){
        for(int j=0; j<dy_; j++){
            for(int k=0;k<dz_;k++){
                dist=(i-_xcenter/1.0)*(i-_xcenter/1.0)/(rx_*rx_)+
                (j-_ycenter/1.0)*(j-_ycenter/1.0)/(ry_*ry_) +
                (k-_zcenter/1.0)*(k-_zcenter/1.0)/(rz_*rz_);
                if(dist<=1.0){
                    des.putVoxel(i,j,k);
                }
            }
        }
    }
}
