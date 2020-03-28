#include <bits/stdc++.h>
using namespace std;
#include <bitset>

vector<int>Ans;

int n,a[1000],sv[1055][111],tl,cs=0,cnt[111];
/*
int go11(int x,int y,int z)
{
    memset(cnt,0, sizeof cnt);

    int t=y%10;
    int tt=y/10;
    cnt[t]++;
    cnt[tt]++;
    if(cnt[tt]>1) return 0;
    if(cnt[t]>1) return 0;
    if((x&(1<<t))==0) return 0;
    if((x&(1<<tt))==0) return 0;


    t=z%10;
    tt=z/10;
    cnt[t]++;
    cnt[tt]++;
    if(cnt[tt]>1) return 0;
    if(cnt[t]>1) return 0;
    if((x&(1<<t))==0) return 0;
    if((x&(1<<tt))==0) return 0;

    return 1;
}
*/
int go1(int x,int y,int z)
{
    memset(cnt,0, sizeof cnt);

    int t=y;
    while(t!=0)
    {
        int ff=t%10;
        t=t/10;
        if((x&(1<<ff))==0 || cnt[ff]>0) return 0;
        cnt[ff]++;
    }

    t=z;
    while(t!=0)
    {
        int ff=t%10;
        t=t/10;
        if((x&(1<<ff))==0 || cnt[ff]>0) return 0;
        cnt[ff]++;
    }
    return 1;
}

int go(int x,int y)
{
    if(y<10 && (x&(1<<y))) return 1;
    for(int i=0; i<=y/2; i++)
    {
        if(i!=y-i)
        {
            if(go1(x,i,y-i)) return 1;
        }
    }
    if(y==100) return 0;
    int t=y%10;
    int tt=y/10;
    if(t==tt) return 0;
    if((x&(1<<t))==0) return 0;
    if((x&(1<<tt))==0) return 0;
    return 1;
}
int main()
{
//    bitset<32>tm(1024);
//    cout<<tm<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1; i<(1<<10); i++)
    {
        for(int j=0; j<=100; j++)
        {
            sv[i][j]=go(i,j);
        }

    }

    while(cin>>n)
    {
        if(n==0) break ;
        Ans.clear();
//        cout<<Ans.size()<<endl;
        for(int i=0; i<n; i++) cin>>a[i];

        for(int i=1; i<(1<<10); i++)
        {
            int f=1;
            for(int j=0; j<n; j++)
            {
                if(sv[i][a[j]]==0)
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                tl=0;
                for(int k=9; k>=0; k--)
                {
                    if((i&(1<<k)))
                    {
                        tl=tl*10+k;
                    }
                }
                Ans.push_back(tl);
            }
        }
        sort(Ans.begin(),Ans.end());
        cout<<"Case "<<++cs<<": "<<Ans[0]<<endl;

    }
    return 0;
}
