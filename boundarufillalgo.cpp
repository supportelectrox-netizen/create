#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    int i;
    for (i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), color);
        x += xInc;
        y += yInc;
    }
}

void boundaryFill(int x, int y, int fillColor, int boundaryColor)
{
    int currentColor = getpixel(x, y);

    if (currentColor != boundaryColor && currentColor != fillColor)
    {
        putpixel(x, y, fillColor);

        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int seedX, seedY;

    printf("Enter Top Left Corner (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter Bottom Right Corner (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter Seed Point Inside Rectangle (x y): ");
    scanf("%d %d", &seedX, &seedY);

    int boundaryColor = WHITE;
    int fillColor = RED;

    drawLine(x1, y1, x2, y1, boundaryColor);
    drawLine(x2, y1, x2, y2, boundaryColor);
    drawLine(x2, y2, x1, y2, boundaryColor);
    drawLine(x1, y2, x1, y1, boundaryColor);

    boundaryFill(seedX, seedY, fillColor, boundaryColor);

    getch();
    closegraph();

    return 0;
}
