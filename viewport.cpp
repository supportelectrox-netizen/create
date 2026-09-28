#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx, dy, xInc, yInc, x, y;
    int steps, i;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs((int)dx) > abs((int)dy))
        steps = abs((int)dx);
    else
        steps = abs((int)dy);

    xInc = dx / steps;
    yInc = dy / steps;

    x = x1;
    y = y1;

    for(i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), color);
        x += xInc;
        y += yInc;
    }
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float wxmin, wymin, wxmax, wymax;
    float vxmin, vymin, vxmax, vymax;
    float x1, y1, x2, y2, x3, y3;


    printf("Enter Window (wxmin wymin wxmax wymax): ");
    scanf("%f %f %f %f", &wxmin, &wymin, &wxmax, &wymax);


    printf("Enter Viewport (vxmin vymin vxmax vymax): ");
    scanf("%f %f %f %f", &vxmin, &vymin, &vxmax, &vymax);


    printf("Enter Triangle Coordinates:\n");

    printf("Vertex 1: ");
    scanf("%f %f", &x1, &y1);

    printf("Vertex 2: ");
    scanf("%f %f", &x2, &y2);


    printf("Vertex 3: ");
    scanf("%f %f", &x3, &y3);

    drawLine(wxmin, wymin, wxmax, wymin, WHITE);
    drawLine(wxmax, wymin, wxmax, wymax, WHITE);
    drawLine(wxmax, wymax, wxmin, wymax, WHITE);
    drawLine(wxmin, wymax, wxmin, wymin, WHITE);

    drawLine(x1, y1, x2, y2, WHITE);
    drawLine(x2, y2, x3, y3, WHITE);
    drawLine(x3, y3, x1, y1, WHITE);

    float sx = (vxmax - vxmin) / (wxmax - wxmin);
    float sy = (vymax - vymin) / (wymax - wymin);

    float nx1 = vxmin + (x1 - wxmin) * sx;
    float ny1 = vymin + (y1 - wymin) * sy;

    float nx2 = vxmin + (x2 - wxmin) * sx;
    float ny2 = vymin + (y2 - wymin) * sy;

    float nx3 = vxmin + (x3 - wxmin) * sx;
    float ny3 = vymin + (y3 - wymin) * sy;


    drawLine(vxmin, vymin, vxmax, vymin, YELLOW);
    drawLine(vxmax, vymin, vxmax, vymax, YELLOW);
    drawLine(vxmax, vymax, vxmin, vymax, YELLOW);
    drawLine(vxmin, vymax, vxmin, vymin, YELLOW);

    drawLine(nx1, ny1, nx2, ny2, RED);
    drawLine(nx2, ny2, nx3, ny3, RED);
    drawLine(nx3, ny3, nx1, ny1, RED);



    getch();
    closegraph();
    return 0;
}


//Enter Window (wxmin wymin wxmax wymax):
//50 50 250 250

//Enter Viewport (vxmin vymin vxmax vymax):
//300 50 500 250

//Enter Triangle Coordinates:

//Vertex 1:
//80 80

//Vertex 2:
//200 100

//Vertex 3:
//120 200
