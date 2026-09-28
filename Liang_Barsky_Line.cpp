#include <graphics.h>
#include <stdio.h>
#include <math.h>

void drawLine(float x1, float y1, float x2, float y2, int color)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    int i;

    for (i = 0; i <= steps; i++)
    {
        putpixel((int)round(x), (int)round(y), color);
        x = x + xIncrement;
        y = y + yIncrement;
    }
}

void drawRectangle(float xmin, float ymin, float xmax, float ymax, int color)
{
    drawLine(xmin, ymin, xmax, ymin, color);
    drawLine(xmax, ymin, xmax, ymax, color);
    drawLine(xmax, ymax, xmin, ymax, color);
    drawLine(xmin, ymax, xmin, ymin, color);
}

void liangBarsky(float *x1, float *y1,float *x2, float *y2, float *xmin, float *ymin, float *xmax, float *ymax)
{
    float dx = *x2 - *x1;
    float dy = *y2 - *y1;

    float p[4], q[4];

    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;

    q[0] = *x1 - *xmin;
    q[1] = *xmax - *x1;
    q[2] = *y1 - *ymin;
    q[3] = *ymax - *y1;

    float u1 = 0.0;
    float u2 = 1.0;

    int i;

    for (i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                printf("Line is completely outside.\n");
                return;
            }
        }
        else
        {
            float r = q[i] / p[i];

            if (p[i] < 0)
            {
                if (r > u1)
                    u1 = r;
            }
            else
            {
                if (r < u2)
                    u2 = r;
            }
        }
    }

    if (u1 > u2)
    {
        printf("Line is completely outside.\n");
        return;
    }

    float nx1 = *x1 + u1 * dx;
    float ny1 = *y1 + u1 * dy;

    float nx2 = *x1 + u2 * dx;
    float ny2 = *y1 + u2 * dy;

    printf("Clipped Line:\n");
    printf("(%.2f, %.2f) to (%.2f, %.2f)\n", nx1, ny1, nx2, ny2);

    drawLine(nx1, ny1, nx2, ny2, GREEN);
}

int main()
{
    int gd = DETECT, gm;

    float x1, y1, x2, y2;
    float xmin, ymin, xmax, ymax;

    initgraph(&gd, &gm, "");

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    printf("Enter clipping window (xmin ymin xmax ymax): ");
    scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax);

    drawRectangle(xmin, ymin, xmax, ymax, WHITE);
    drawLine(x1, y1, x2, y2, RED);
    liangBarsky(&x1, &y1, &x2, &y2, &xmin, &ymin, &xmax, &ymax);

    getch();
    closegraph();
    return 0;
}
