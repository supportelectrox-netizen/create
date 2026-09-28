#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

float xmin,ymin,xmax,ymax;

void drawLine(int x1,int y1,int x2,int y2,int color)
{
    float dx,dy,xinc,yinc,x,y;
    int steps;
    dx = x2-x1;
    dy = y2-y1;
    if(fabs(dx)>fabs(dy))
    {
        steps = fabs(dx);
    }
    else
    {
        steps = fabs(dy);
    }
    xinc = dx/steps;
    yinc = dy/steps;
    x = x1;
    y = y1;
    for(int i = 0;i<=steps;i++)
    {
        putpixel((int)(x+0.5),(int)(y+0.5),color);
        x = x+xinc;
        y = y+yinc;
    }

}

int computeCode(float x,float y)
{

    int code = INSIDE;
    if(x<xmin)
    {
        code |= LEFT;
    }
    else if(x>xmax)
    {
        code |= RIGHT;
    }
    if(y<ymin)
    {
        code |= BOTTOM;
    }
    else if(y>ymax)
    {
        code |= TOP;
    }
  return code;

}

void lineClip(float x1,float y1,float x2,float y2)
{

    int code1 = computeCode(x1,y1);
    int code2 = computeCode(x2,y2);
    int accept = 0;
    while(1)
    {
        if(code1 == 0 && code2 == 0)
        {
            accept = 1;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }

        else
        {
            float x,y;
            int codeOut;

            if(code1 != 0)
            {
                codeOut = code1;
            }
            else
            {
                codeOut = code2;
            }

            if(codeOut & TOP)
            {
                x = x1 + (x2-x1)*(ymax-y1)/(y2-y1);
                y = ymax;
            }
            else if(codeOut & BOTTOM)
            {
                x = x1 +(x2-x1)*(ymin-y1)/(y2-y1);
                y = ymin;
            }
            else if(codeOut & RIGHT)
            {
                y = y1 + (y2-y1)*(xmax-x1)/(x2-x1);
                x = xmax;
            }
            else
            {
                y = y1 + (y2-y1)*(xmin-x1)/(x2-x1);
                x = xmin;
            }

            if(codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1,y1);
            }
            else
            {
                x2 =x;
                y2 = y;
                code2 = computeCode(x2,y2);
            }


        }
    }


   if(accept)
   {
       drawLine(round(x1),round(y1),round(x2),round(y2),RED);


   }

}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    float x1,y1,x2,y2;

    printf("Enter xmin ymin xmax ymax ");
    scanf("%f %f %f %f",&xmin,&ymin,&xmax,&ymax);

    printf("Enter x1 y1 x2 y2");
    scanf("%f %f %f %f",&x1,&y1,&x2,&y2);

    drawLine(xmin,ymin,xmax,ymin,WHITE);
    drawLine(xmin,ymin,xmin,ymax,WHITE);
    drawLine(xmin,ymax,xmax,ymax,WHITE);
    drawLine(xmax,ymin,xmax,ymax,WHITE);

    drawLine(x1,y1,x2,y2,YELLOW);

    lineClip(x1,y1,x2,y2);

    getch();
    closegraph();
    return 0;
}
