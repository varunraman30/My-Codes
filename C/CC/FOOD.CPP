#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<fstream.h>
#include<conio.h>

int ordline=0;


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



struct item                                  //STRUCTURE - FOOD IN ORDER TABLE
 {
	int cash,amount,q;
	char money2[4];
	char ming[25];
 }food1[5];

void append()
{
 for(int i=0; i<ordline-1; ++i)
    if(!strcmpi(food1[ordline-1].ming,food1[i].ming))
      {
       food1[i].q+=food1[ordline-1].q;
       food1[i].amount=food1[i].q*food1[i].cash;
       ordline--;
      }
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

void info()
{
 setcolor(1);
 font(6,1);
 outtextxy(getmaxx()/2-32,getmaxy()-10,"[PRESS 'Q' TO SPECIFY THE QUANTITY REQUIRED]");
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
	  feedbk(price,50,300);
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

food french[3]={food ('v',35,50,"THE WORLD'S BEST POTATOES HANDPICKED AND","DEEP FRIED TO TICKLE YOUR TASTE BUDS.","35","FRENCH","FRIES","SMALL"), food ('v',55,50,"THE WORLD'S BEST POTATOES HANDPICKED AND","DEEP FRIED TO TICKLE YOUR TASTE BUDS.","55","FRENCH","FRIES","LARGE"), food('v',60,50,"PUT A SMILE ON ANY KID'S FACE WITH THESE FUN SHAPED","POTATOES THAT HAVE A CRISPY AND MASHED POTATO INSIDE.","60","SMILES")};

food roll[2]={food('v',70,50,"FRESH VEGGIES ROCK IN A HOT NEW ROLE !! TASTE THE","FRESHNESS OF TOMATOES, LETTUCE AND PEPPER MAYO.","70","VEGGIE","ROLL"), food('n',95,50,"CHICKEN ROCKS IN A HOT NEW ROLE !! TASTE THE","FRESHNESS OF TOMATOES, LETTUCE AND PEPPER MAYO.","95","CHICKEN","ROLL")};

food krush[8]={food('v',50,50,"JUICY LEMON WEDGES WILL TEASE YOU.","FRENCH MINT LEAVES WILL TEMPT YOU.","50","VIRGIN","MOJITO"), food('v',60,50,"THIS PERFECT SUMMER COMPANION IS","LOADED WITH GREEN MANGO SYRUP.","60","GREEN","MANGO","JELLY"), food('v',75,50,"IT'S CRUSHED. IT'S A LIQUID, WELL ALMOST.","AND ITS AN OVERLOAD FOR A SNACK.","75","CHOCO","LASH"), food('v',70,50,"CHOCOLATE COOKIES AND PEANUT BUTTER TOPPED","WITH SINFUL CHOCOLATE SYRUP BLENDED.","70","CHOCOPEANUT","BOLT"), food('v',60,50,"IT'S MANGO. AND IT'S MUCH MORE BECAUSE IT HAS","CREAMY YOGURT AND ICY DAIRY SLUSH TOO.","60","MANGO","BURST"), food('v',60,50,"CRUNCHY STRAWBERRIES WITH CREAMY","YOGURT AND ICY DAITY SLUSH.","60","STRAWBERRY","SMOOTHIE"), food('v',85,50,"INDULGENT AND THICK, THE ICED CAPPUCINO IS A","STRONG COLD COFFEE TOPPED WITH DELICIOUS NUTS.","85","ICED","CAPPUCCINO"), food('v',95,50,"ICY AND THICK, THE ICED MOCHACCINO IS A DELICIOUS","MIX OF RICH DARK CHOCOLATE AND COFFEE.","95","ICED","MOCHACCINO")};

food combo[5]={food('n',789,20,"CONTENTS : 8 PCS BUCKET CHICKEN, ONE FRENCH FRIES LARGE,","ONE POPCORN CHICKEN, FIVE SMILES, ONE 1.25L COKE.","789","FAMILY","FEAST"), food('v',350,20,"CONTENTS : TWO VEGGIE BURGERS, TWO FRENCH FRIES","SMALL, TWO VEGGIE ROLLS, FIVE SMILES, TWO 300ML COKE.","350","VEGGIE","COMBO"), food('n',389,20,"CONTENTS : TWO ZINKER BURGERS, TWO FRENCH FRIES","SMALL, TWO CHICKEN ROLLS, FIVE SMILES, TWO 300ML COKE.","389","CHICKEN","COMBO"), food('n',140,20,"CONTENTS : THREE PCS STRIPS, ONE FRENCH","FRIES SMALL, ONE 300ML COKE","140","STANDARD","COMBO"), food('n',129,20,"CONTENTS : ONE KIDDY BURGER, ONE FRENCH FRIES","SMALL, ONE 300ML COKE, TWO EXCITING TOYS.","129","KIDDY","COMBO")};

food fry[7]={food('n',125,50,"TREAT YOUR TASTEBUDS TO SPICY, CRUNCHY, JUICY","CHICKEN THAT SETS YOUR TASTE BUDS ALIGHT.","125","2 PCS","CHICKEN"), food('n',235,50,"TREAT YOUR TASTEBUDS TO SPICY, CRUNCHY, JUICY","CHICKEN THAT SETS YOUR TASTE BUDS ALIGHT.","235","4 PCS","CHICKEN"), food('n',440,35,"MARINATED AND SEASONED WITH A BLEND OF HERBS","AND SPICES, AND THEN GRILLED TO PERFECTION.","440","8 PCS","CHICKEN"), food('n',635,25,"MARINATED AND SEASONED WITH A BLEND OF HERBS","AND SPICES, AND THEN GRILLED TO PERFECTION.","635","12 PCS","CHICKEN"), food('n',105,50,"A FUN CHICKEN WING APPETIZER THAT","MAKES YOU ASK FOR MORE AND MORE.","105","5 PCS","LOLLYPOP"), food('n',105,50,"TENDER, CRISPY AND JUICY BONELESS STRIPS","OF CHICKEN. A UNIQUE TREAT !","105","3 PCS","STRIPS"), food('n',80,50,"TENDER, JUICY PIECES OF HOT AND CRISPY CHICKEN WITH","EXTREME SPRINGLE, THAT YOU CAN POP NON-STOP !","80","POPCORN","CHICKEN")};

food burger[4]={food('n',90,50,"JUICY, CRISPY CHICKEN FILLET, TOPPED WITH ICEBERG","LETTUCE AND DELICIOUS MAYO, SERVED IN A SOFT SESAME BUN.","90","ZINKER","BURGER"), food('v',80,50,"A CRISPY FILLET OF 100 % REAL VEEGIES, TOPPED WITH","ICEBERG LETTUCE AND MAYO, SERVED IN A SOFT SESAME BUN.","80","VEGGIE","BURGER"), food('v',35,50,"A CRISPY FILLET OF THE BEST POTATOES, MASHED, TOPPED WITH","LETTUCE AND DELICIOUS MAYO, SERVED IN A SOFT SESAME BUN.","35","ALOO","TIKKI","BURGER"), food('n',55,50,"PUT A SMILE ON ANY KID'S FACE WITH","THESE AWESOME KID'S ONLY BURGERS.","55","KIDDY","BURGER")};

food icecream[7]={food('v',35,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","VANILLA ICE CREAM SERVED IN A CRISP CONE.","35","VANILLA"), food('v',35,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","STRAWBERRY ICE CREAM SERVED IN A CRISP CONE.","35","STRAWBERRY"), food('v',40,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","MANGO ICE CREAM SERVED IN A CRISP CONE.","40","MANGO"), food('v',40,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","CHOCOLATE ICE CREAM SERVED IN A CRISP CONE.","40","CHOCOLATE"), food('v',40,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","PISTA ICE CREAM SERVED IN A CRISP CONE.","40","PISTA"), food('v',40,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","BUTTER SCOTCH ICE CREAM SERVED IN A CRISP CONE.","40","BUTTER","SCOTCH"), food('v',45,50,"FAVOURITE OF ALL AGE GROUPS, DIG INTO EXQUISITE","CHOCO CHIP ICE CREAM SERVED IN A CRISP CONE.","45","CHOCO","CHIP")};

food coke125('v',60,50,"A CHILLING DRINK THAT REJUVINATES","YOUR BODY AND KEEPS YOU REFRESHED.","60","COKE","1.25L");				       //COKE 1.25L

food coke300('v',25,50,"A CHILLING DRINK THAT REJUVINATES","YOUR BODY AND KEEPS YOU REFRESHED.","25","COKE","200ML");

food new1[6]={food('v',1,1," "," "," "," "," "," "),food('v',1,1," "," "," "," "," "," "),food('v',1,1," "," "," "," "," "," "),food('v',1,1," "," "," "," "," "," "),food('v',1,1," "," "," "," "," "," "),food('v',1,1," "," "," "," "," "," ")};

void food :: display(int x, int y)
{
    while(1)
    {
	int midx = getmaxx() / 2;
	int poly[10]={100,getmaxy()-75,midx+75,getmaxy()-75,midx+75,getmaxy()-30,100,getmaxy()-30};
	setcolor(5);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,poly);
	char s[20];
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
	  veg(getmaxx()/2+100,getmaxy()/2+100,'s');
	else if(type=='n')
	  nonveg(getmaxx()/2+100,getmaxy()/2+100,'s');
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
	   }
	   continue;
	}
	else
	   continue;
    }
}




int food :: quantity(int qtt)                        //FUNCTION - QUANTITY ACCEPTER
{
    int q;
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
      char ch[3], t[2];
      while(i<=1)
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
      ch[i]='\0';
      q=10*(int)(ch[0]-48);
      q+=(int)(ch[1]-48);
      if(q>qtt)
      {
	setcolor(4);
	outtextxy(105,getmaxy()-55,"SORRY, STOCKS ARE LESS... :-(");
	outtextxy(105,getmaxy()-45,"PLEASE ENTER A LESSER QUANTITY");
	delay(2000);
      }
      else if(q<0)
      {
	setcolor(4);
	outtextxy(105,getmaxy()-55,"SORRY, ENTER VALID AMOUNT... :-(");
	delay(2000);
	break;
      }
      else
      {
	outtextxy(105,getmaxy()-55,"SUCCESS... :-)");
	delay(2000);
	break;
      }
    }
    return q;
}

void main()
{
food t('v',1,1," "," "," "," "," "," ");
int i=0;
fstream f("Food.dat",ios::in|ios::app);
while(i<=43)
{
   t=french[i++];
   f.write((char*)&t,sizeof(t));
}
}
