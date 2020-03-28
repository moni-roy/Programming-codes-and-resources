#include <bits/stdc++.h>
using namespace std;
#define I(a) scanf("%d",&a)

int main()
{
    int a;
    while(I(a)==1)
    {
        if(a==-1) break;
        printf("Round %d\n",a);
        char s1[10001],s2[10001];
        scanf("%s",s1);
        scanf("%s",s2);
        int l1=strlen(s1);
        int l2=strlen(s2);
        map<char,int>mp;
        set<char>st;
        for(int i=0; i<l1; i++)
        {
            mp[s1[i]]=1;
            st.insert(s1[i]);
        }
        int f=0,fl=0,cnt=0;
        for(int i=0; i<l2; i++)
        {
            if(mp[s2[i]]==1)
            {
                cnt++;
                mp[s2[i]]=2;
            }
            else if(mp[s2[i]]==0) fl++;
            if(fl>=7)
            {
                f=1;
                puts("You lose.");
                break;
            }
            if(cnt==st.size())
            {
                f=1;
                puts("You win.");
                break;
            }
        }
        if(!f)
        {
            puts("You chickened out.");
        }
    }
    return 0;
}
