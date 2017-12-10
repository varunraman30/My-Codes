import java.util.Scanner;

public class Search 
{
	public static void bin(int a[],int n,int x)
	{
		int i,j,temp,pos=-10,f=0;
		for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		if(a[j+1]<a[j])
		{
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
		int l=0,u=n-1,m;	
		while(l<=u)
		{
			m=(l+u)/2;
			if(a[m]==x)
			{
				pos=m+1;
				f=1;
				break;
			}
			else if(a[m]<x)
				l=m+1;
			else
				u=m-1;				
		}
		if(f==0)
			System.out.println("Element Not Found in Array");
		else
			System.out.println("Element Found at : "+pos);
	}
	public static void main(String args[])
	{
		int a[]=new int[100];
		int n,i,x;
		Scanner s=new Scanner(System.in);
		System.out.print("Enter Number of Elements (Ascending Order) : ");
		n=s.nextInt();
		for(i=0;i<n;i++)
		{
			System.out.print("Element "+(i+1)+" : ");
			a[i]=s.nextInt();
		}
		System.out.print("Enter Element to be found : ");
		x=s.nextInt();
		bin(a,n,x);
		s.close();
		System.out.println("Exiting.......");
	}
}
