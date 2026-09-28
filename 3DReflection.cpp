#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    if (steps == 0)
    {
        putpixel(x1, y1, color);
        return;
    }

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    int i;

    for (i = 0; i <= steps; i++)
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

    initgraph(&gd, &gm, "");

    struct Point3D p[8];

    printf("Enter 8 vertices of Cube (x y z):\n");

    int i;

    for (i = 0; i < 8; i++)
    {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
    }

    int choice;

    printf("\n3D Reflection Options:\n");
    printf("1. Reflection about XY Plane\n");
    printf("2. Reflection about XZ Plane\n");
    printf("3. Reflection about YZ Plane\n");
    printf("4. Reflection about X Axis\n");
    printf("5. Reflection about Y Axis\n");
    printf("6. Reflection about Z Axis\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    int edges[12][2] =
    {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };

    for (i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(
            p[a].x,
            p[a].y,
            p[b].x,
            p[b].y,
            WHITE
        );
    }

    struct Point3D np[8];

    for (i = 0; i < 8; i++)
    {
        np[i] = p[i];

        if (choice == 1)
        {
            np[i].z = -p[i].z;
        }
        else if (choice == 2)
        {
            np[i].y = -p[i].y;
        }
        else if (choice == 3)
        {
            np[i].x = -p[i].x;
        }
        else if (choice == 4)
        {
            np[i].y = -p[i].y;
            np[i].z = -p[i].z;
        }
        else if (choice == 5)
        {
            np[i].x = -p[i].x;
            np[i].z = -p[i].z;
        }
        else if (choice == 6)
        {
            np[i].x = -p[i].x;
            np[i].y = -p[i].y;
        }
    }

    int offsetX = 250;

    for (i = 0; i < 12; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        drawLine(
            np[a].x + offsetX,
            np[a].y,
            np[b].x + offsetX,
            np[b].y,
            RED
        );
    }

    setcolor(WHITE);
    outtextxy(50, 30, "Original Cube");

    setcolor(RED);
    outtextxy(300, 30, "Reflected Cube");

    getch();

    closegraph();

    return 0;
}
