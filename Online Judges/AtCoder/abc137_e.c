#include <stdio.h>
#define MXSZ 5005
#define INF 10000000001
typedef struct mk{
    long long u,v,c;
}data;
data input[MXSZ];
long long cost[MXSZ];
long long max(long long a,long long b){return (a<b)?b:a;}
long long min(long long a,long long b){return (a>b)?b:a;}
void bellmanFord(long long n,long long m){
    for(int i = 0;i<=n;i++) cost[i] = INF;
    cost[1]= 0;
    for(int i = 0;i<n+n;i++){
        for(int j = 0;j<m;j++){
            long long u = input[j].u;
            long long v = input[j].v;
            long long c = input[j].c;
            if(cost[u]!=INF && cost[u]+c<cost[v]){
                if(i<=n) cost[v] = max(-INF, min(INF,cost[u]+c));
                else cost[v] = -INF;
            }
        }
    }
}
void MRoy(){
    long long n,m,p,a,b,c;
    scanf("%lld%lld%lld",&n,&m,&p);
    for(long long i = 0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        input[i].c = -c+p;
        input[i].u = a;
        input[i].v = b;
    }
    bellmanFord(n,m);
    if(cost[n]==-INF) printf("-1\n");
    else printf("%lld\n",max(0,-cost[n]));
}
int main(){
    MRoy();
    return 0;
}