#include <graphics.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    int x, y;

    printf("Enter top-left corner (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter bottom-right corner (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    for (x = x1; x <= x2; x++)
    {
        putpixel(x, y1, WHITE);
        putpixel(x, y2, WHITE);
    }

    for (y = y1; y <= y2; y++)
    {
        putpixel(x1, y, WHITE);
        putpixel(x2, y, WHITE);
    }

    for (y = y1 + 1; y < y2; y++)
    {
        for (x = x1 + 1; x < x2; x++)
        {
            putpixel(x, y, GREEN);
        }
    }

    getch();
    closegraph();

    return 0;
}
