#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>
#include<string.h>

struct detail
{
    char name[30], cage[3], diff;
    int iage;
}s;

struct quan
{
   char q[60],a[4][50],cans,diff;
   int qno;
};

void symbol()
{
  int midx = getmaxx() / 2, midy = getmaxy() / 2;
  int xradius = 100, yradius = 100;


  setcolor(15);
  setfillstyle(0, 2);

  for(int y=0;y<=225;y+=15)
     pieslice(midx, midy, y, y+15, 140);

  for(y=300;y<=360;y+=15)
     pieslice(midx, midy, y, y+15, 140);

  setcolor(0);
  circle(midx,midy,140);

  setfillstyle(1,0);
  fillellipse(midx, midy, 110,110);

  setcolor(15);
  setfillstyle(2,0);
  fillellipse(midx,midy+150,30,30);
  setcolor(15);
  int rect[8]={midx-30,midy,midx+30,midy,midx+30,midy+150,midx-30,midy+150};
  setfillstyle(2,15);
  fillpoly(4,rect);

  setcolor(6);
  setfillstyle(1, 6);
  fillellipse(midx, midy, xradius, yradius);

  setcolor(14);
  setfillstyle(1, 14);
  fillellipse(midx, midy, xradius-10, yradius-10);

  setcolor(4);
  setfillstyle(1, 4);
  int bolt[12]={midx,midy-90,midx-50,midy+25,midx+20,midy+5,midx,midy+90,midx+50,midy-25,midx-20,midy-5};
  fillpoly(6,bolt);

  setcolor(2);
  settextstyle(8,HORIZ_DIR,5);
  for(int j=0;j<3;j++)
     outtextxy(midx-100+j,25,"BRAINIAC");
  settextstyle(0,HORIZ_DIR,1);
  while(!kbhit())
  {
    delay(50);
    randomize();
    setcolor(rand());
    outtextxy(165,450,"ARE YOU READY TO BECOME THE 'BRAINIAC' ?");
  }
}

void read(char ch[100],int x,int n)
 {
	int i=0;
	char t[2];
	while(i<=n)
	{
	   if(i==-1)
	     i=0;
	   ch[i]=t[0]=getch();
	   if(ch[i]==13)
	     break;
	   else if(ch[i]==8)
	    {
	      setcolor(0);
	      if(i==0)
		i=1;
	      for(int j=1;j<=10;j++)
		 rectangle(105+((i-1)*8),x+j-2,105+((i)*8),x+6);
	      --i;
		      continue;
	    }
	   t[1]='\0';
	   setcolor(4);
	   outtextxy(105+(i*8),x,t);
	   i++;
	}
	ch[i]='\0';
 }

void game(quan *r)
{
     int len,p,i,j,midx=getmaxx()/2,midy=getmaxy()/2,count=0;
     char **parts;
     while(count<10)
     {
	cleardevice();
	len=strlen(r[count].q);
	for(i=j=len/2;i>=len-10||j<=len+10;i--,j++)
	if(r[count].q[i]==' ')
	{
	  p=i;
	  break;
	}
	else if(r[count].q[j]==' ')
	{
	  p=j;
	  break;
	}
	strncpy(parts[0],r[count].q,p);
	parts[0][p]='\0';
	for(i=p+1,j=0;p<=len;i++,j++)
	   parts[1][j]=r[count].q[i];

	setcolor(2);
	for(int y=0;y<=2;y++)
	{
	   rectangle(midx-125+y, midy-40+y, midx+125-y,midy+10-y);
	   rectangle(midx-125+y, midy+20+y, midx+125-y,midy+70-y);
	   rectangle(midx-125+y, midy+80+y, midx+125-y,midy+130-y);
	   rectangle(midx-125+y, midy+140+y, midx+125-y,midy+190-y);
	}

	setcolor(4);
	settextstyle(0,0,1);

	settextjustify(1,2);

	outtextxy(midx,midy-20+2,r[count].a[0]);
	outtextxy(midx,midy+40+2,r[count].a[1]);
	outtextxy(midx,midy+100+2,r[count].a[2]);
	outtextxy(midx,midy+160+2,r[count].a[3]);

	setcolor(2);
	for(y=0;y<=0;y++)
	{
	   outtextxy(midx,100,parts[0]);
	   outtextxy(midx,125,parts[1]);
	}
	int i=30;
	while(!kbhit())
	{
	   delay(1000);
	   i--;
	}
     }
}

void currentq(char d)
{
    int a1=0;
    quan b1,cur[20];
    fstream f1("current.dat",ios::in|ios::out);
    while(f1.read((char*)&b1,sizeof(b1)))
	 cur[a1++];
    if(d=='e')
      game(cur);
    else
      game(cur+10);
}
void scienceq(char d)
{
    int a2=0;
    quan b2,sci[20];
    fstream f2("science.dat",ios::in|ios::out);
    while(f2.read((char*)&b2,sizeof(b2)))
	 sci[a2++];
    if(d=='e')
      game(sci);
    else
      game(sci+10);
}
void techq(char d)
{
    int a3=0;
    quan b3,tech[20];
    fstream f3("tech.dat",ios::in|ios::out);
    while(f3.read((char*)&b3,sizeof(b3)))
	 tech[a3++];
    if(d=='e')
      game(tech);
    else
      game(tech+10);
}
void sportsq(char d)
{
    int a4=0;
    quan b4,spo[20];
    fstream f4("sports.dat",ios::in|ios::out);
    while(f4.read((char*)&b4,sizeof(b4)))
	 spo[a4++];
    if(d=='e')
      game(spo);
    else
      game(spo+10);
}
void moviesq(char d)
{
    int a5=0;
    quan b5,mov[20];
    fstream f5("current.dat",ios::in|ios::out);
    while(f5.read((char*)&b5,sizeof(b5)))
	 mov[a5++];
    if(d=='e')
      game(mov);
    else
      game(mov+10);
}
void marker(int maxx,int maxy,int color)
{
     int poly[6]={maxx-6,maxy,maxx+2,maxy-7,maxx+2,maxy+7};
     setcolor(0);
     setfillstyle(SOLID_FILL,color);
     fillpoly(3, poly);
}

void main()
{
  int gdriver = DETECT,gmode;
  int midx, midy, i;
  char ch1,ch2;
  initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

  symbol();
  getch();
  do
  {
  cleardevice();
  setcolor(2);
  settextstyle(8,HORIZ_DIR,5);
  for(int j=0;j<3;j++)
     outtextxy(getmaxx()/2-100+j,25,"BRAINIAC");

  settextstyle(0,HORIZ_DIR,1);
  setcolor(14);
  outtextxy(50,255,"NAME :");
  line(50,264,80,264);
  outtextxy(60,303,"AGE : ");
  line(60,312,82,312);
  setcolor(8);
  for(int i4=0;i4<2;i4++)
  {
     rectangle(100+i4,250+i4,500+i4,270+i4);
     rectangle(100+i4,297+i4,150+i4,318+i4);
  }

  marker(515,260,2);
  read(s.name,256,30);
  marker(515,260,0);
  marker(162,309,2);
  read(s.cage,306,3);
  marker(162,309,0);
  s.iage=atoi(s.cage);
  if(s.iage>=128||s.iage<=1)
    s.cage[0]='\0';
  setcolor(15);

  do
  {
     setcolor(15);
     outtextxy(100,350,"DIFFICULTY : 1) BY AGE            2) BY CHOICE");
     ch1=getch();
     if(ch1=='1')
     {
       if(s.iage<=15)
       {
	 s.diff='e';
	 outtextxy(150,390,"      EASY RECOMMENDED");
       }
       else
       {
	 s.diff='h';
	 outtextxy(150,390,"        HARD RECOMMENDED");
       }
     }
     else if(ch1=='2')
     {
       while(1)
       {
	 setcolor(15);
	 outtextxy(120,370,"    1) EASY-PEASY            2)PUNISHING");
	 ch2=getch();
	 if(ch2=='1')
	 {
	   s.diff='e';
	   outtextxy(150,390,"         YOU'VE SELECTED EASY");
	   break;
	 }
	 else if(ch2=='2')
	 {
	   s.diff='h';
	   outtextxy(150,390,"           YOU'VE SELECTED HARD");
	   break;
	 }
	 else
	 {
	   outtextxy(200,450,"       WRONG OPTION");
	   delay(1000);
	   setcolor(0);
	   setfillstyle(1,0);
	   bar(0,450,getmaxx(),getmaxy());
	 }
       }
     }
     else
     {
       outtextxy(200,450,"          WRONG OPTION");
       delay(1000);
       setcolor(0);
       setfillstyle(1,0);
       bar(0,350,getmaxx(),getmaxy());
     }
     if(!s.name[0]||!s.cage[0])
     {
       outtextxy(200,450,"Enter Valid Name and Age");
       delay(2500);
     }
  }while(ch1!='1'&&ch1!='2');
}while(!s.name[0]);
  delay(1000);
  char ch3;
  while(1)
  {
     setcolor(7);
     cleardevice();
     settextstyle(4,0,3);
     outtextxy(300,50,"TOPICS");
     outtextxy(300,100,"1.CURRENT AFFAIRS");
     outtextxy(300,150,"2.SCIENCE");
     outtextxy(300,200,"3.MOVIES");
     outtextxy(300,250,"4.TECH");
     outtextxy(300,300,"5.SPORTS");
     ch3=getch();
     if(ch3>='1'&&ch3<='5')
       break;
     else
       continue;
  }
  switch(ch3)
  {
      case '1':  currentq(s.diff);
		 break;
      case '2':  scienceq(s.diff);
		 break;
      case '3':  moviesq(s.diff);
		 break;
      case '4':  techq(s.diff);
		 break;
      case '5':  sportsq(s.diff);
		 break;
  }
  cleardevice();
  closegraph();
}