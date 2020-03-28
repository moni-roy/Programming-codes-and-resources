#include<stdio.h>
#include<string.h>
#include <math.h>
char fst[1000],snd[1000],sum[10000];
///function for maximum
int max(int m,int n)
{
    if(m>n) return m;
    else return n;
}
void strrev(char str[])
{
	int x,y=0,i;
	x=strlen(str);
	for(i=0,y=x-1;i<y;y--,i++)
	{
		int ch=str[i];
		str[i]=str[y];
		str[y]=ch;
	}
}
///function for two string sum
void string_sum(char mn[])
{
    int len1=strlen(sum);
    int len2=strlen(mn);
    int len=max(len1,len2);
    strrev(sum);
    strrev(mn);
    char smm[10000];
    int i=0,rem=0,sm=0;
    for(i=0; i<len; i++)
    {
        if(len1<=i) sum[i]='0';
        if(len2<=i) mn[i]='0';
        sm=(sum[i]-'0')+(mn[i]-'0')+rem;
        smm[i]=(sm%10)+'0';
        rem=sm/10;
    }
    if(rem>0)
    {
        smm[i]='1';
        i++;
    }
    smm[i]='\0';
    strcpy(sum,smm);
    strrev(sum);
}
/// function for multiple two string
void func(int x, int y)
{
    char cop[10000];
    int i,j=0;
    for(i=0; i<x; i++) // for insert right 0
    {
        cop[j++]='0';
    }
    int rem=0,sm=0;

    for(i=0; i<strlen(fst); i++)
    {
        sm=rem+(fst[i]-'0')*y;
        cop[j++]=(sm%10)+'0';
        rem=sm/10;
    }
    while(rem>9)
    {
        cop[j++]=rem%10+'0';
        rem/=10;
    }
    if(rem>0)
    {
        cop[j++]=rem+'0';
    }
    cop[j]='\0';
    strrev(cop);
    string_sum(cop);
}
int main()
{
    while(scanf("%s%s",fst,snd)==2)
    {
        int i;
        strrev(fst);
        for(i=strlen(snd)-1; i>=0; i--)
        {

            func(strlen(snd)-i-1,snd[i]-'0');
        }
        int mk=0,m=0;
        //char result[10000];
        while(sum[mk++]=='0');
        //printf("%s\n",sum);
        for(m=mk-1;m<strlen(sum);m++)
        {
			printf("%c",sum[m]);
		}
		if(mk>=strlen(sum))
		{
			printf("0");
		}
		puts("");
        strcpy(sum,"");
    }
    return 0;
}
