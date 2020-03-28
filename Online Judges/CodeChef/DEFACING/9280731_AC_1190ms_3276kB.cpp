#include <bits/stdc++.h>
using namespace std;
int ts,l,n;
char s[100],m[100];
vector <int>sv[11];
void pre()
{
    // 0-> 0,8
    sv[0].push_back(0);
    sv[0].push_back(8);
    //1->0,1,3,4,7,8,9
    sv[1].push_back(0);
    sv[1].push_back(1);
    sv[1].push_back(3);
    sv[1].push_back(4);
    sv[1].push_back(7);
    sv[1].push_back(8);
    sv[1].push_back(9);
    //2 ->2,8
    sv[2].push_back(2);
    sv[2].push_back(8);
    //3-> 3,8,9
    sv[3].push_back(3);
    sv[3].push_back(8);
    sv[3].push_back(9);
    //4-> 4,8,9
    sv[4].push_back(4);
    sv[4].push_back(8);
    sv[4].push_back(9);
    //5-> 5,6,8,9
    sv[5].push_back(5);
    sv[5].push_back(6);
    sv[5].push_back(8);
    sv[5].push_back(9);
    //6-> 6,8
    sv[6].push_back(6);
    sv[6].push_back(8);
    //7-> 0,3,7,8,9
    sv[7].push_back(0);
    sv[7].push_back(3);
    sv[7].push_back(7);
    sv[7].push_back(8);
    sv[7].push_back(9);
    //8->8
    sv[8].push_back(8);
    //9->8,9
    sv[9].push_back(8);
    sv[9].push_back(9);

    // 10->0 1 2 3 4 5 6 7 8 9
    sv[10].push_back(0);
    sv[10].push_back(1);
    sv[10].push_back(2);
    sv[10].push_back(3);
    sv[10].push_back(4);
    sv[10].push_back(5);
    sv[10].push_back(6);
    sv[10].push_back(7);
    sv[10].push_back(8);
    sv[10].push_back(9);
}

int go(int p,int t,string &ss)
{
    if(n==p) return t;
    int ret=0;
    for(int i=0; i<(int)sv[ss[p]-'0'].size(); i++)
    {
        int tt = t;
        if( sv[ss[p]-'0'][i]<(m[p]-'0'))
        {
            tt*=10;
            tt+=sv[ss[p]-'0'][i];
            for(int j = p+1; j<n; j++)
            {
                tt*=10;
                int ii = sv[ss[j]-'0'].size()-1;
                tt+=sv[ss[j]-'0'][ii];
            }
            ret= max(ret,tt);
        }
        else if (sv[ss[p]-'0'][i]==(m[p]-'0'))
        {
            tt*=10;
            tt+=sv[ss[p]-'0'][i];
            ret = max(ret,go(p+1,tt,ss));

        }
    }
    return ret;
}

int main()
{

    pre();

    scanf("%d",&ts);
    while(ts--)
    {
        scanf("%s%s",&s,&m);
        l = strlen(s);
        n = strlen(m);
        int Ans = 0;
        string s1=s;
        for(int i=0;i<10;i++)
        {
            string ss=s1;
            while(ss.size()<n)
            {
                ss+=":";
            }
            Ans = max(Ans,go(0,0,ss));
            s1 = ":"+s1;
            if(s1.size()>n) break;
        }
        cout<<Ans<<endl;
    }
    return 0;
}
