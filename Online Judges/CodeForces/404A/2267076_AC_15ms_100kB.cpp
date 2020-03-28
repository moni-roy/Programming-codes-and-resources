#include<bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    char str[350][350];
    cin>>num;
    int cn1=0,cnt2=0;
    for(int i=0; i<num; i++)
    {
        scanf("%s",str[i]);
    }
    int flag=0;
    int other=0;
    char ch1,ch2;
    ch1=str[0][0];
    ch2=str[0][1];
    if(ch1==ch2)
    {
        other=1;
        goto mk;
    }
    for(int i=0; i<num; i++)
    {
        if(str[i][i]!=str[i][num-1-i]||str[i][i]!=ch1)
        {
            flag=1;
            goto mk;
        }
    }
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            if(str[i][j]==ch1)
            {
                cn1++;
            }
            else if(str[i][j]==ch2)
            {
                cnt2++;
            }
            else
            {
                other =1;
                goto mk;
            }
        }
    }
    if(cn1!=num*2-1&&cn1+cnt2!=num)
    {
        other =1;
    }
    mk:
    if(other==0&&flag==0) puts("YES");
    else puts("NO");
    return 0;
}
