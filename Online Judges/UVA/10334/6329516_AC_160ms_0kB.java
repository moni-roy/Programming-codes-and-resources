/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
import java.util.Scanner;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		BigInteger fb[]=new BigInteger[1010];
		fb[0]=BigInteger.ONE;
		fb[1]=BigInteger.ONE;
		fb[1]=fb[1].add(fb[0]);
		for(int i=2;i<1002;i++){
			fb[i]=BigInteger.ZERO;
			fb[i]=fb[i].add(fb[i-1]);
			fb[i]=fb[i].add(fb[i-2]);
		}
		while(sc.hasNext()){
			int n=sc.nextInt();
			System.out.println(fb[n]);
		}
	}
}