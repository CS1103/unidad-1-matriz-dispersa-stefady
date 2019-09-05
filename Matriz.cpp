//
// Created by HP on 3/09/2019.
//

#include "Matriz.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

enum class OPCIONES{Imprimir=1,Datos,Transpuesta,Suma,MEscalar,MVectorial};

Matriz::Matriz() {

}

Matriz::~Matriz() {

}

Matriz::Matriz(TipoEspacio alto,TipoEspacio ancho) :ALTO{alto},ANCHO{ancho}{
}



float Matriz::dispercion(TipoPorcentaje dis) {
    return (ALTO*ANCHO*(1-dis));
}

void Matriz::valoresMatriz() {
    srand(time(nullptr));
    float _dis;cout<<"Ingrese dispersion porcentual: ";cin>>_dis;
    int d; d=dispercion(_dis);
    //creando los 3 arrays: numero, posX, posY
    Value=new TipoEspacio [d];
    for(int i=0;i<d;i++){Value[i]=1+rand()%1;}

    Ancho=new TipoEspacio [d];
    for(int i=0;i<d;i++){Ancho[i]=rand()%ANCHO;}

    Alto=new TipoEspacio [d];
    for(int i=0;i<d;i++){Alto[i]=rand()%ALTO;}
    //creando matriz
    M=new TipoEspacio*[ANCHO];
    for (int i=0; i<ANCHO;i++){
        M[i]=new TipoEspacio [ALTO];
    }
    //rellenando espacios
    for (int i=0; i<ANCHO;i++){
        for (int j=0; j<ALTO;j++){M[i][j]=0;}}
    for(int i=0;i<d;i++){M[Ancho[i]][Alto[i]]=Value[i];}
}

void Matriz::crearespacio() {
    //creando matriz
    M=new TipoEspacio*[ALTO];
    for (int i=0; i<ALTO;i++){
        M[i]=new TipoEspacio [ANCHO];
    }
}

void Matriz::imprimirdatos() {
    for(int i=0;i<ANCHO;i++){
        for(int j=0;j<ALTO;j++)
        {if(M[i][j]!=0){cout<<Value[i]<<"<"<<Ancho[i]<<","<<Alto[i]<<">  ";}}}
}

void Matriz::imprimirMatriz(){
    for(int i=0;i<ANCHO;i++){
        for(int j=0;j <ALTO;j++){
            cout<<M[i][j]<<" ";
        }cout<<endl;
    }
}

int Matriz::getAlto(){
    return ALTO;
}

int Matriz::getAncho(){
    return ANCHO;
}

void Menu(){
    cout<<"1. Imprimir matriz."<<endl;
    cout<<"2. Imprimir valores de la matriz."<<endl;
    cout<<"3. Matriz transpuesta."<<endl;
    cout<<"4. Suma de matrices."<<endl;
    cout<<"5. Multiplicacion escalar de matrices."<<endl;
    cout<<"6. Multiplicacion vectorial de matrices."<<endl;
    cout<<"7. Fin."<<endl;
    cout<<"Escoja opcion: "<<endl;
}


void ejecutar(){
    TipoEspacio fil,col;int opcion;

    cout<<"Cantidad de filas: ";cin>>fil;
    cout<<"Cantidad de columnas: ";cin>>col;

    Matriz M_A(col,fil);cout<<"Creando matriz A ...";   M_A.valoresMatriz();
    ;M_A.imprimirMatriz();cout<<endl;

    Matriz M_B(col,fil);   M_B.valoresMatriz();
    cout<<"Creando matriz B ..."<<endl;

    auto *M_C=new Matriz(fil,col);
    auto *M_D=new Matriz(fil,col);
    auto *M_E=new Matriz(fil,col);

    do{Menu();cin>>opcion;}while(opcion<0||opcion>8);

    switch (OPCIONES(opcion)){
        case OPCIONES::Imprimir:
            M_A.imprimirMatriz();
            do{Menu();cin>>opcion;}while(opcion<0||opcion>8);break;

        case OPCIONES::Datos:
            M_A.imprimirdatos();
            do{Menu();cin>>opcion;}while(opcion<0||opcion>8);break;

        case OPCIONES::Transpuesta:
            M_C->transpuesta(*M_C);M_C->imprimirMatriz();break;
            break;

        case OPCIONES ::Suma:

            break;
    }

}

void Matriz::transpuesta(const Matriz &A) {

    for (TipoEspacio i = 0; i <ALTO; i++) {
        for (TipoEspacio j = 0; j < ANCHO; j++) { A.M[i][j]= M[j][i];
    }
}}

//void Matriz::suma(const Matriz &A,const Matriz &B){
//    TipoEspacio mayorAncho,mayorAlto;
//    if(A.getAncho()<B.getAncho()){mayorAncho=B.getAncho();} else {mayorAncho=A.getAncho();}
//    if(A.getAlto()<B.getAlto()){mayorAlto=B.getAlto();} else {mayorAlto=B.getAlto();}
//    Matriz sum(mayorAncho,mayorAlto); sum.crearespacio();
//    for(TipoEspacio i=0;i<mayorAncho;i++){
//    for(TipoEspacio j=0;j<mayorAlto;j++){//sum[i][j]=A[i][j]+B[i][j];
//    }}}

//void Matriz::multiplicacionEscalar(const Matriz &A,int n){
//    Matriz sum(A.getAncho(),A.getAlto()); sum.crearespacio();
//    for(TipoEspacio i=0;i<A.getAncho();i++){
//        for(TipoEspacio j=0;j<A.getAlto();j++){//sum[i][j]=A[i][j]*B[i][j];
//        }}
//}
