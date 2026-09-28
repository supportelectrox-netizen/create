#include <graphics.h>
#include <stdio.h>

void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;

    float p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    float dx = 2 * ry * ry * x;
    float dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0)
        {
            x++;
            dx = 2 * ry * ry * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = 2 * ry * ry * x;
            dy = 2 * rx * rx * y;
            p1 = p1 + dx - dy + (ry * ry);
        }
    }

    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y - 1) - (rx * rx) * (ry * ry);
    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0)
        {
            y--;
            dy = 2 * rx * rx * y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x++;
            y--;
            dx = 2 * ry * ry * x;
            dy = 2 * rx * rx * y;
            p2 = p2 + dx - dy + (rx * rx);
        }
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int xc, yc, rx, ry;

    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter X-radius (rx): ");
    scanf("%d", &rx);

    printf("Enter Y-radius (ry): ");
    scanf("%d", &ry);

    drawEllipse(xc, yc, rx, ry);

    getch();
    closegraph();

    return 0;
}
