#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;
//-------------------------------------

#define ll long long
#define ull unsigned long long
#define sc(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
#define sci(x) scanf("%d",&x)
#define sci2(x,y) scanf("%d%d",&x,&y)

#define F(i,a,b) for(i=a;i<b;i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define mem(x) memset(x,0,sizeof x)
#define all(x) x.begin(),x.end()
#define pb(x)  push_back(x);
#define xx first
#define yy second
#define inf 999999999999999
#define mkp(x,y) make_pair(x,y)
#define pii pair<ll,ll>
#define unq(x) x.resize(unique(x.begin(),x.end())-x.begin())
#define db(x) cerr<<#x<<" "<<x<<endl
#define db2(x,y) cerr<<#x<<" "<<x<<endl<<#y<<" "<<y<<endl<<endl

#define area(p1,p2,p3) (p1.xx*p2.yy+p2.xx*p3.yy+p3.xx*p1.yy-p1.yy*p2.xx-p2.yy*p3.xx-p3.yy*p1.xx)
#define dstt(u,v,x,y) ((ll)(x-u)*(ll)(x-u)+(ll)(y-v)*(ll)(y-v))
//---------------------------------------

#define MX 1000007
#define pi 2*acos(0.00)

#define open       freopen("input.txt","r",stdin)
#define close      freopen ("output.txt","w",stdout)


int BIT[MX];
void add(int p, ll vl)
{
    for(int i = p; i <= MX; i += (i & -i))BIT[i] += (ll)vl;
}

int read(int p)
{
    int ret = 0;
    for(int i = p; i > 0; i -= (i & -i)) ret += BIT[i];
    return ret;
}
int _sum(int a,int b)
{
    if(a>b) swap(a,b);
    return read(b)-read(a-1);
}
int asol[MX];
int main()
{
    ll i, j, l, u, v, w, x, y, z, a, b, c, d, e, f, t = 1, tc;
    ll flg, sz, cnt, gt, ans, mx, mn;
    ll m, k;
    ll low, hi, md, sm, ff;

    string st;
    vector<int> inp,tk;
    ll val,tot =0 ;
    while(cin >> st)
    {
        if(st=="#") val = -1;
        else
        {
            sz = st.size();
            val = 0;
            rep(i,0,sz) val = val*10+st[i]-'0';
        }
        tk.pb(val);
        inp.pb(val);
    }
    sz = tk.size();
    sort(all(tk));
    map<int,int> com;
    int id=1;
    mem(asol);
    rep(i,0,sz)
    {
        val = tk[i];
        if(com.find(val)==com.end())
        {
            com[val] = id;
            asol[id] = val;
            id++;
        }
    }
    tot = inp.size();
    int now = 0;
    rep(i,0,tot)
    {
        val = inp[i];
        if(val==-1)
        {
            int need;
            if(now%2==0) need = now/2+1;
            else need = (now+1)/2;

            low = 1,hi = id-1;
            int pos=0;
            while(low<=hi)
            {
                md = (low+hi)/2;
                sm = read(md);
                if(sm>=need) pos = md,hi=md-1;
                else low = md+1;
            }
            printf("%d\n",asol[pos]);
//            cout<<asol[pos]<<endl;
            add(pos,-1);

            if(now) now--;
            continue;
        }
        int com_id = com[val];
        add(com_id,1);
        now++;
    }




    return 0;
}


