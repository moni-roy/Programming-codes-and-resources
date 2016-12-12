int dp[2001][2001];
int EditDistance(string s,string ss) {
    int lf = s.size(),ls = ss.size();
    for(int i=0; i<=lf; i++) dp[i][0]=i;
    for(int i=0; i<=ls; i++) dp[0][i]=i;
    dp[0][0]=0;
    for(int i=1; i<=lf; i++) {
        for(int j=1; j<=ls; j++) {
            int t=(s[i-1]==ss[j-1])? 0:1;
            dp[i][j]=min(dp[i-1][j-1]+t,min(dp[i][j-1]+1,dp[i-1][j]+1));
        }
    }
    return dp[lf][ls];
}
