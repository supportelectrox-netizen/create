#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    int xc, yc, r;
    int x = 0, y;
    int p;

    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "");

    y = r;
    p = 1 - r;

    while (x <= y)
    {
        drawCircle(xc, yc, x, y);

        x++;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }

    getch();
    closegraph();

    return 0;
}
