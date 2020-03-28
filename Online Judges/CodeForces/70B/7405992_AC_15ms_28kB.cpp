#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sz;
    string s;
    cin>>sz;
    getchar();
    getline(cin,s);
    int l =s.size();
    int pr = -1,ok=-1,Ans = 0,cnt=0,f=0;
    for(int i=0; i<l; i++)
    {
        if(!f && s[i]==' ')
        {
            ok++;
            continue;
        }
        f=1;
        cnt++;
        if(s[i]=='.'||s[i]=='?'||s[i]=='!')
        {
//            cout<<i<<" "<<ok<<" "<<pr<<" "<<cnt<<endl;
            if(cnt==sz)
            {
                Ans++;
                ok=i;
                cnt = 0;
                f=0;
            }
            else if(cnt>sz)
            {
                if(ok<pr)
                {
                    if(pr-ok+1<=sz) Ans++;
                    else
                    {
                        cout<<"Impossible"<<endl;
                        return 0;
                    }
                    cnt = i-pr;
                    int k = pr+1;
                    while(s[k++]==' ') cnt--;
                    ok=k-1;
                }
                else if(ok>=pr)
                {
                    cout<<"Impossible"<<endl;
                    return 0;
                }
            }
            pr=i;
        }
    }
    if(cnt>sz)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(cnt) Ans++;
    cout<<Ans<<endl;
    return 0;
}
/*
10
hello! how are you?

16
Abacaba. Abacaba. abacaba. abacab.

6
jhf. fj. hjgfgj. fjfj.

*/
