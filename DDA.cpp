#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    int gd = DETECT,gm;
    int x1,y1,x2,y2;
    float dx,dy,steps,xinc,yinc,x,y;

    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
    printf("Enter x1 y1 :");
    scanf("%d%d",&x1,&y1);

    printf("Enter x2 y2 :");
    scanf("%d%d",&x2,&y2);

    dx= x2-x1;
    dy = y2-y1;
    if(fabs(dx)>fabs(dy))
    {
        steps = dx;
    }
    else
    {
        steps = dy;
    }
    xinc = dx/steps;
    yinc = dy/steps;
    x = x1;
    y = y1;

    for(int i = 0;i<=steps;i++)
    {
        putpixel((int(x+0.5)),(int)(y+0.5),WHITE);
        x = x+xinc;
        y = y+yinc;

    }
    getch();
    closegraph();


}
