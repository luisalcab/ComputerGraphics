// Drawing a line with Bresenham's algorithm
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
 
// Bresenham's line algorithm
function drawLine(x1, y1, x2, y2) {
    var dx = Math.abs(x2 - x1);
    var dy = Math.abs(y2 - y1);
    var sx = (x1 < x2) ? 1 : -1;
    var sy = (y1 < y2) ? 1 : -1;
    var err = dx - dy;

    while(true) {
        point (x1, y1);
        if ((x1 == x2) && (y1 == y2)) break;
        var e2 = 2 * err;
        if (e2 > -dy) { 
            err -= dy; 
            x1  += sx; 
        }
        if (e2 <  dx) { 
            err += dx; 
            y1  += sy; 
        }
    }
}