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

    for(i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), color);
        x += xInc;
        y += yInc;
    }
}

struct Point3D
{
    int x;
    int y;
    int z;
};

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    struct Point3D p[8];
    struct Point3D np[8];

    int tx, ty, tz;
    int i;

    printf("Enter 8 vertices of Cube (x y z):\n");

    for(i = 0; i < 8; i++)
    {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
    }

    printf("Enter Translation Factors (tx ty tz): ");
    scanf("%d %d %d", &tx, &ty, &tz);


    int edges[12][2] =
    {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };


    for(i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(p[a].x, p[a].y,
                 p[b].x, p[b].y,
                 WHITE);
    }


    for(i = 0; i < 8; i++)
    {
        np[i].x = p[i].x + tx;
        np[i].y = p[i].y + ty;
        np[i].z = p[i].z + tz;
    }

    for(i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(np[a].x, np[a].y,
                 np[b].x, np[b].y,
                 RED);
    }


    getch();
    closegraph();

    return 0;
}
