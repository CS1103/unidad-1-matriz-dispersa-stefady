//
// Created by HP on 3/09/2019.
//

#ifndef PRACTICAS_MATRIZ_MATRIZ_H
#define PRACTICAS_MATRIZ_MATRIZ_H

using TipoEspacio= long int;
using TipoPorcentaje=float;
using TipoCaracter=int;

class Matriz {
private:
    TipoEspacio ALTO;
    TipoEspacio ANCHO;
    TipoPorcentaje dis;
    TipoEspacio **M;
    TipoEspacio *Value;
    TipoEspacio *Ancho;
    TipoEspacio *Alto;

public:
    Matriz();
    Matriz(TipoEspacio alto,TipoEspacio ancho);
    ~Matriz();

    //TipoPorcentaje setdis(TipoPorcentaje _dis){dis=_dis;}
    //TipoPorcentaje getdis(){return dis;}

    float dispercion(TipoPorcentaje dis);

    void valoresMatriz();
    void crearespacio();
    void imprimirMatriz();
    void imprimirdatos();
    int getAlto();
    int getAncho();
    void Suma(Matriz A, Matriz B);
    void matrizDispersa(Matriz A);
    //void multiplicacionEscalar(const Matriz &A,int n);

};

void ejecutar();
void Menu();


#endif //PRACTICAS_MATRIZ_MATRIZ_H
