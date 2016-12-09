#include <bits/stdc++.h>
using namespace std;
#define MX 500

int dx[]= {-2,-2,1,-1,-3,-1};
int dy[]= {1,-1,-2,-2,-1,-3};

int sv[MX+5][MX+5];
int grandy(int x,int y) {
    if(x==0 && y==0) return 0;
    if(sv[x][y]!=-1) return sv[x][y];
    set<int>st;
    for(int i=0; i<6; i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx>=0 && xx<=MX && yy>=0 && yy<=MX)
            st.insert(grandy(xx,yy));
    }
    int mn = 0;
    while(st.count(mn)) mn++;
    return (sv[x][y]=mn);
}
int main() {
    int Ans,n,x,y,cs=0,ts;
    cin>>ts;
    memset(sv,-1,sizeof sv);
    while(ts--) {
        cin>>n;
        Ans=0;
        for(int i=0; i<n; i++) {
            cin>>x>>y;
            Ans ^= grandy(x,y);
        }
        cout<<"Case "<<++cs<<": ";
        if(Ans) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}


