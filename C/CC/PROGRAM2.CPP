#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
#include<time.h>

int no=44;
int brcount=0;
int atcount=0;
int ordcount=0;                              //ORDER COUNTER
int ordline=0;                               //TABLE LEVEL COUNTER
int total=0;                                 //BILL TOTAL

void feedbk(char ch[100],int x,int n);
time_t t;

struct login		       //STRUCTURE - LOGGING IN
 {
	char user[10],pass[10];
 }log[3];

struct accdetails                            //STRUCTURE - ORDERING
 {
	char name[40],phoneno[15],address1[48],address2[48],bill[12],str[80];
 }acc;

struct feedback                              //STRUCTURE - FEEDBACK
 {
	char name[48], complaint1[48],complaint2[48],complaint3[48],phoneno[15];
 }feed;

class food
{
     private:
	int stock,qty;
	char type, name1[15], footnote1[58], footnote2[58], price[4], name2[12], name3[12];
     public:
	int price1;
	food(int u=0)
	{u++;}
	food(char t, int p, int s, char f1[60], char f2[60], char m[4], char n1[15], char n2[9]="\0", char n3[9]="\0")
	{
	     type=t;
	     price1=p;
	     strcpy(price,m);
	     strcpy(name1,n1);
	     strcpy(name2,n2);
	     strcpy(name3,n3);
	     strcpy(footnote1,f1);
	     strcpy(footnote2,f2);
	     stock=s;
	}

	int quantity(int qtt);

	void display(int x,int y);

	char* dname1()
	{ return name1; }

	char* dname2()
	{ return name2; }

	char* dname3()
	{ return name3; }

	char* dprice()
	{ return price; }

	char dtype()
	{ return type; }

	void cname1()
	{
	   char ch[15];
	   outtextxy(5,256,"ENTER NAME 1");
	   feedbk(ch,256,15);
	   strcpy(name1,ch);
	}

	void cname2()
	{
	   char ch[15];
	   outtextxy(5,256,"ENTER NAME 2");
	   feedbk(ch,256,15);
	   strcpy(name2,ch);
	}

	void cname3()
	{
	   char ch[15];
	   outtextxy(2,256,"ENTER NAME 3");
	   feedbk(ch,256,15);
	   strcpy(name3,ch);
	}

	void cstock()
	{
	   char s[3],t[3],h[15];
	   itoa(stock,t,10);
	   strcpy(h,"STOCK IS : ");
	   strcat(h,t);
	   outtextxy(20,250,h);
	   outtextxy(2,300,"ENTER STOCK");
	   feedbk(s,300,3);
	   if(s[1]=='\0')
	   {
	     s[1]=s[0];
	     s[0]='0';
	   }
	   stock=atoi(s);
	}

	void cprice()
	{
	  char h[15];
	  strcpy(h,"PRICE IS : ");
	  strcat(h,price);
	  outtextxy(20,250,h);
	  outtextxy(2,300,"ENTER PRICE");
	  feedbk(price,300,300);
	  price1=atoi(price);
	}

	void create(char t, int p, int s, char f1[60], char f2[60], char m[4], char n1[15], char n2[9]="\0", char n3[9]="\0")
	{
	     type=t;
	     price1=p;
	     strcpy(price,m);
	     strcpy(name1,n1);
	     strcpy(name2,n2);
	     strcpy(name3,n3);
	     strcpy(footnote1,f1);
	     strcpy(footnote2,f2);
	     stock=s;
	}
};

food e[44];

struct item                                  //STRUCTURE - FOOD IN ORDER TABLE
 {
	int cash,amount,q;
	char money2[4];
	char ming[50];
 }food1[5];

void append()
{
 for(int i=0; i<ordline-1; ++i)
    if(!strcmpi(food1[ordline-1].ming,food1[i].ming))
      {
       food1[i].q+=food1[ordline-1].q;
       food1[i].amount=food1[i].q*food1[i].cash;
       ordline--;
       total=0;
      }
}

void navigator(int midx,int midy)            //FUNCTION - NAVIGATOR
 {
	int poly[6]={midx-5,midy-15,midx-5,midy+15,midx-25,midy};
	setcolor(14);
	setfillstyle(SOLID_FILL,14);
	fillpoly(3,poly);
  }

void marker(int maxx,int maxy,int color)
{
     int poly[6]={maxx-6,maxy,maxx+2,maxy-7,maxx+2,maxy+7};
     setcolor(0);
     setfillstyle(SOLID_FILL,color);
     fillpoly(3, poly);
}

inline void font(int n,int size)             //FUNCTION - VARIOUS FONTS
 {
	if(n==2)
	   settextstyle(TRIPLEX_FONT,HORIZ_DIR,size);
	else if(n==3)
	   settextstyle(SMALL_FONT,HORIZ_DIR,size);
	else if(n==4)
	   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,size);
	else if(n==5)
	   settextstyle(GOTHIC_FONT,HORIZ_DIR,size);
	else
	   settextstyle(DEFAULT_FONT,HORIZ_DIR,size);
 }

void draw_icream(int color,int spot)
{
      int maxx = getmaxx()-100,maxy = getmaxy()/2;
      int poly[6]={maxx-50,maxy,maxx+50,maxy,maxx,maxy+200};
      setfillstyle(SOLID_FILL, 4);
      setcolor(4);
      fillellipse(maxx,maxy-68,5,5);
      setfillstyle(SOLID_FILL, color);
      setcolor(color);
      fillellipse(maxx,maxy-16,50,50);
      setfillstyle(SOLID_FILL,spot);
      setfillstyle(SOLID_FILL,spot);
      fillellipse(maxx-10,maxy-40,8,8);
      fillellipse(maxx-20,maxy-10,8,8);
      fillellipse(maxx+20,maxy-20,8,8);
      fillellipse(maxx-40,maxy-16,8,8);
      fillellipse(maxx+40,maxy-16,8,8);
      setfillstyle(SOLID_FILL, 6);
      setcolor(6);
      fillpoly(3, poly);
      setcolor(15);
      for(int i=50;i>=0;i-=10)
	 line(maxx-50+i,maxy,maxx-50+i,maxy+4*(i));
      for(i=0;i<=50;i+=10)
	 line(maxx+i,maxy,maxx+i,maxy+200-4*(i));
}

void ruppee(int x, int y)                    //FUNCTION - RUPPEE SYMBOL
 {
	for(int i=0;i<=0;i++)
	{
	   line(x-13+i,y-4+i,x-3+i,y-4+i);
	   line(x-13+i,y+i,x-3+i,y+i);
	   line(x-10,y+4+i,x-3,y+10+i);
	   arc(x-10+i,y,270,90,4);
	}
 }
void draw_coke300()
 {
  int midx = getmaxx()-100;
  int midy = getmaxy() / 2;

  int poly[10]={midx-75,midy-50,midx+75,midy-50,midx+45,midy+175,midx-45,midy+175};
  setcolor(4);

  setfillstyle(SOLID_FILL,4);

  fillpoly(4,poly);

  setfillstyle(SOLID_FILL,8);
  setcolor(15);
  fillellipse(midx,midy-50,75,15);

  for(int k=0;k<=11;k++)
  {
     arc(midx-65+12*k,midy-50,0,180,3);
     if(k>=10)
       continue;

     arc(midx-54+12*k,midy-45,0,180,3);
     arc(midx-54+12*k,midy-55,0,180,3);
  }
  setcolor(7);
  for(int i=0;i<10;i++)
     arc(getmaxx()-100+i,midy+50,60,300,25);
  for(i=0;i<5;i++)
     arc(getmaxx()-80+i,midy+55,60,300,10);
  }
void draw_smiles()                           //FUNCTION - DRAWING SMILES
 {
	int midx = getmaxx()-150;
	int midy = getmaxy() / 2+50;
	setcolor(14);
	setfillstyle(SOLID_FILL,14);
	fillellipse(midx,midy,50,50);
	setfillstyle(SOLID_FILL,5);
	fillellipse(midx-20,midy-20,10,10);
	fillellipse(midx+20,midy-20,10,10);
	setcolor(5);
	for(int i=0;i<=5;i++)
	   arc(midx,midy,210-(i*2),330+(i*2),30-i);
 }

void menutable()                             //FUNCTION - MENU TABLE
 {
		while(!kbhit())
		{
		setbkcolor(4);
		for(int i =0;i<=2;i++)
		{
		   setbkcolor(4);
		   setcolor(15);
		   rectangle(getmaxx()/4*2+i,i,getmaxx()/4*3+i,getmaxy()-i);
		   rectangle(getmaxx()/4,i,getmaxx()-i,getmaxy()/3-i);
		   rectangle(getmaxx()/4,getmaxy()/3*2+i,getmaxx()-i,getmaxy()-i);
		   line(getmaxx()-i,0,getmaxx()-i,getmaxy());
		   line(i,0,i,getmaxy());
		   line(getmaxx()/4+i,0,getmaxx()/4+i,getmaxy());
		   line(getmaxx()/4+i-30,0,getmaxx()/4+i-30,getmaxy());
		   line(i,getmaxy()/7+i,getmaxx()/4+i-30,getmaxy()/7+i);
		   line(i,getmaxy()/7*2+i,getmaxx()/4-30,getmaxy()/7*2+i);
		   line(i,getmaxy()/7*3+i,getmaxx()/4-30,getmaxy()/7*3+i);
		   line(i,getmaxy()/7*4+i,getmaxx()/4-30,getmaxy()/7*4+i);
		   line(i,getmaxy()/7*5+i,getmaxx()/4-30,getmaxy()/7*5+i);
		   line(i,getmaxy()/7*6+i,getmaxx()/4-30,getmaxy()/7*6+i);
		   line(i,getmaxy()-i,getmaxx()/4,getmaxy()-i);
		   line(0,i,getmaxx()/4,i);
		   font(6,1);
		   setcolor(7);
		   outtextxy(getmaxx()/4*3+5,getmaxy()/3*2+8,"To control the side");
		   outtextxy(getmaxx()/4*3+5,getmaxy()/3*2+18,"panel, use the up &");
		   outtextxy(getmaxx()/4*3+10,getmaxy()/3*2+28,"down arrow keys.To");
		   outtextxy(getmaxx()/4*3+10,getmaxy()/3*2+38,"select press enter");
		   outtextxy(getmaxx()/4*3+10,getmaxy()/3*2+48,"& press the number");
		   outtextxy(getmaxx()/4*3+8,getmaxy()/3*2+58,"of the item needed.");
		   outtextxy(getmaxx()/4*3+15,getmaxy()/3*2+68,"To go back to the");
		   outtextxy(getmaxx()/4*3+15,getmaxy()/3*2+78,"side panel,press");
		   outtextxy(getmaxx()/4*3+15,getmaxy()/3*2+88,"escape. After you");
		   outtextxy(getmaxx()/4*3+30,getmaxy()/3*2+98,"have finished");
		   outtextxy(getmaxx()/4*3+5,getmaxy()/3*2+108,"selecting,press 'o'");
		   outtextxy(getmaxx()/4*3+5,getmaxy()/3*2+118,"     to order.");
		   font(6,2);
		   setcolor(rand());
		   outtextxy(getmaxx()/4*3+13,getmaxy()/3*2+138,"HAVE FUN!");
		}
		font(4,3);
		setcolor(2);
		for(i=0;i<=2;i++)
		{
		   outtextxy(20+i+3,getmaxy()/14-15,"SNACKS");
		   outtextxy(20+i-6,getmaxy()/14*3-15,"KRUSHERS");
		   outtextxy(20+i+3,getmaxy()/14*5-15,"COMBOS");
		   outtextxy(20+i+2,getmaxy()/14*7-15,"CHICKEN");
		   outtextxy(20+i,getmaxy()/14*9-15,"BURGERS");
		   outtextxy(20+i-12,getmaxy()/14*11-15,"ICE-CREAM");
		   outtextxy(20+i+5,getmaxy()/14*13-15,"MISC.");
		}
		}
 }

void veg(int midx,int midy,char n)           //FUNCTION - VEG SYMBOL
 {
	int i=1;
	if(n=='b')
	{
	  for(i=1;i<=40;i++)
	  {
	     if(i<=3)
	       setcolor(2);
	     else
	       setcolor(15);
	     rectangle(midx-40+i,midy-40+i,midx+40-i,midy+40-i);
	  }
	  setcolor(2);
	  setfillstyle(SOLID_FILL,2);
	  fillellipse(midx, midy, 20,20);
	}
	else if(n=='s')
	{
	  for(i=1;i<=10;i++)
	  {
	     if(i<=8)
	       setcolor(15);
	     else
	       setcolor(2);
	     rectangle(midx+i,midy+i,midx-i,midy-i);
	  }
	  setcolor(2);
	  setfillstyle(SOLID_FILL,2);
	  fillellipse(midx, midy, 5,5);
	}
 }

void nonveg(int midx,int midy,char n)        //FUNCTION - NON-VEG SYMBOL
 {
	int i=1;
	if(n=='b')
	{
	  for(i=1;i<=40;i++)
	  {
	     if(i<=3)
	       setcolor(4);
	     else
	       setcolor(15);
	     rectangle(midx-40+i,midy-40+i,midx+40-i,midy+40-i);
	  }
	  setcolor(4);
	  setfillstyle(SOLID_FILL,4);
	  fillellipse(midx, midy, 20,20);
	}
	else if(n=='s')
	{
	  for(i=1;i<=10;i++)
	  {
	     if(i<=8)
	       setcolor(15);
	     else
	       setcolor(4);
	     rectangle(midx+i,midy+i,midx-i,midy-i);
	  }
	  setcolor(4);
	  setfillstyle(SOLID_FILL,4);
	  fillellipse(midx, midy, 5,5);
	}
 }

void number(int j)
 {
	font(2,1);
	setcolor(14);
	switch(j)
	{
	     case 8:
			 circle(459,333,10);
			 outtextxy(455,320,"8");
			 font(6,1);
			 outtextxy(getmaxx()/2+18,getmaxy()-15,"See more details");
	     case 7:
			 font(2,1);
			 circle(299,333,10);
			 outtextxy(295,320,"7");
			 font(6,1);
			 outtextxy(getmaxx()/4+18,getmaxy()-15,"See more details");
	     case 6:
			 font(2,1);
			 circle(619,173,10);
			 outtextxy(615,160,"6");
			 font(6,1);
			 outtextxy(getmaxx()/4*3+18,getmaxy()/3*2-10,"See more details");
	     case 5:
			 font(2,1);
			 circle(459,173,10);
			 outtextxy(455,160,"5");
			 font(6,1);
			 outtextxy(getmaxx()/2+18,getmaxy()/3*2-10,"See more details");
	     case 4:
			 font(2,1);
			 circle(300,173,10);
			 outtextxy(295,160,"4");
			 font(6,1);
			 outtextxy(getmaxx()/4+18,getmaxy()/3*2-10,"See more details");
	     case 3:
			 font(2,1);
			 circle(619,18,10);
			 outtextxy(615,5,"3");
			 font(6,1);
			 outtextxy(getmaxx()/4*3+18,getmaxy()/14*4+10,"See more details");
	     case 2:
			 font(2,1);
			 circle(459,18,10);
			 outtextxy(455,5,"2");
			 font(6,1);
			 outtextxy(getmaxx()/2+18,getmaxy()/14*4+10,"See more details");
	     case 1:
			 font(2,1);
			 circle(299,18,10);
			 outtextxy(295,5,"1");
			 font(6,1);
			 outtextxy(getmaxx()/4+18,getmaxy()/14*4+10,"See more details");
	}
 }

void snacks()                                //FUNCTION - SNACK ITEMS
 {
	font(2,1);
	outtextxy(getmaxx()/4+40,getmaxy()/14,e[0].dname1());
	outtextxy(getmaxx()/4+50,getmaxy()/14+20,e[0].dname2());
	outtextxy(getmaxx()/4+47,getmaxy()/14+40,e[0].dname3());

	outtextxy(getmaxx()/4*2+40,getmaxy()/14,e[1].dname1());
	outtextxy(getmaxx()/4*2+50,getmaxy()/14+20,e[1].dname2());
	outtextxy(getmaxx()/4*2+48,getmaxy()/14+40,e[1].dname3());

	outtextxy(getmaxx()/4*3+50,getmaxy()/14,e[2].dname1());

	outtextxy(getmaxx()/4+50,getmaxy()/3+30,e[3].dname1());
	outtextxy(getmaxx()/4+60,getmaxy()/3+50,e[3].dname2());

	outtextxy(getmaxx()/4*2+50,getmaxy()/3+30,e[4].dname1());
	outtextxy(getmaxx()/4*2+65,getmaxy()/3+50,e[4].dname2());
	font(6,1);
	for(int i=2;i<=4;i++)
	   veg(getmaxx()/4*i-20,getmaxy()/4,'s');
	veg(getmaxx()/4*2-20,getmaxy()/3*2-40,'s');
	nonveg(getmaxx()/4*3-20,getmaxy()/3*2-40,'s');

	number(5);
	setcolor(3);
	font(3,7);
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/4-13,e[i-1].dprice());
	}
	for(i=1;i<=2;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/14*8+3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/14*8-7,e[2+i].dprice());
	}
 }

void krushers()                              //FUNCTION - KRUSHER DRINKS
 {
	font(2,1);
	outtextxy(getmaxx()/4+50,getmaxy()/14,e[5].dname1());
	outtextxy(getmaxx()/4+51,getmaxy()/14+20,e[5].dname2());

	outtextxy(getmaxx()/4*2+55,getmaxy()/14,e[6].dname1());
	outtextxy(getmaxx()/4*2+54,getmaxy()/14+20,e[6].dname2());
	outtextxy(getmaxx()/4*2+55,getmaxy()/14+40,e[6].dname3());

	outtextxy(getmaxx()/4*3+55,getmaxy()/14,e[7].dname1());
	outtextxy(getmaxx()/4*3+60,getmaxy()/14+20,e[7].dname2());

	outtextxy(getmaxx()/4+18,getmaxy()/3+40,e[8].dname1());
	outtextxy(getmaxx()/4+62,getmaxy()/3+60,e[8].dname2());

	outtextxy(getmaxx()/4*2+55,getmaxy()/3+40,e[9].dname1());
	outtextxy(getmaxx()/4*2+56,getmaxy()/3+60,e[9].dname2());

	outtextxy(getmaxx()/4*3+24,getmaxy()/3+40,e[10].dname1());
	outtextxy(getmaxx()/4*3+38,getmaxy()/3+60,e[10].dname2());

	outtextxy(getmaxx()/4+62,getmaxy()/3*2+30,e[11].dname1());
	outtextxy(getmaxx()/4+26,getmaxy()/3*2+50,e[11].dname2());

	outtextxy(getmaxx()/4*2+65,getmaxy()/3*2+30,e[12].dname1());
	outtextxy(getmaxx()/4*2+29,getmaxy()/3*2+50,e[12].dname2());

	for(int i=2;i<=4;i++)
	   veg(getmaxx()/4*i-20,getmaxy()/4,'s');
	for(i=2;i<=4;i++)
	   veg(getmaxx()/4*i-20,getmaxy()/3*2-40,'s');
	for(i=2;i<=3;i++)
	   veg(getmaxx()/4*i-20,getmaxy()-40,'s');
	number(8);
	setcolor(3);
	font(3,7);
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/4-13,e[4+i].dprice());
	}
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/14*8+3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/14*8-7,e[6+i].dprice());
	}
	for(i=1;i<=2;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/14*13-7);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/14*13-17,e[10+i].dprice());
	}
 }

void combos()                                //FUNCTION - COMBO MEALS
 {
	font(2,1);
	outtextxy(getmaxx()/4+50,getmaxy()/14,e[13].dname1());
	outtextxy(getmaxx()/4+50,getmaxy()/14+20,e[13].dname2());

	outtextxy(getmaxx()/4*2+48,getmaxy()/14,e[14].dname1());
	outtextxy(getmaxx()/4*2+50,getmaxy()/14+20,e[14].dname2());

	outtextxy(getmaxx()/4*3+46,getmaxy()/14,e[15].dname1());
	outtextxy(getmaxx()/4*3+50,getmaxy()/14+20,e[15].dname2());

	outtextxy(getmaxx()/4+40,getmaxy()/3+40,e[16].dname1());
	outtextxy(getmaxx()/4+50,getmaxy()/3+60,e[16].dname2());

	outtextxy(getmaxx()/4*2+55,getmaxy()/3+40,e[17].dname1());
	outtextxy(getmaxx()/4*2+59,getmaxy()/3+60,e[17].dname2());
	font(6,1);
	for(int i=2;i<=4;i+=2)
	   nonveg(getmaxx()/4*i-20,getmaxy()/4,'s');
	veg(getmaxx()/4*3-20,getmaxy()/4,'s');
	nonveg(getmaxx()/4*2-20,getmaxy()/3*2-40,'s');
	nonveg(getmaxx()/4*3-20,getmaxy()/3*2-40,'s');
	number(5);
	setcolor(3);
	for(i=1;i<=3;i++)
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	for(i=1;i<=2;i++)
	   ruppee(getmaxx()/4*i+32,getmaxy()/14*8+3);
	font(3,7);
	for(i=0;i<=2;i++)
	{
	   outtextxy(getmaxx()/4+37+i,getmaxy()/4-13,e[13].dprice());
	   outtextxy(getmaxx()/2+37+i,getmaxy()/4-13,e[14].dprice());
	   outtextxy(getmaxx()/4*3+37+i,getmaxy()/4-13,e[15].dprice());
	   outtextxy(getmaxx()/4+37+i,getmaxy()/14*8-7,e[16].dprice());
	   outtextxy(getmaxx()/2+37+i,getmaxy()/14*8-7,e[17].dprice());
	}
 }

void fries()                                 //FUNCTION - FRIED ITEMS
 {
	font(2,1);
	outtextxy(getmaxx()/4+55,getmaxy()/14,e[18].dname1());
	outtextxy(getmaxx()/4+45,getmaxy()/14+20,e[18].dname2());

	outtextxy(getmaxx()/4*2+55,getmaxy()/14,e[19].dname1());
	outtextxy(getmaxx()/4*2+45,getmaxy()/14+20,e[19].dname2());

	outtextxy(getmaxx()/4*3+55,getmaxy()/14,e[20].dname1());
	outtextxy(getmaxx()/4*3+50,getmaxy()/14+20,e[20].dname2());

	outtextxy(getmaxx()/4+52,getmaxy()/3+30,e[21].dname1());
	outtextxy(getmaxx()/4+50,getmaxy()/3+50,e[21].dname2());

	outtextxy(getmaxx()/4*2+55,getmaxy()/3+30,e[22].dname1());
	outtextxy(getmaxx()/4*2+40,getmaxy()/3+50,e[22].dname2());

	outtextxy(getmaxx()/4*3+56,getmaxy()/3+30,e[23].dname1());
	outtextxy(getmaxx()/4*3+53,getmaxy()/3+50,e[23].dname2());

	outtextxy(getmaxx()/4+42,getmaxy()/3*2+30,e[24].dname1());
	outtextxy(getmaxx()/4+44,getmaxy()/3*2+50,e[24].dname2());
	font(6,1);
	for(int i=2;i<=4;i++)
	   nonveg(getmaxx()/4*i-20,getmaxy()/4,'s');
	for(i=2;i<=4;i++)
	   nonveg(getmaxx()/4*i-20,getmaxy()/3*2-40,'s');
	for(i=2;i<=2;i++)
	   nonveg(getmaxx()/4*i-20,getmaxy()-40,'s');
	number(7);
	setcolor(3);
	font(3,7);
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/4-13,e[17+i].dprice());
	}
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/14*8+3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/14*8-7,e[20+i].dprice());
	}
	ruppee(getmaxx()/4+32,getmaxy()/14*13-7);
	for(int j=0;j<=2;j++)
	   outtextxy(getmaxx()/4+37+j,getmaxy()/14*13-17,e[24].dprice());
 }

void burgers()                               //FUNCTION - BURGERS
 {
	font(2,1);
	outtextxy(getmaxx()/4+55,getmaxy()/14,e[25].dname1());
	outtextxy(getmaxx()/4+50,getmaxy()/14+20,e[25].dname2());

	outtextxy(getmaxx()/4*2+55,getmaxy()/14,e[26].dname1());
	outtextxy(getmaxx()/4*2+50,getmaxy()/14+20,e[26].dname2());

	outtextxy(getmaxx()/4*3+60,getmaxy()/14,e[27].dname1());
	outtextxy(getmaxx()/4*3+58,getmaxy()/14+20,e[27].dname2());
	outtextxy(getmaxx()/4*3+47,getmaxy()/14+40,e[27].dname3());

	outtextxy(getmaxx()/4+55,getmaxy()/3+30,e[28].dname1());
	outtextxy(getmaxx()/4+45,getmaxy()/3+50,e[28].dname2());
	font(6,1);
	nonveg(getmaxx()/4*2-20,getmaxy()/4,'s');
	for(int i=3;i<=4;i++)
	   veg(getmaxx()/4*i-20,getmaxy()/4,'s');
	nonveg(getmaxx()/2-20,getmaxy()/3*2-40,'s');
	number(4);
	setcolor(3);
	font(3,7);
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/4-13,e[24+i].dprice());
	}
	ruppee(getmaxx()/4+32,getmaxy()/14*8+3);
	for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4+37+j,getmaxy()/14*8-7,e[28].dprice());
 }
void desserts()                              //FUNCTION - ICE CREAMS
 {
	font(2,1);
	outtextxy(getmaxx()/4+45,getmaxy()/14,e[29].dname1());

	outtextxy(getmaxx()/4*2+23,getmaxy()/14,e[30].dname1());

	outtextxy(getmaxx()/4*3+50,getmaxy()/14,e[31].dname1());

	outtextxy(getmaxx()/4+30,getmaxy()/3+30,e[32].dname1());

	outtextxy(getmaxx()/4*2+57,getmaxy()/3+30,e[33].dname1());

	outtextxy(getmaxx()/4*3+50,getmaxy()/3+30,e[34].dname1());
	outtextxy(getmaxx()/4*3+53,getmaxy()/3+50,e[34].dname2());

	outtextxy(getmaxx()/4+50,getmaxy()/3*2+30,e[35].dname1());
	outtextxy(getmaxx()/4+52,getmaxy()/3*2+50,e[35].dname2());
	font(6,1);
	for(int i=2;i<=4;i++)
	   veg(getmaxx()/4*i-20,getmaxy()/4,'s');
	for(i=2;i<=4;i++)
	   veg(getmaxx()/4*i-20,getmaxy()/3*2-40,'s');
	veg(getmaxx()/2-20,getmaxy()-40,'s');
	number(7);
	setcolor(3);
	font(3,7);
	for(i=1;i<=3;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/4-13,e[28+i].dprice());
	}
	for(i=1;i<=3;i++)
	{
	   for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4*i+37+j,getmaxy()/14*8-7,e[31+i].dprice());
	   ruppee(getmaxx()/4*i+32,getmaxy()/14*8+3);
	}
	ruppee(getmaxx()/4+32,getmaxy()/14*13+3);
	for(int j=0;j<=2;j++)
	      outtextxy(getmaxx()/4+37+j,getmaxy()/14*13-7,e[35].dprice());
 }

void coke()                                  //FUNCTION - COKE DRINKS
 {
	font(2,1);
	outtextxy(getmaxx()/4+58,getmaxy()/14,e[36].dname1());
	outtextxy(getmaxx()/4+50,getmaxy()/14+20,e[36].dname2());
	outtextxy(getmaxx()/4*2+60,getmaxy()/14,e[37].dname1());
	outtextxy(getmaxx()/4*2+47,getmaxy()/14+20,e[37].dname2());
	font(6,1);
	for(int i=2;i<=3;i++)
	    veg(getmaxx()/4*i-20,getmaxy()/4,'s');
	number(2);
	if(strcmp(e[38].dprice()," ")!=0)
	{
	  number(3);
	  font(2,1);
	  outtextxy(getmaxx()/4*3+50,getmaxy()/14,e[38].dname1());
	  outtextxy(getmaxx()/4*3+50,getmaxy()/14+20,e[38].dname2());
	  outtextxy(getmaxx()/4*3+50,getmaxy()/14+40,e[38].dname3());
	  setcolor(3);
	  font(3,7);
	  ruppee(getmaxx()/4*3+32,getmaxy()/4-3);
	  for(int o=0;o<=2;o++)
	     outtextxy(getmaxx()/4*3+37+o,getmaxy()/4-13,e[38].dprice());
	  if(e[38].dtype()=='n')
	    nonveg(getmaxx()-20,getmaxy()/4,'s');
	  else
	    veg(getmaxx()-20,getmaxy()/4,'s');
	}
	if(strcmp(e[39].dprice()," ")!=0)
	{
	  number(4);
	  font(2,1);
	  outtextxy(getmaxx()/4+50,getmaxy()/3+30,e[39].dname1());
	  outtextxy(getmaxx()/4+50,getmaxy()/3+50,e[39].dname2());
	  outtextxy(getmaxx()/4+50,getmaxy()/3+70,e[39].dname3());
	  setcolor(3);
	  font(3,7);
	  ruppee(getmaxx()/4+32,getmaxy()/14*8-3);
	  for(int o=0;o<=2;o++)
	     outtextxy(getmaxx()/4+37+o,getmaxy()/14*8-13,e[39].dprice());
	  if(e[39].dtype()=='n')
	    nonveg(getmaxx()/2-20,getmaxy()/3*2-40,'s');
	  else
	    veg(getmaxx()/2-20,getmaxy()/3*2-40,'s');
	}
	if(strcmp(e[40].dprice()," ")!=0)
	{
	  number(5);
	  font(2,1);
	  outtextxy(getmaxx()/2+50,getmaxy()/3+30,e[40].dname1());
	  outtextxy(getmaxx()/2+50,getmaxy()/3+50,e[40].dname2());
	  outtextxy(getmaxx()/2+50,getmaxy()/3+70,e[40].dname3());
	  setcolor(3);
	  font(3,7);
	  ruppee(getmaxx()/2+32,getmaxy()/14*8-3);
	  for(int o=0;o<=2;o++)
	     outtextxy(getmaxx()/2+37+o,getmaxy()/14*8-13,e[40].dprice());
	  if(e[40].dtype()=='n')
	    nonveg(getmaxx()/4*3-20,getmaxy()/3*2-40,'s');
	  else
	    veg(getmaxx()/4*3-20,getmaxy()/3*2-40,'s');
	}
	if(strcmp(e[41].dprice()," ")!=0)
	{
	  number(6);
	  font(2,1);
	  outtextxy(getmaxx()/4*3+50,getmaxy()/3+30,e[41].dname1());
	  outtextxy(getmaxx()/4*3+50,getmaxy()/3+50,e[41].dname2());
	  outtextxy(getmaxx()/4*3+50,getmaxy()/3+70,e[41].dname3());
	  setcolor(3);
	  font(3,7);
	  ruppee(getmaxx()/4*3+32,getmaxy()/14*8-3);
	  for(int o=0;o<=2;o++)
	     outtextxy(getmaxx()/4*3+37+o,getmaxy()/14*8-13,e[41].dprice());
	  if(e[41].dtype()=='n')
	    nonveg(getmaxx()-20,getmaxy()/3*2-40,'s');
	  else
	    veg(getmaxx()-20,getmaxy()/3*2-40,'s');
	}
	if(strcmp(e[42].dprice()," ")!=0)
	{
	  number(7);
	  font(2,1);
	  outtextxy(getmaxx()/4+50,getmaxy()/3*2+30,e[42].dname1());
	  outtextxy(getmaxx()/4+50,getmaxy()/3*2+50,e[42].dname2());
	  outtextxy(getmaxx()/4+50,getmaxy()/3*2+70,e[42].dname3());
	  setcolor(3);
	  font(3,7);
	  ruppee(getmaxx()/4+32,getmaxy()/14*13-3);
	  for(int o=0;o<=2;o++)
	     outtextxy(getmaxx()/4+37+o,getmaxy()/14*13-13,e[42].dprice());
	  if(e[42].dtype()=='n')
	    nonveg(getmaxx()/2-20,getmaxy()-40,'s');
	  else
	    veg(getmaxx()/2-20,getmaxy()-40,'s');
	}
	if(strcmp(e[43].dprice()," ")!=0)
	{
	  number(8);
	  font(2,1);
	  outtextxy(getmaxx()/2+50,getmaxy()/3*2+30,e[43].dname1());
	  outtextxy(getmaxx()/2+50,getmaxy()/3*2+50,e[43].dname2());
	  outtextxy(getmaxx()/2+50,getmaxy()/3*2+70,e[43].dname3());
	  setcolor(3);
	  font(3,7);
	  ruppee(getmaxx()/2+32,getmaxy()/14*13-3);
	  for(int o=0;o<=2;o++)
	     outtextxy(getmaxx()/2+37+o,getmaxy()/14*13-13,e[43].dprice());
	  if(e[43].dtype()=='n')
	    nonveg(getmaxx()/4*3-20,getmaxy()-40,'s');
	  else
	    veg(getmaxx()/4*3-20,getmaxy()-40,'s');
	}
	setcolor(3);
	font(3,7);
	for(i=1;i<=2;i++)
	{
	   ruppee(getmaxx()/4*i+32,getmaxy()/4-3);
	   for(int j=0;j<=2;j++)
	   {
	      outtextxy(getmaxx()/4+37+j,getmaxy()/4-13,e[36].dprice());
	      outtextxy(getmaxx()/2+37+j,getmaxy()/4-13,e[37].dprice());
	   }
	}
 }

void feedbk(char ch[100],int x,int n)        //FUNCTION - CHARACTER FIELD
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

void logo(int color)                    //FUNCTION - LOGO
 {
	setcolor(color);
	for(int i=0;i<10;i++)
	   arc(getmaxx()-75+i,50,60,300,25);
	for(i=0;i<5;i++)
	   arc(getmaxx()-43+i,55,60,300,10);
 }

inline void accept()                         //FUNCTION - ACCEPTING FEEDBACK
 {
	feedbk(feed.name,256,48);
	marker(515,260,0);marker(260,310,2);
	feedbk(feed.phoneno,306,15);
	marker(260,310,0);marker(515,360,2);
	feedbk(feed.complaint1,356,48);
	marker(515,360,0);marker(515,370,2);
	feedbk(feed.complaint2,366,48);
	marker(515,370,0);marker(515,380,2);
	feedbk(feed.complaint3,376,48);
	marker(515,380,0);
 }

void load(int d)                             //FUNCTION - LOADING SCREEN
{
	for(int i=10;i<250;i+=10)
	{
	   cleardevice();
	   font(1,1);
	   setbkcolor(0);
	   setcolor(15);
	   rectangle(getmaxx()/2-122,getmaxy()/2-12,getmaxx()/2+122,getmaxy()/2+12);
	   setcolor(4);
	   for(int j=0;j<=i;j++)
	      line(getmaxx()/2-120+j,getmaxy()/2-10,getmaxx()/2-120+j,getmaxy()/2+10);
	   setcolor(1+random(15));
	   outtextxy(getmaxx()/2-100,getmaxy()/2-100,"PLEASE WAIT...LOADING....");
	   delay(d);
	}
	cleardevice();
}

inline void addbox()                         //FUNCTION - ADDRESS BOX
 {
	setcolor(15);
	rectangle(0,getmaxy()/4,getmaxx(),getmaxy()-120);
	rectangle(getmaxx()/3,getmaxy()/4,getmaxx()/3*2,getmaxy()-120);
 }

void password(char ch[], int x)                         //FUNCTION - PASSWORD FIELD
 {
	int i=0;
	char t[2];
	while(i<=10)
	{
	   if(i==-1)
	     i=0;
	   ch[i]=getch();
	   t[0]='*';
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

void draw_french()                           //FUNCTION - DRAWING FRENCH FRIES
 {
	int midx = getmaxx() / 2+200;
	int midy = getmaxy() / 2+25;
	int poly[14]={midx-100,221,midx-40,375,midx+40,375,midx+100,221};
	setcolor(4);
	setcolor(14);
	setfillstyle(SOLID_FILL,14);
	bar3d(midx-50,midy-(100),midx-30,midy+50, 5, 5);
	bar3d(midx-28,midy-(95),midx-8,midy+50,5,5);
	bar3d(midx-6,midy-(120),midx+14,midy+50, 5, 5);
	bar3d(midx+16,midy-(105),midx+36,midy+50,5,5);
	bar3d(midx-70,midy-(110),midx-53,midy+35, 5, 5);
	bar3d(midx-90,midy-(60),midx-73,midy-20,5,5);
	bar3d(midx+39,midy-(120),midx+60,midy+50,5,5);
	bar3d(midx+62,midy-60,midx+80,midy-20,5,5);
	setfillstyle(SOLID_FILL,4);
	fillpoly(4,poly);
	setcolor(1);
	for(int i=0;i<10;i++)
	   arc(midx+i,getmaxy()/2+50,60,300,25);
	for(i=0;i<5;i++)
	   arc(midx+10+i,getmaxy()/2+50,60,300,10);
 }

inline void addstart()                       //FUNCTION - STARTING OF ADDRESS
 {
	cleardevice();
	logo(4);
	font(3,4);
	addbox();
	setcolor(15);
 }

void andhra()                                //FUNCTION - ANDHRA BANK LOGO
 {
	cleardevice();
	int radius = 100;
	int midx = getmaxx() / 2-100;
	int midy = getmaxy() / 2-100;
	setbkcolor(15);
	setcolor(1);
	for(int i=20;i<=radius;i++)
	   circle(336,255,i);
	setcolor(4);
	for(i=20;i<=radius;i++)
	   circle(midx, midy, i);
	setcolor(15);
	for(int j=0;j<=20;j++)
	{
	   circle(midx, midy, j);
	   circle(336,255,j);
	}
	setcolor(15);
	for(i=0;i<=30;i++)
	   line(midx+5+i,midy-10,midx+5+i,midy+100);
	for(i=0;i<=10;i++)
	   line(319+i,260,319+i,midy);
	setcolor(4);
	for(i=23;i<=104;i++)
	   line(midx-5+i,midy-10,midx-5+i,midy+100);
	setcolor(1);
	for(i=0,j=0;i<=40;i++)
	{
	   if(i%2==0)
	     j++;
	   line(280+j,40,330,40+i);
	}
	setcolor(1);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	for(i=0;i<=2;i++)
	   outtextxy(210+i,getmaxy()/2+125,"ANDHRA BANK");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	for(i=10;i<250;i+=10)
	{
	   setcolor(2);
	   rectangle(getmaxx()/2-123,getmaxy()/2+220-12,getmaxx()/2+123,getmaxy()/2+220+13);
	   setcolor(4);
	   for(int j=0;j<=i;j++)
	      line(getmaxx()/2-120+j,getmaxy()/2+220-10,getmaxx()/2-120+j,getmaxy()/2+220+10);
	   setcolor(1+random(14));
	   outtextxy(getmaxx()/2-100,getmaxy()/2+190,"REDIRECTING....PLEASE WAIT");
	   delay(200);
	}
 }

void info()
{
 setcolor(1);
 font(6,1);
 outtextxy(getmaxx()/2-32,getmaxy()-10,"[PRESS 'Q' TO SPECIFY THE QUANTITY REQUIRED]");
}

void sbi()                                   //FUNCTION - SBI BANK LOGO
 {
	cleardevice();
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2-100;
	setbkcolor(15);
	setcolor(1);
	setfillstyle(SOLID_FILL,1);
	fillellipse(midx,midy,100,100);
	setfillstyle(SOLID_FILL,15);
	setcolor(15);
	fillellipse(midx,midy,20,20);
	setcolor(15);
	for(int i=0;i<=10;i++)
	   line(midx-5+i,midy-20,midx-5+i,midy+100);
	setcolor(1);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	for(i=0;i<=2;i++)
      outtextxy(160+i,midy+120,"STATE BANK OF INDIA");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	for(i=10;i<250;i+=10)
	{
	   setcolor(1);
	   rectangle(getmaxx()/2-123,getmaxy()/2+220-12-100,getmaxx()/2+123,getmaxy()/2+220+13-100);
	   setcolor(4);
	   for(int j=0;j<=i;j++)
	      line(getmaxx()/2-120+j,getmaxy()/2+220-10-100,getmaxx()/2-120+j,getmaxy()/2+220+10-100);
	   setcolor(1+random(14));
	   outtextxy(getmaxx()/2-100,getmaxy()/2+190-100,"REDIRECTING....PLEASE WAIT");
	   delay(200);
	}
 }

void hdfc()                                  //FUNCTION - HDFC BANK LOGO
 {
	cleardevice();
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 4+50;
	setbkcolor(15);
	setcolor(1);
	for(int i=0;i<=80;i++)
	   rectangle(midx-40+i,midy-40+i,midx+40,midy+40);
	setcolor(4);
	for(i=0;i<=20;i++)
	{
	   rectangle(midx-100+i,midy-80+i,midx-80,midy-10);
	   rectangle(midx-100+i,midy-100+i,midx-10,midy-80);
	   rectangle(midx-100+i,midy+10+i,midx-80,midy+80);
	   rectangle(midx-100+i,midy+80+i,midx-10,midy+100);
	   rectangle(midx+10+i,midy-100+i,midx+100,midy-80);
	   rectangle(midx+80+i,midy-100+i,midx+100,midy-10);
	   rectangle(midx+80+i,midy+10+i,midx+100,midy+100);
	   rectangle(midx+10+i,midy+80+i,midx+100,midy+100);
	}
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	for(i=0;i<=2;i++)
	   outtextxy(240+i,getmaxy()/2+100,"HDFC BANK");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	for(i=10;i<250;i+=10)
	{
	   setcolor(2);
	   rectangle(getmaxx()/2-123,getmaxy()/2+220-12,getmaxx()/2+123,getmaxy()/2+220+13);
	   setcolor(4);
	   for(int j=0;j<=i;j++)
	      line(getmaxx()/2-120+j,getmaxy()/2+220-10,getmaxx()/2-120+j,getmaxy()/2+220+10);
	   setcolor(1+random(14));
	   outtextxy(getmaxx()/2-100,getmaxy()/2+190,"REDIRECTING....PLEASE WAIT");
	   delay(200);
	}
 }

void axis()                                  //AXIS BANK LOGO
 {
	cleardevice();
	int midx = getmaxx() / 2;
	setbkcolor(0);
	setcolor(5);
	for(int i=0;i<=30;i++)
	   line(midx+i-15,100,midx-60+i,200);
	for(i=0;i<=40;i++)
	   line(midx-12+i,165,midx+15+i,200);
	setcolor(0);
	for(i=0;i<32;i++)
	   line(303+i,100,380+i,200);
	setcolor(5);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	for(i=0;i<=2;i++)
	outtextxy(240+i,getmaxy()/2,"AXIS BANK");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	for(i=10;i<250;i+=10)
	{
	   setcolor(15);
	   rectangle(getmaxx()/2-123,getmaxy()/2+150-12,getmaxx()/2+123,getmaxy()/2+150+13);
	   setcolor(4);
	   for(int j=0;j<=i;j++)
	      line(getmaxx()/2-120+j,getmaxy()/2+150-10,getmaxx()/2-120+j,getmaxy()/2+150+10);
	   setcolor(1+random(15));
	   outtextxy(getmaxx()/2-100,getmaxy()/2+100,"REDIRECTING....PLEASE WAIT");
	   delay(200);
	}
  }

void assign()
 {
	total=0;
	font(3,7);
	char con[2];
	if(ordline>0)
	{
	   setcolor(5);
	   for(int i=1;i<=ordline;i++)
	   {
	   con[0]=48+i;
	   con[1]='\0';
	   for(int j=0;j<=2;j++)
	      outtextxy(25+j,105+40*(i),con);
	   }
	   font(3,6);
	   char tot[10];
	   setcolor(5);
	   for(int a=0;a<=ordline;a++)
	      total+=food1[a-1].amount;
	   itoa(total,tot,10);
	   for(int j=1;j<=ordline;j++)
	   for(i=0;i<=2;i++)
	   {
	      outtextxy(80+i,108+40*(j),food1[j-1].ming);
	      outtextxy(310+i,108+40*(j),food1[j-1].money2);
	      char string[3];
	      itoa(food1[j-1].q,string,10);
	      outtextxy(450+i,108+40*(j),string);
	      char str[5];
	      itoa(food1[j-1].amount,str,10);
	      outtextxy(550+i,108+40*(j),str);
	      outtextxy(420+i,getmaxy()-68,tot);
	   }
	   strcpy(acc.bill,"RS.");
	   strcat(acc.bill,tot);
	   strcat(acc.bill,"/-");
	}

 }

void order()
 {
	fstream c("Cust.dat",ios::app|ios::out);
	while(1)
	{
		cleardevice();
		int midx = getmaxx() / 2;
		int midy = getmaxy();
		setcolor(1);
		setbkcolor(8);
		font(5,4);
		outtextxy(midx-100,20,"YOUR ORDER");
		font(3,7);
		setcolor(4);
		for(int h=0;h<=2;h++)
		{
		   outtextxy(10+h,105,"S.NO");
		   outtextxy(145+h,105,"NAME");
		   outtextxy(310+h,105,"PRICE");
		   outtextxy(410+h,105,"QUANTITY");
		   outtextxy(545+h,105,"AMOUNT");
		}
		setcolor(15);
		font(6,1);
		outtextxy(midx-200,midy-12,"PRESS 'P' TO PAY OR PRESS ESCAPE TO SELECT MORE ITEMS");
		for(int i=0;i<=7;i++)
		for(int j=0;j<=2;j++)
		{
		   line(0,100+40*i-j,midx*2,100+40*i-j);          //DIVISIONS
		   line(0+j,100,0+j,380);                         //LEFT LIMIT
		   line(midx*2-j,100,midx*2-j,380);               //RIGHT LIMIT
		   line(60+j,100,60+j,380);                       //S.NO LINE
		   line(275+j,100,275+j,380);                     //NAME LINE
		   line(midx*2-j-120,100,midx*2-j-120,380);       //PRICE LINE
		   line(midx+75+j,100,midx+75+j,380);             //QUANTITY LINE
		}
		font(2,3);
		outtextxy(200,midy-75,"TOTAL AMOUNT : ");
		assign();
		int x=410;
		int y=midy-62;
		setcolor(3);
		for(i=0;i<=1;i++)
		{
		   line(x-13+i,y-4+i,x-3+i,y-4+i);
		   line(x-13+i,y+i,x-3+i,y+i);
		   line(x-10,y+4+i,x-3,y+10+i);
		   arc(x-10+i,y,270,90,4);
		}
		font(4,4);
		char choice2=getch();
		if(choice2==27)
		  break;
		if(choice2=='p')
		{
		    cleardevice();
		    if(total==0)
		    {
		      cleardevice();
		      outtextxy(100,100,"YOUR BILL AMOUNT IS ZERO");
		      delay(2000);
		    }
		    else
		    {
		    setcolor(14);
		    setbkcolor(8);
		    font(2,4);
		    outtextxy(250,100,"CUSTOMER");
		    outtextxy(260,140,"DETAILS");
		    for(y=0;y<2;y++)
		    {
		       line(250,140-1+y,405,140-1+y);
		       line(260,180-1+y,370,180-1+y);
		       rectangle(100+y,250-y,500+y,270+y);
		       rectangle(100+y,300-y,250+y,320+y);
		       rectangle(100+y,350-y,500+y,378+y);
		    }
		    setcolor(2);
		    font(6,1);
		    outtextxy(50,255,"NAME :");
		    line(50,264,80,264);
		    outtextxy(20,303,"PHONE NO : ");
		    line(20,312,82,312);
		    outtextxy(20,353,"ADDRESS : ");
		    line(20,362,82,362);

		    feedbk(acc.name,256,40);
		    feedbk(acc.phoneno,306,15);
		    feedbk(acc.address1,354,48);
		    feedbk(acc.address2,364,48);
		    time(&t);
		    strcpy(acc.str,ctime(&t));

		    c.write((char*)&acc,sizeof(acc));
		    cleardevice();
		    font(2,2);
		    do
		    {
		      cleardevice();
		      font(2,2);
		      outtextxy(getmaxx()/2-150,getmaxy()/2-120,"1.STATE BANK OF INDIA");
		      outtextxy(getmaxx()/2-150,getmaxy()/2-90,"2.AXIS BANK");
		      outtextxy(getmaxx()/2-150,getmaxy()/2-60,"3.ANDHRA BANK");
		      outtextxy(getmaxx()/2-150,getmaxy()/2-30,"4.HDFC BANK");
		      choice2=getch();
		    }while(choice2!='1'&&choice2!='2'&&choice2!='3'&&choice2!='4');
		    if(choice2=='1')
		      sbi();
		    else if(choice2=='2')
		      axis();
		    else if(choice2=='3')
		      andhra();
		    else
		      hdfc();
		    ordline=0;
		    cleardevice();
		    setbkcolor(6);
		    setcolor(14);
		    font(5,5);
		    outtextxy(30,getmaxy()/2-10,"PAYMENT SUCCESSFUL !!!");
		    delay(5000);
		    }
		    break;
		}
	}
	c.close();
 }

void dispfeed()
{
   fstream f("Feed.dat",ios::in|ios::binary);
   int g=0;
   f.seekg((int)(-1*sizeof(feed)),ios::end);
   while(f.read((char*)&feed,sizeof(feed))&&g<=4)
   {
	char s[2];
	s[0]=49+g;
	s[1]='\0';
	font(3,6);
	for(int k=0;k<=2;k++)
	{
	   outtextxy(10+k,getmaxy()/5*g+10,"FEEDBACK");
	   outtextxy(95+k,getmaxy()/5*g+10,s);
	}
	font(6,1);
	outtextxy(10,getmaxy()/5*g+40,"NAME : ");
	outtextxy(60,getmaxy()/5*g+40,feed.name);
	outtextxy(10,getmaxy()/5*g+60,"COMMENT : ");
	outtextxy(80,getmaxy()/5*g+60,feed.complaint1);
	outtextxy(80,getmaxy()/5*g+70,feed.complaint2);
	outtextxy(80,getmaxy()/5*g+80,feed.complaint3);
	f.seekg((int)(-2*sizeof(feed)),ios::cur);
	g++;
   }
   if(g==0)
   {
	font(3,6);
	for(int k=0;k<=2;k++)
	   outtextxy(getmaxx()/2-143+k,getmaxy()/2-10,"SORRY, NO FEEDBACKS SUBMITTED");
   }
   f.close();
}

void dispcust()
{
     cleardevice();
     setcolor(15);
     for(int h=0;h<=getmaxy()-3;h+=getmaxy()/5)
     {
	line(0,h+1,getmaxx(),h+1);
	line(0,h+2,getmaxx(),h+2);
	line(0,h+3,getmaxx(),h+3);
     }
     fstream c("Cust.dat",ios::in|ios::binary);
     setbkcolor(14);
     int g=0;
     c.seekg((int)(-1*sizeof(acc)-1),ios::end);
     while(c.read((char*)&acc,sizeof(acc))&&g<=4)
     {
	setcolor(2);
	char s[2];
	s[0]=49+g;
	s[1]='\0';
	font(3,6);
	for(int k=0;k<=2;k++)
	{
	   outtextxy(10+k,getmaxy()/5*g+10,"CUSTOMER");
	   outtextxy(95+k,getmaxy()/5*g+10,s);
	}
	font(6,1);
	outtextxy(10,getmaxy()/5*g+35,"NAME : ");
	outtextxy(60,getmaxy()/5*g+35,acc.name);
	outtextxy(10,getmaxy()/5*g+45,"PHONE NO : ");
	outtextxy(80,getmaxy()/5*g+45,acc.phoneno);
	outtextxy(10,getmaxy()/5*g+55,"ADDRESS : ");
	outtextxy(80,getmaxy()/5*g+55,acc.address1);
	outtextxy(80,getmaxy()/5*g+65,acc.address2);
	outtextxy(10,getmaxy()/5*g+75,"DATE AND TIME : ");
	outtextxy(130,getmaxy()/5*g+75,acc.str);
	outtextxy(10,getmaxy()/5*g+85,"AMOUNT : ");
	outtextxy(80,getmaxy()/5*g+85,acc.bill);
	setcolor(0);
	for(int t6=0;t6<=10;t6++)
	   rectangle(getmaxx()/2+2+t6,getmaxy()/5*g+80+t6,getmaxx()/2+10,getmaxy()/5*g+90);
	c.seekg((int)(-2*sizeof(acc)-1),ios::cur);
	g++;
	setcolor(4);
     }
     if(g==0)
     {
	font(3,6);
	for(int k=0;k<=2;k++)
	   outtextxy(getmaxx()/2-143+k,getmaxy()/2-10,"SORRY, NO CUSTOMERS FOUND");
     }
     c.close();
}

void food :: display(int x, int y)
{
    while(1)
    {
	int midx = getmaxx() / 2;
	int poly[10]={100,getmaxy()-75,midx+75,getmaxy()-75,midx+75,getmaxy()-30,100,getmaxy()-30};
	setcolor(5);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,poly);
	char s[50];
	strcpy(s,name1);strcat(s," ");
	strcat(s,name2);strcat(s," ");
	strcat(s,name3);
	setbkcolor(5);
	setcolor(7);
	font(3,10);
	for(int m=0;m<=2;m++)
	   outtextxy(x+m,y,s);
	font(3,6);
	for(m=0;m<=1;m++)
	{
	   outtextxy(5+m,getmaxy()/2-50,footnote1);
	   outtextxy(5+m,getmaxy()/2-30,footnote2);
	}
	setcolor(3);
	for(int u=0;u<=1;u++)
	   ruppee(75+u,getmaxy()/2+95);
	font(3,7);
	for(u=0;u<=3;u++)
	   outtextxy(82+u,getmaxy()/2+86,dprice());
	if(type=='v')
	  veg(getmaxx()/2+50,getmaxy()/2+100,'s');
	else if(type=='n')
	  nonveg(getmaxx()/2+50,getmaxy()/2+100,'s');
	info();
	char check;
	check=getch();
	if(check==27)
	  break;
	else if(check=='q'||check=='Q')
	{
	   int stack=quantity(stock);
	   if(stack)
	   {
	     stock-=stack;
	     ++ordline;
	     strcpy(food1[ordline-1].ming,s);
	     food1[ordline-1].cash=price1;
	     food1[ordline-1].amount=price1 * stack;
	     strcpy(food1[ordline-1].money2,dprice());
	     food1[ordline-1].q=stack;
	     append();
	   }
	   continue;
	}
	else
	   continue;
    }
}


int food :: quantity(int qtt)                        //FUNCTION - QUANTITY ACCEPTER
{
    int q,f;
    while(1)
    {
      int midx = getmaxx() / 2;
      int poly[10]={100,getmaxy()-75,midx+75,getmaxy()-75,midx+75,getmaxy()-30,100,getmaxy()-30};
      setcolor(15);
      int x=414,i=0;
      setfillstyle(SOLID_FILL,8);
      fillpoly(4,poly);
      font(6,1);
      outtextxy(105,getmaxy()-65,"HOW MANY DO YOU WISH TO ORDER ?");
      char ch[4], t[2];
      while(i<=2)
      {
	if(i==-1)
	  i=0;
	ch[i]=t[0]=getch();
	if(ch[i]==13)
	  break;
	else if(ch[i]==8)
	{
	  setcolor(8);
	  if(i==0)
	    i=1;
	  for(int j=1;j<=10;j++)
	     rectangle(355+((i-1)*8),x+j-2,355+((i)*8),x+6);
	  --i;
	  continue;
	}
	t[1]='\0';
	setcolor(4);
	outtextxy(355+(i*8),x,t);
	i++;
      }
      if(ch[i]==13)
	ch[i]='\0';
      ch[i]='\0';
      ch[3]='\0';
      for(int y5=0;y5[ch]!='\0';y5++);
      if(y5==1)
	q=ch[0]-48;
      else if(y5==2)
      {
	q=ch[1]-48;
	q+=(ch[0]-48)*10;
      }
      else
      {
	q=ch[2]-48;
	q+=(ch[1]-48)*10;
	q+=(ch[0]-48)*100;
      }
      if(q>qtt)
      {
	setcolor(4);
	outtextxy(105,getmaxy()-55,"SORRY, STOCKS ARE LESS... :(");
	outtextxy(105,getmaxy()-45,"PLEASE ENTER A LESSER QUANTITY");
	delay(2000);
      }
      else if(q<0 || (ch[0]<48||ch[0]>57))
      {
	setcolor(4);
	outtextxy(105,getmaxy()-55,"SORRY, ENTER VALID AMOUNT... :(");
	delay(2000);
	break;
      }
      else
      {
	outtextxy(105,getmaxy()-55,"SUCCESS... :)");
	delay(2000);
	f=0;
	break;
      }
    }
    if(f==0)
      return q;
    else
      return 0;
}
