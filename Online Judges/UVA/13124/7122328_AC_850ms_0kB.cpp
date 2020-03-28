#include <bits/stdc++.h>

using namespace std;

string s[111];
int sv[33],vs[33],r,c,st[5][111][111][33];

void check()
{
    for(int k=1; k<=r; k++)
    {
        for(int i=1; i<=c; i++)
        {
            for(int ii=0;ii<27;ii++) st[1][k][i][ii] = st[1][k][i-1][ii];
            st[1][k][i][s[k-1][i-1]-'a']++;
        }
    }
    for(int i=1; i<=c; i++)
    {
        for(int k=1; k<=r; k++)
        {
            for(int ii=0;ii<27;ii++) st[2][k][i][ii] = st[2][k-1][i][ii];
            st[2][k][i][s[k-1][i-1]-'a'] ++;
        }
    }
    for(int k=1; k<=r; k++)
    {
        for(int i=1; i<=c; i++)
        {
            for(int ii=0;ii<27;ii++) st[3][k][i][ii] = st[3][k-1][i-1][ii];
            st[3][k][i][s[k-1][i-1]-'a']++;
        }
    }
    for(int k=r; k>0; k--)
    {
        for(int i=1; i<=c; i++)
        {
            for(int ii=0;ii<27;ii++) st[4][k][i][ii] = st[4][k+1][i-1][ii];
            st[4][k][i][s[k-1][i-1]-'a']++;
        }
    }
    return;
}

bool FIND(int l)
{
    int f=0,fl=0,fg=0,ff=0;
    for(int k=1; k<=r; k++)
    {
        for(int i=1; i<=c-l+1; i++)
        {
            int ii=i+l-1;
            f=1;
            for(int ll=0;ll<27;ll++)
            {
                int t = sv[ll];
                int tt = st[1][k][ii][ll]-st[1][k][i-1][ll];
                if(t!=tt) f=0;
            }
            if(f) break;
        }
        if(f) break;
    }
    for(int i=1; i<=c; i++)
    {
        for(int k=1; k<=r-l+1; k++)
        {
            int kk=k+l-1;
            fl=1;
            for(int ll=0;ll<27;ll++)
            {
                int t = sv[ll];
                int tt = st[2][kk][i][ll]-st[2][k-1][i][ll];
                if(t!=tt) fl=0;
            }
            if(fl) break;
        }
        if(fl) break;
    }
    for(int k=1; k<=r-l+1; k++)
    {
        for(int i=1; i<=c-l+1; i++)
        {
            int kk=k+l-1;
            int ii= i+l-1;
            ff=1;
            for(int ll=0;ll<27;ll++)
            {
                int t = sv[ll];
                int tt = st[3][kk][ii][ll]-st[3][k-1][i-1][ll];
                if(t!=tt) ff=0;
            }
            if(ff) break;
        }
        if(ff) break;
    }
    for(int k=r; k>=l; k--)
    {
        for(int i=1; i<=c-l+1; i++)
        {
            int kk = k-l+1;
            int ii = i+l-1;
            fg=1;
            for(int ll=0;ll<27;ll++)
            {
                int t = sv[ll];
                int tt = st[4][kk][ii][ll]-st[4][k+1][i-1][ll];
                if(t!=tt) fg=0;
            }
            if(fg) break;
        }
        if(fg) break;
    }
    return (f|fl|ff|fg);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q;
    while(cin>>r>>c>>q)
    {
        for(int i=0; i<r; i++)
        {
            cin>>s[i];
        }
//        memset(st,0,sizeof st);
        for(int i=0;i<27;i++){
            st[1][0][0][i]=0;
            st[2][0][0][i]=0;
            st[3][0][0][i]=0;
            st[4][0][0][i]=0;
            st[1][r+1][0][i]=0;
            st[2][r+1][0][i]=0;
            st[3][r+1][0][i]=0;
            st[4][r+1][0][i]=0;
        }
        check();
        int Ans=0;
        while(q--)
        {
            string p;
            cin>>p;
            for(int i=0; i<27; i++) sv[i]=0;
            for(int i=0; i<p.size(); i++)
            {
                sv[p[i]-'a']++;
            }
            if(FIND(p.size())) Ans++;
        }
        cout<<Ans<<endl;
    }
    return 0;
}
