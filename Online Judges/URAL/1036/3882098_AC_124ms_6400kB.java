import java.util.*;
import java.math.*;

public class Main{
	static Scanner sc=new Scanner(System.in);
	public static void main(String[] args){
		
		BigInteger[][] sv=new BigInteger[100][1010];
		int n,s;
		n=sc.nextInt();
		s=sc.nextInt();
		if(s%2==1){
			System.out.println("0");
		}
		else{
			for(int i=0;i<51;i++){
				for(int j=0;j<1010;j++){
					sv[i][j]=BigInteger.ZERO;
				}
			}
			for(int i=0;i<=9;i++){
				sv[1][i]=BigInteger.ONE;
			}
			for(int i=2;i<=n;i++){
				for(int j=0;j<=s;j++){
					for(int k=0;k<=9;k++){
						if(j-k<0) break;
						sv[i][j]=sv[i][j].add(sv[i-1][j-k]);
					}
				}
			}
			System.out.println(sv[n][s/2].multiply(sv[n][s/2]));
		}
	}
}
		
