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

    if (abs((int)dx) > abs((int)dy))
        steps = abs((int)dx);
    else
        steps = abs((int)dy);

    xInc = dx / steps;
    yInc = dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++)
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

    int x1, y1, x2, y2, x3, y3;
    float sx, sy;

    printf("Enter coordinates of Triangle:\n");

    printf("Vertex 1 (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Vertex 2 (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Vertex 3 (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    printf("Enter Scaling Factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    drawLine(x1, y1, x2, y2, WHITE);
    drawLine(x2, y2, x3, y3, WHITE);
    drawLine(x3, y3, x1, y1, WHITE);


    int nx1 = (int)(x1 * sx + 0.5);
    int ny1 = (int)(y1 * sy + 0.5);

    int nx2 = (int)(x2 * sx + 0.5);
    int ny2 = (int)(y2 * sy + 0.5);

    int nx3 = (int)(x3 * sx + 0.5);
    int ny3 = (int)(y3 * sy + 0.5);


    drawLine(nx1, ny1, nx2, ny2, RED);
    drawLine(nx2, ny2, nx3, ny3, RED);
    drawLine(nx3, ny3, nx1, ny1, RED);

    getch();
    closegraph();

    return 0;
}
