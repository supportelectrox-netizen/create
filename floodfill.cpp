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

void floodFill(int x, int y, int oldColor, int newColor)
{
    int currentColor = getpixel(x, y);

    if (currentColor == oldColor)
    {
        putpixel(x, y, newColor);

        floodFill(x + 1, y, oldColor, newColor);
        floodFill(x - 1, y, oldColor, newColor);
        floodFill(x, y + 1, oldColor, newColor);
        floodFill(x, y - 1, oldColor, newColor);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int seedX, seedY;
    int boundaryColor = WHITE;
    int fillColor = GREEN;
    int oldColor;

    printf("Enter Top Left Corner (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter Bottom Right Corner (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter Seed Point Inside Rectangle (x y): ");
    scanf("%d %d", &seedX, &seedY);

    drawLine(x1, y1, x2, y1, boundaryColor);
    drawLine(x2, y1, x2, y2, boundaryColor);
    drawLine(x2, y2, x1, y2, boundaryColor);
    drawLine(x1, y2, x1, y1, boundaryColor);

    oldColor = getpixel(seedX, seedY);

    floodFill(seedX, seedY, oldColor, fillColor);

    getch();
    closegraph();

    return 0;
}
