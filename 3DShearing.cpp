#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color);

        x += xInc;
        y += yInc;
    }
}

struct Point3D
{
    int x, y, z;
};

int main()
{
    int gd = DETECT, gm;

    struct Point3D p[8];
    struct Point3D np[8];

    float shxy, shxz;
    float shyx, shyz;
    float shzx, shzy;

    int edges[12][2] =
    {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    int i;
    int a, b;

    initgraph(&gd, &gm, "");

    printf("Enter 8 vertices of Cube (x y z):\n");

    for(i = 0; i < 8; i++)
    {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d %d",
              &p[i].x,
              &p[i].y,
              &p[i].z);
    }

    printf("\nEnter Shearing Factors:\n");

    printf("Shear X with Y (shxy): ");
    scanf("%f", &shxy);

    printf("Shear X with Z (shxz): ");
    scanf("%f", &shxz);

    printf("Shear Y with X (shyx): ");
    scanf("%f", &shyx);

    printf("Shear Y with Z (shyz): ");
    scanf("%f", &shyz);

    printf("Shear Z with X (shzx): ");
    scanf("%f", &shzx);

    printf("Shear Z with Y (shzy): ");
    scanf("%f", &shzy);

    for(i = 0; i < 12; i++)
    {
        a = edges[i][0];
        b = edges[i][1];

        drawLine(p[a].x, p[a].y, p[b].x, p[b].y, WHITE);
    }

    for(i = 0; i < 8; i++)
    {
        np[i].x = p[i].x + shxy * p[i].y + shxz * p[i].z;
        np[i].y = shyx * p[i].x + p[i].y + shyz * p[i].z;
        np[i].z = shzx * p[i].x + shzy * p[i].y + p[i].z;
    }

    for(i = 0; i < 12; i++)
    {
        a = edges[i][0];
        b = edges[i][1];

        drawLine(np[a].x, np[a].y,np[b].x, np[b].y, RED);
    }

    getch();
    closegraph();
    return 0;
}
