import java.util.Scanner;
import static java.lang.Math.pow;

public class Main {
	
	static Scanner sc=new Scanner(System.in);
	
	public static void main (String args[]) {
		int tst,n,i,t;
		tst=sc.nextInt();
		for(t=0;t<tst;t++)
		{
			long ans=0;
			n=sc.nextInt();
			//for(i=1;i<15;i++)
			//{
			//	ans+=n/java.lang.Math.pow(5.0,i);
			//}
			while(n>0)
			{
				ans+=n/5;
				n/=5;
			}
			System.out.print(ans);
			System.out.println("");
		}
		
	}
}
