import java.util.Scanner;
public class Main
{
	static Scanner sc= new Scanner(System.in);
	public static void main(String args[])
	{
		int n,k,ans=0;
		int tst=sc.nextInt();
		while(tst-->0)
		{
			ans=0;
			n=sc.nextInt();
			k=sc.nextInt();
			///while(n>0)
			///{
			///	int m=n/k;
			///	ans+=n-m;
			///	n=m/k;
			///}
			ans=f(n,k);
			System.out.println(ans);
		}
	}
	public static int f(int n,int k)
	{
		if(n<1) return n;
		return n-n/k+f((n/k)/k,k);
	}
}