#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    if (steps == 0)
    {
        putpixel(x1, y1, WHITE);
        return;
    }

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    int i;

    for (i = 0; i <= steps; i++)
    {
        putpixel((int)round(x), (int)round(y), WHITE);

        x = x + xIncrement;
        y = y + yIncrement;
    }
}


void drawEllipse(int xc, int yc, int rx, int ry)
{
    float x = 0;
    float y = ry;

    float rx2 = rx * rx;
    float ry2 = ry * ry;

    float p1 = ry2 - (rx2 * ry) + (0.25 * rx2);

    float dx = 2 * ry2 * x;
    float dy = 2 * rx2 * y;


    while (dx < dy)
    {
        putpixel(xc + (int)round(x), yc + (int)round(y), WHITE);
        putpixel(xc - (int)round(x), yc + (int)round(y), WHITE);
        putpixel(xc + (int)round(x), yc - (int)round(y), WHITE);
        putpixel(xc - (int)round(x), yc - (int)round(y), WHITE);

        if (p1 < 0)
        {
            x++;

            dx = 2 * ry2 * x;

            p1 = p1 + dx + ry2;
        }
        else
        {
            x++;
            y--;

            dx = 2 * ry2 * x;
            dy = 2 * rx2 * y;

            p1 = p1 + dx - dy + ry2;
        }
    }



    float p2 =
        ry2 * (x + 0.5) * (x + 0.5)
        + rx2 * (y - 1) * (y - 1)
        - rx2 * ry2;


    while (y >= 0)
    {
        putpixel(xc + (int)round(x), yc + (int)round(y), WHITE);
        putpixel(xc - (int)round(x), yc + (int)round(y), WHITE);
        putpixel(xc + (int)round(x), yc - (int)round(y), WHITE);
        putpixel(xc - (int)round(x), yc - (int)round(y), WHITE);

        if (p2 > 0)
        {
            y--;

            dy = 2 * rx2 * y;

            p2 = p2 + rx2 - dy;
        }
        else
        {
            y--;
            x++;

            dx = 2 * ry2 * x;
            dy = 2 * rx2 * y;

            p2 = p2 + dx - dy + rx2;
        }
    }
}



int main()
{
    int gd = DETECT, gm;

    int xc, yc;

    int rx1, ry1;
    int rx2, ry2;

    int topX, topY;
    int bottomX, bottomY;
    int leftX, leftY;
    int rightX, rightY;


    printf("======================================\n");
    printf("     3D WIREFRAME MODEL INPUT\n");
    printf("======================================\n");



    printf("\nEnter center of ellipses (xc yc): ");
    scanf("%d %d", &xc, &yc);


    printf("\nEnter First Ellipse Rx Ry: ");
    scanf("%d %d", &rx1, &ry1);


    printf("Enter Second Ellipse Rx Ry: ");
    scanf("%d %d", &rx2, &ry2);


    printf("\nEnter TOP point (x y): ");
    scanf("%d %d", &topX, &topY);

    printf("Enter BOTTOM point (x y): ");
    scanf("%d %d", &bottomX, &bottomY);

    printf("Enter LEFT point (x y): ");
    scanf("%d %d", &leftX, &leftY);

    printf("Enter RIGHT point (x y): ");
    scanf("%d %d", &rightX, &rightY);


    initgraph(&gd, &gm, "");



    drawLine(leftX, leftY, topX, topY);

    drawLine(topX, topY, rightX, rightY);

    drawLine(rightX, rightY, bottomX, bottomY);

    drawLine(bottomX, bottomY, leftX, leftY);


    drawLine(leftX, leftY, rightX, rightY);

    drawLine(topX, topY, bottomX, bottomY);



    drawEllipse(xc, yc, rx1, ry1);


    drawEllipse(xc, yc, rx2, ry2);


    getch();

    closegraph();

    return 0;
}


//Enter center of ellipses (xc yc): 330 160

//Enter First Ellipse Rx Ry: 220 92
//Enter Second Ellipse Rx Ry: 155 92

//Enter TOP point (x y): 335 35
//Enter BOTTOM point (x y): 335 290
//Enter LEFT point (x y): 15 165
//Enter RIGHT point (x y): 650 165
