// Lines drawing algorithm
/*
Autor: 
Luis Alberto Alcántara Cabrales A01634185

Descripción:
Dado dos puntos en el formato (x,y) se dibuja 
una línea entre ellos utilizando el algoritmo 
de Bresenham.

Fecha: 1/11/2022
*/

#include <iostream>
#include <string>
using namespace std;

// Funcion que imprime en consola los puntos de la linea
void lineDrawing(int x1, int y1, int x2, int y2){
    int dx = x2 - x1;
    int dy = y2 - y1;

}

int main (){
    cout << "Lines drawing algorithm" << endl;

    // Variables
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    // Entrada de datos
    string punto = " ";
    for (int i = 0; i < 2; i++){
        while(getline(cin, punto)){
            if (punto.length() > 0){
                break;
            }
        }
        if (i == 0){
            x1 = stoi(punto.substr(1, punto.find(",")));
            y1 = stoi(punto.substr(punto.find(",") + 1, punto.find(")")));
        } else {
            x2 = stoi(punto.substr(1, punto.find(",")));
            y2 = stoi(punto.substr(punto.find(",") + 1, punto.find(")")));
        }
    }

    // Llamada a la funcion
    lineDrawing(x1, y1, x2, y2);

    return 0;
}