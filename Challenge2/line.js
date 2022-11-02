// Drawing a line
/*
Autor:
Luis Alberto Alcántara Cabrales A01634185

Descripción:
Dibuja una linea entre dos puntos dados

Entradas:
x1, y1, x2, y2

Salidas:
Dibuja una linea entre los puntos dados

Fecha: 02/11/2022
*/

function setup() {
    createCanvas(400, 400);
}
  
function draw() {
    background(220);
    drawLine(1,2,100,20);
    drawLine(10,200,50,10);
    drawLine(300,300,10,10);
    drawLine(200,300,250,50);
    drawLine(350,350,100,300);
}
  
function drawLine(x1, y1, x2, y2) {
    var dx = x2 - x1;
    var dy = y2 - y1;
  
    var m = dy / dx;
    var b = y1 - m * x1;
  
    var x = x1;
    var y = y1;
  
    if (x2 > x1) {
        while (x <= x2) {
            point(x, y);
            x++;
            y = m * x + b;
        }
    } else {
        while (x >= x2) {
            point(x, y);
            x--;
            y = m * x + b;
        }
    }
}