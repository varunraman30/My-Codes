#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void show13()
{
   cout<<"\t\t\t00000   00000   00000   0   00000\n";
   cout<<"\t\t\t0   0   0   0     0     0       0\n";
   cout<<"\t\t\t00000   0   0     0     0   00000\n";
   cout<<"\t\t\t0  0    0   0     0     0       0\n";
   cout<<"\t\t\t0   0   00000     0     0   00000\n\n\n";
}
void main()
{
   int i;
   char s[100],r[100],c;
   clrscr();
   show13();
   cout<<"Enter String : ";
   gets(s);
   cout<<"\n1.To ROT13\n2.Reversal\n";
   cout<<"\nEnter Choice : ";cin>>c;
   switch(c)
   {
	case '1':
		   for(i=0;s[i];i++)
		   {
		      if(s[i]>='a'&&s[i]<='m')
			r[i]=s[i]+13;
		      else if(s[i]>='n'&&s[i]<='z')
			r[i]=s[i]-13;
		      else if(s[i]>='A'&&s[i]<='M')
			r[i]=s[i]+13;
		      else if(s[i]>='N'&&s[i]<='Z')
			r[i]=s[i]-13;
		      else
			r[i]=s[i];
		   }r[i]=0;
		   cout<<"Your String : ";puts(s);
		   cout<<"ROT13 String : ";puts(r);
		   break;
	case '2':
		   for(i=0;s[i];i++)
		   {
		      if(s[i]>='a'&&s[i]<='m')
			r[i]=s[i]+13;
		      else if(s[i]>='n'&&s[i]<='z')
			r[i]=s[i]-13;
		      else if(s[i]>='A'&&s[i]<='M')
			r[i]=s[i]+13;
		      else if(s[i]>='N'&&s[i]<='Z')
			r[i]=s[i]-13;
		      else
			r[i]=s[i];
		   }r[i]=0;
		   cout<<"ROT13 String : ";puts(s);
		   cout<<"Your String : ";puts(r);
   }
   getch();
}
