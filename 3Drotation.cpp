#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

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
    float x;
    float y;
    float z;
};


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    struct Point3D p[8], np[8];

    float angle, rad;
    int i;

    printf("Enter 8 vertices of Cube (x y z):\n");

    for(i = 0; i < 8; i++)
    {
        printf("Vertex %d: ", i + 1);
        scanf("%f %f %f",
              &p[i].x,
              &p[i].y,
              &p[i].z);
    }


    printf("Enter Rotation Angle (degrees): ");
    scanf("%f", &angle);


    rad = angle * PI / 180.0;
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
        drawLine((int)p[a].x, (int)p[a].y, (int)p[b].x, (int)p[b].y, WHITE);
    }

    for(i = 0; i < 8; i++)
    {
        np[i].x = p[i].x * cos(rad) - p[i].y * sin(rad);
        np[i].y = p[i].x * sin(rad) + p[i].y * cos(rad);
        np[i].z = p[i].z;
    }

    for(i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        drawLine((int)np[a].x, (int)np[a].y, (int)np[b].x, (int)np[b].y, RED);
    }

    getch();
    closegraph();

    return 0;
}

//Vertex 1: 100 100 0
//Vertex 2: 200 100 0
//Vertex 3: 200 200 0
//Vertex 4: 100 200 0

//Vertex 5: 150 150 100
//Vertex 6: 250 150 100
//Vertex 7: 250 250 100
//Vertex 8: 150 250 100

