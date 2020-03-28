#include <bits/stdc++.h>

using namespace std;

int sv[111][111];
int go(int n,int m){
    if(n>m) swap(n,m);
    if(n<=0) return 0;
    if(sv[n][m]!=-1) return sv[n][m];
    set<int>st;
    for(int i=1;i<=n/2+1;i++)
    {
        for(int j=1;j<=m/2+1;j++){
            int ret = go(i-1,j-1);
            ret ^= go(i-1,m-j);
            ret ^= go(n-i,j-1);
            ret ^= go(n-i,m-j);
            st.insert(ret);
        }
    }
    int mn = 0;
    for(auto x: st)
    {
        if(mn!=x) break;
        mn++;
    }
    return sv[n][m]=mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    memset(sv,-1,sizeof sv);
    int ts,n,m,Ans;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++)
        {
            sv[i][j]=sv[j][i]=go(i,j);
        }
    }
    cin>>ts;
    while(ts--){
        cin>>n>>m;
        Ans = sv[n][m];
        if(Ans) cout<<"1"<<endl;
        else cout<<"2"<<endl;
    }
    return 0;
}
