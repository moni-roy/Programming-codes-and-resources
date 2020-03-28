#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
char factorial[1010][100000];
char cop[100000],str[100000];
void revrs(char str[])
{
    int len = strlen(str);
    int x;
    for(int i=0,j=len-1;i<j;j--,i++)
    {
        x=str[i];
        str[i]=str[j];
        str[j]=x;
    }
    return ;
}
void FACTORIAL()
{
    strcpy(factorial[0],"1");
    strcpy(factorial[1],"1");
    strcpy(factorial[2],"2");
    strcpy(factorial[3],"6");
    for(int i=4;i<1005;i++)
    {
        strcpy(cop,factorial[i-1]);
        revrs(cop);
        int len=strlen(cop);
        int rem=0,sum=0,k;
        for(k=0;k<len;k++)
        {
            sum=rem+(cop[k]-'0')*i;
            rem=sum/10;
            str[k]=(sum%10)+'0';
        }
        mk:
        if(rem>9)
        {
            str[k]=(rem%10)+'0';
            k++;
            rem/=10;
            goto mk;
        }
        if(rem>0)
        {
            str[k]=rem+'0';
            k++;
        }
        str[k]='\0';
        revrs(str);
        strcpy(factorial[i],str);
    }
    return ;
}
int main()
{
    FACTORIAL();
    int num;
    while(cin>>num)
    {
        cout<<num<<"!"<<endl;
        puts(factorial[num]);
    }
    return 0;
}