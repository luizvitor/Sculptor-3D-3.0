#include "cutvoxel.h"
//Metodo para recortar um unico elemento.
cutVoxel::cutVoxel(int x,int y,int z){
    x0_=x;y0_=y;z0_=z;
}
cutVoxel::~cutVoxel(){

}
void cutVoxel::draw(Sculptor &des){
    des.cutVoxel(x0_,y0_,z0_);
}
