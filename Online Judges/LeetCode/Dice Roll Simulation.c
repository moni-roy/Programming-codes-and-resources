int dp[5001][7][17];
const int Mod = 1000000007;
int RollMax[5001];
int N;

int rec(int pos, int last, int cnt){
    if(pos >= N) return 1;
    if(dp[pos][last][cnt] != -1) return dp[pos][last][cnt];
    int ret = 0;
    for(int dc=1; dc<=6; dc++){
        if(dc == last && RollMax[dc - 1] > cnt){
            ret = (ret + rec(pos + 1, last, cnt + 1) % Mod) % Mod;
        }
        else if(dc != last){
            ret = (ret + rec(pos + 1, dc, 1) % Mod) % Mod;
        }
    }
    dp[pos][last][cnt] = ret;
    return dp[pos][last][cnt];
}

int dieSimulator(int n, int* rollMax, int rollMaxSize){
    for(int i=0; i<=n; i++){
        
        for(int j=0; j<=6; j++){
            for(int k=0; k<16; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(int i=0; i<rollMaxSize; i++) RollMax[i] = rollMax[i];
    N = n;
    return rec(0, 0, 0);
}
