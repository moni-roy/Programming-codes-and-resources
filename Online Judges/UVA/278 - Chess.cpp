#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,r,c,Ans;
    char ch;
    char s[100];
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(s);
        sscanf(s,"%c %d %d",&ch,&r,&c);
//        cout<<ch<<" "<<r<<" "<<c<<endl;
        if(ch=='r')
        {
            Ans=min(r,c);
            printf("%d\n",Ans);
        }
        if(ch=='k')
        {
            Ans=(r*c+1)/2;
            printf("%d\n",Ans);
        }
        if(ch=='Q')
        {
            Ans=min(r,c);
            printf("%d\n",Ans);
        }
        if(ch=='K')
        {
            Ans=((r+1)/2)*((c+1)/2);
            printf("%d\n",Ans);
        }
    }
    return 0;
}
