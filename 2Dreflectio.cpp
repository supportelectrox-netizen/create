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

    for (i = 0; i <= steps; i++)
    {
        putpixel((int)round(x), (int)round(y), color);
        x += xInc;
        y += yInc;
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, x3, y3;
    int choice;

    printf("Enter coordinates of Triangle:\n");

    printf("Vertex 1 (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Vertex 2 (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Vertex 3 (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    printf("\nReflection Options:\n");
    printf("1. Reflection about X-axis\n");
    printf("2. Reflection about Y-axis\n");
    printf("3. Reflection about Origin\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;

    drawLine(0, cy, getmaxx(), cy, WHITE);
    drawLine(cx, 0, cx, getmaxy(), WHITE);
    drawLine(cx + x1, cy - y1, cx + x2, cy - y2, WHITE);
    drawLine(cx + x2, cy - y2, cx + x3, cy - y3, WHITE);
    drawLine(cx + x3, cy - y3, cx + x1, cy - y1, WHITE);

    int nx1, ny1;
    int nx2, ny2;
    int nx3, ny3;


    if (choice == 1)
    {
        nx1 = x1;
        ny1 = -y1;

        nx2 = x2;
        ny2 = -y2;

        nx3 = x3;
        ny3 = -y3;
    }
    else if (choice == 2)
    {
        nx1 = -x1;
        ny1 = y1;

        nx2 = -x2;
        ny2 = y2;

        nx3 = -x3;
        ny3 = y3;
    }
    else if (choice == 3)
    {
       
        nx1 = -x1;
        ny1 = -y1;

        nx2 = -x2;
        ny2 = -y2;

        nx3 = -x3;
        ny3 = -y3;
    }
    else
    {
        printf("Invalid Choice!");

        getch();
        closegraph();

        return 0;
    }

    
    drawLine(cx + nx1, cy - ny1, cx + nx2, cy - ny2, RED);
    drawLine(cx + nx2, cy - ny2, cx + nx3, cy - ny3, RED);
    drawLine(cx + nx3, cy - ny3,cx + nx1, cy - ny1, RED);

    getch();
    closegraph();

    return 0;
}
