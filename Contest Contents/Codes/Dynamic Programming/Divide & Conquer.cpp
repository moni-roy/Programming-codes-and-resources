/*
 * This solution for divide k group of a array
 * */
ll n,k,sv[5005],dp[5005][5005];
bool vis[5005][5005];
ll Cost(int l,int r){
    return (sv[r]-sv[l]);
}
void Func(int l,int r,int x,int y){
    if(l>r) return;
    int mid=(l+r)>>1;
    if(vis[mid][k]) return;
    ll &res=dp[mid][k];
    res=INT_MAX;
    int Id=-1;
    for(int i=x;i<=min(y,mid);i++) {
        ll Tp=dp[i][k-1]+Cost(i+1,mid);
        if(res>Tp) {
            res=Tp,Id=i;
        }
    }
    Func(l,mid-1,x,Id);
    Func(mid+1,r,Id,y);
}
void Solve(int K,int n){
    for(int i=1;i<=n;i++ ) {
        dp[i][1]=Cost(1,i);
    }
    for(int i=2;i<=K;i++) {
        k=i;
        Func(1,n,1,n);
    }
    cout<<dp[n][k]<<endl;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>sv[i];
    }
    Solve(k,n);
    return 0;
}
