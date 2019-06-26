#include "cutsphere.h"
//Metodo para recortar em forma de esfera.
cutSphere::cutSphere(int dx,int dy,int dz,int xcenter,int ycenter,int zcenter,int radius){
    _xcenter=xcenter;_ycenter=ycenter;_zcenter=zcenter;_radius=radius;
    dx_=dx;dy_=dy;dz_=dz;
}
cutSphere::~cutSphere(){

}
void cutSphere::draw(Sculptor &des){
    double rd=_radius/1.0;
    double dist;
    for(int i=0;i<dx_;i++){
        for(int j=0;j<dy_;j++){
            for(int k=0;k<dz_;k++){
                //formula para calcular uma esfera.
                dist=(i-_xcenter/1.0)*(i-_xcenter/1.0)/(rd*rd)+
                (j-_ycenter/1.0)*(j-_ycenter/1.0)/(rd*rd)+
                (k-_zcenter/1.0)*(k-_zcenter/1.0)/(rd*rd);
                if(dist<=1.0){
                    des.cutVoxel(i,j,k);
                }
            }
        }
    }
}
