#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
int bit[N];
const int extra = 5000;
vector<pair<int,int> > horizontal[N],vertical[N];
vector<int>visited[N];
long long result = 0;

void update(int p,int v){
    p++;
    while(p<N){
        bit[p]+= v;
        p += (p & (-p));
    }
}
int query(int p){
    int ret = 0;
    p++;
    while (p)
    {
        ret += bit[p];
        p -= (p & (-p));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,x,y,x1,y1;
    cin>>n;
    for(int i =0 ;i<n;i++){
        cin>>x>>y>>x1>>y1;
        x+=extra;
        y+=extra;
        x1+=extra;
        y1+=extra;
        if(y1==y){
            horizontal[y].push_back({min(x,x1),max(x,x1)});
        }
        else vertical[x].push_back({min(y,y1),max(y1,y)});
    }
    for(int y = 0;y<N;y++){
        for(auto tk: horizontal[y]){
            for(int i = 0;i<N;i++) {
                visited[i].clear();
            }
            memset(bit,0,sizeof bit);
            int l = tk.first;
            int r = tk.second;
            for(int x = l;x<=r;x++){
                for(auto tm: vertical[x]){
                    if(tm.first<=y && y<tm.second){
                        visited[tm.second].push_back(x);
                        update(x,1);
                    }
                }
            }
            for(int ny= y+1; ny<N;ny++){
                for(auto t: horizontal[ny]){
                    int ret = query(t.second) - query(t.first-1);
                    result+= ret*(ret-1)/2;
                }
                for(auto x: visited[ny]) update(x,-1);
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}
