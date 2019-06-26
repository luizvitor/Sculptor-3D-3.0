#include "cutbox.h"
//Metodo para recortar em forma de caixa.
cutBox::cutBox(int dx,int dy,int dz,int x0,int y0,int z0,int x1,int y1,int z1){
    x0_=x0;y0_=y0;z0_=z0;
    x1_=x1;y1_=y1;z1_=z1;
    dx_=dx;dy_=dy;dz_=dz;
}
cutBox::~cutBox(){

}
void cutBox::draw(Sculptor &des){
    int a,b,c;
    if(x1_>dx_){
        a=dx_;
    }
    else{
        a=x1_;
    }
    if(y1_>dy_){
        b=dy_;
    }
    else{
        b=y1_;
    }
    if(z1_>dz_){
        c=dz_;
    }
    else{
        c=z1_;
    }
    for(int i=x0_;i<a;i++){
        for(int j=y0_;j<b;j++){
            for(int k=z0_;k<c;k++){
                des.cutVoxel(i,j,k);
            }
        }
    }
}
