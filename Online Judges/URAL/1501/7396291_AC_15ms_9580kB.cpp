#include <bits/stdc++.h>
using namespace std;

bool sv[1001][1001][5];
bool vs[1001][1001][5];
string s,ss;
int n,m;

bool go(int x,int y,int f )
{
    if(x>=n && y>=m) return 1;
    bool &ret = sv[x][y][f];
    if(vs[x][y][f]) return ret;
    vs[x][y][f]=1;
    ret = 0;
    if(!f)
    {
        if(x<n) ret |=go(x+1,y,s[x]=='0'?1:2);
        if(y<m) ret |=go(x,y+1,ss[y]=='0'?1:2);
    }
    else if(f==1)
    {
        if(x<n) if(s[x]=='1') ret |=go(x+1,y,0);
        if(y<m) if(ss[y]=='1') ret |=go(x,y+1,0);
    }
    else
    {
        if(x<n) if(s[x]=='0') ret |=go(x+1,y,0);
        if(y<m) if(ss[y]=='0') ret |=go(x,y+1,0);
    }
    return ret;
}
void dekhao(int x,int y,int f )
{
    if(x>=n && y>=m)
    {
        cout<<endl;
        return ;
    }
    if(!f)
    {
        if(x<n && go(x+1,y,s[x]=='0'?1:2))
        {
            cout<<"1";
            dekhao(x+1,y,s[x]=='0'?1:2);
            return;
        }
        if(y<m && go(x,y+1,ss[y]=='0'?1:2))
        {
            cout<<2;
            dekhao(x,y+1,ss[y]=='0'?1:2);
            return;
        }
    }
    else if(f==1)
    {
        if(x<n && s[x]=='1' && go(x+1,y,0)){
            cout<<"1";
            dekhao(x+1,y,0);
            return;
        }
        if(y<m && ss[y]=='1' && go(x,y+1,0)){
            cout<<2;
            dekhao(x,y+1,0);
            return;
        }
    }
    else
    {
        if(x<n && s[x]=='0' && go(x+1,y,0))
        {
            cout<<"1";
            dekhao(x+1,y,0);
            return;
        }
        if(y<m && ss[y]=='0' && go(x,y+1,0))
        {
            cout<<2;
            dekhao(x,y+1,0);
            return;
        }
    }
}

int main()
{
    cin>>n;
    cin>>s>>ss;
    m = n;
    memset(vs,0,sizeof vs);
    bool ok = go(0,0,0);
    if(ok)
    {
        dekhao(0,0,0);
    }
    else cout<<"Impossible"<<endl;
    return 0;
}

