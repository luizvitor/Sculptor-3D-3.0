#include "putsphere.h"
#include <math.h>

putSphere::putSphere(int dx,int dy,int dz,int xcenter, int ycenter, int zcenter, int radius, int _r, int _g, int _b, float alpha){
    _xcenter=xcenter;_ycenter=ycenter;_zcenter=zcenter;_radius=radius;
    r_=_r;g_=_g;b_=_b;alpha_=alpha;dx_=dx;dy_=dy;dz_=dz;
}
putSphere::~putSphere(){

}
void putSphere::draw(Sculptor &des){
    double rd=_radius/1.0;
    //Variavel para a distância da esfera em relação a todos os Voxel.
    double dist;
    des.setColor(r_,g_,b_,alpha_);
    for(int i=0;i<dx_;i++){
        for(int j=0;j<dy_;j++){
            for(int k=0;k<dz_;k++){
                //Equação da esfera.
                dist=(i-_xcenter/1.0)*(i-_xcenter/1.0)/(rd*rd)+
                (j-_ycenter/1.0)*(j-_ycenter/1.0)/(rd*rd)+
                (k-_zcenter/1.0)*(k-_zcenter/1.0)/(rd*rd);
                //Condição para efetuar o desenho da esfera.
                if(dist<=1.0){
                    des.putVoxel(i,j,k);
                }
            }
        }
    }
}
