#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <cmath>
#include <iostream>
#include <cstdlib>
#include "vector"

using namespace std;

enum{XY,YZ,ZX};

//estrutura para os blocos.
struct Voxel{
    int red,green,blue; //Cores.
    float alpha;    //Transparência.
    bool isOn; //incluir ou não.
};
//classe para moldar.
class Sculptor{
protected:
    Voxel ***v;//Matriz 3D.
    int nl,nc,np;//Dimensões.
    int r,g,b;
    float a;//Cores.
public:
    //Alocação da Matriz 3D.
    Sculptor(int _nx=0,int _ny=0,int _nz=0);
    //Liberar a memória utilizada.
    ~Sculptor();
    //Atribuir as cores.
    void setColor(int _r,int _g,int _b,float alpha);
    //Criar um Voxel.
    void putVoxel(int x,int y,int z);
    //Cortar um Voxel.
    void cutVoxel(int x,int y,int z);
    //Criar arquivo para leitura do desenho, contendo as dimensões e as cores.
    void writeOFF(string filename);
    //Criar arquivo para armazenar quantidades de poligonos,vertices e posições.
    void writeVECT(string filename);
    //funcao que le o plano e retorna a matriz correspondente
    vector<vector<Voxel>> readPlano(int _dim=0, int _plano = XY);
};

#endif // SCULPTOR_H
