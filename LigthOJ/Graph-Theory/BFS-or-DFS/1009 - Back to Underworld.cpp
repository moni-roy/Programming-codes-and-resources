#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define scl(a) scanf("%lld",&a)
#define sc(a) scanf("%d",&a)
#define zero(a) memset(a,0,sizeof a)
vector<int>edge[20005];
bool vis[20005];
int ck[20005];
int mx,mn;
void BFS(int st){
    queue<int>q;
    q.push(st);
    vis[st]=1;
    ck[st]=1;
    mx=1;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<(int)edge[u].size();i++){
            int v=edge[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
                ck[v]=ck[u]*(-1);
                if(ck[v]==1){
                    mx++;
                }
                else mn++;
            }
        }
        q.pop();
    }
}
int main(){
    int ts,cs=0;
    sc(ts);
    while(ts--){
        int n;
        sc(n);
        for(int i=0;i<n;i++){
            int u,v;
            sc(u),sc(v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        zero(vis);
        ll cnt=0;
        for(int i=1;i<=20000;i++){
            if(!vis[i] && edge[i].size()>0)
            {
                mn=0,mx=0;
                BFS(i);
                cnt+=max(mn,mx);
            }
        }
        printf("Case %d: %lld\n",++cs,cnt);
        for(int i=0;i<20005;i++){
            edge[i].clear();
        }
    }
    return 0;
}
