int n,seen[M],matchR[M];
vector<int>bpGraph[M]; 
bool bpm(int u){
    for(int v=0;v<(int)bpGraph[u].size();v++){
        int V=bpGraph[u][v];
        if(!seen[V]){
            seen[V]=true;
            if(matchR[V]==-1||bpm(matchR[V])){
                matchR[V]=u;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(){
    memset(matchR,-1, sizeof matchR);
    int result=0;
    for(int i=0;i<n;i++){
        memset(seen,0,sizeof seen);
        if(bpm(i)){
            result++;
        }
    }
    return result;
}
