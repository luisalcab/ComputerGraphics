// Lines drawing algorithm
/*
Autor: 
Luis Alberto Alcántara Cabrales A01634185

Descripción:
Dado dos puntos en el formato (x,y) se dibuja 
una línea entre ellos.

Fecha: 1/11/2022
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Funcion que imprime en consola los puntos de la linea
void lineDrawing(int x1, int y1, int x2, int y2) {

    int dx = x2 - x1;
    int dy = y2 - y1;

    if(x2 < x1) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
        for (int i = x1; i <= x2; i++) {
            int y = y1 + (i - x1) * dy / dx;
            cout << "(" << i << "," << y << ")" << endl;
        }
        return;
    } else if(x2 == x1) {
        if(y2 < y1) {
            for (int i = y2; i <= y1; i++) {
                cout << "(" << x1 << "," << i << ")" << endl;
            }
            return;
        } else if(y2 == y1) {
            cout << "(" << x1 << "," << y1 << ")" << endl;
            return;
        } else if (y2 > y1) {
            for (int i = y1; i <= y2; i++) {
                cout << "(" << x1 << "," << i << ")" << endl;
            }
            return;
        }
    } else {
        for (int i = x1; i <= x2; i++) {
            int y = y1 + (i - x1) * dy / dx;
            cout << "(" << i << "," << y << ")" << endl;
        }
    }

}

int main (){
    cout << "Lines drawing algorithm" << endl;
    cout << endl;

    // Variables
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    // Entrada de datos
    string punto = " ";
    cout << "Ingresa los puntos en el formato (x,y): " << endl;
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
    cout << "Los puntos de la linea son: " << endl;
    lineDrawing(x1, y1, x2, y2);

    return 0;
}