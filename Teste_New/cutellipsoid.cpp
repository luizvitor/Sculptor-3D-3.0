#include "cutellipsoid.h"
//Metodo para recortar em forma de elipsoide.
cutEllipsoid::cutEllipsoid(int dx,int dy,int dz,int xcenter,int ycenter,int zcenter,int rx,int ry,int rz){
    xcenter_=xcenter;ycenter_=ycenter;zcenter_=zcenter;
    _rx=rx;_ry=ry;_rz=rz;
    dx_=dx;dy_=dy;dz_=dz;
}
cutEllipsoid::~cutEllipsoid(){

}
void cutEllipsoid::draw(Sculptor &fig){
    double rx_=_rx/1.0,ry_=_ry/1.0,rz_=_rz/1.0;
    double dist;
    for(int i=0;i<dx_;i++){
        for(int j=0;j<dy_;j++){
            for(int k=0;k<dz_;k++){
                //formula para calcular uma elipsoide.
                dist=(i-xcenter_/1.0)*(i-xcenter_/1.0)/(rx_*rx_)+
                (j-ycenter_/1.0)*(j-ycenter_/1.0)/(ry_*ry_)+
                (k-zcenter_/1.0)*(k-zcenter_/1.0)/(rz_*rz_);
                if(dist<=1){
                    fig.cutVoxel(i,j,k);
                }
            }
        }
    }
}
