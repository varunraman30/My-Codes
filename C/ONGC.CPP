//ONGC LOGO
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
    int x=getmaxx()/2, y=getmaxy()/2;
    setbkcolor(4);
    for(int i=0;i<=10;i++)
    {
       arc(x,y,95,200,150-i);
       arc(x,y,340,85,150-i);
       arc(x,y+150,11,70,50+i);
       arc(x,y+150,110,169,50+i);
       arc(x,y+150,16,80,80+i);
       arc(x,y+150,100,163,80+i);
    }
    int poly1[10]={x-13,y-140,x-50,y+40,x-140,y+40,x-140,y+50,x-40,y+50};
    int poly2[10]={x+14,y-140,x+50,y+40,x+140,y+40,x+140,y+50,x+40,y+50};
    int poly3[8]={x-35,y+150,x+35,y+150,x+35,y+200,x-35,y+200};
    int poly4[8]={x-13,y-140,x-13,y+135,x-23,y+135,x-23,y-90};
    int poly5[8]={x+14,y-140,x+14,y+135,x+23,y+135,x+23,y-90};
    int poly6[8]={x+14,y+63,x+135,y+63,x+130,y+73,x+14,y+73};
    int poly7[8]={x-14,y+63,x-135,y+63,x-130,y+73,x-14,y+73};
    setfillstyle(SOLID_FILL,15);
    fillpoly(5,poly1);
    fillpoly(5,poly2);
    fillpoly(4,poly4);
    fillpoly(4,poly5);
    fillpoly(4,poly6);
    fillpoly(4,poly7);
    fillellipse(x,y+150,35,35);

    setfillstyle(SOLID_FILL,0);
    setcolor(0);
    fillpoly(4,poly3);
    getch();
}