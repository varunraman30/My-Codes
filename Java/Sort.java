import java.util.Scanner;

public class Sort 
{
	public static void Asc_sort(int a[],int n)
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		if(a[j+1]<a[j])
		{
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
		System.out.print("After Sorting : ");
		for(i=0;i<n;i++)
			System.out.print(a[i]+ " ");	
	}
	public static void Des_sort(int a[],int n)
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		if(a[j+1]>a[j])
		{
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
		System.out.print("After Sorting : ");
		for(i=0;i<n;i++)
			System.out.print(a[i]+ " ");		
	}
	public static void main(String[] args) 
	{
		int a[]=new int[100];
		int n,i,c;
		Scanner s=new Scanner(System.in);
		System.out.print("Enter Number of Elements : ");
		n=s.nextInt();
		for(i=0;i<n;i++)
		{
			System.out.print("Element "+(i+1)+" : ");
			a[i]=s.nextInt();
		}
		System.out.print("Before Sorting : ");
		for(i=0;i<n;i++)
			System.out.print(a[i]+" ");
		System.out.print("\n\nAscending or Descending (1-2) ? : ");
		c=s.nextInt();			
		switch(c)
		{
			case 1: Asc_sort(a,n);					
				 	break;
			case 2: Des_sort(a,n);				
					break;
			default: System.out.println("Select Valid Choice...");
		}
		System.out.print("\nExiting......");
		s.close();
	}
}
