int maxSumTwoNoOverlap(int* a, int s, int l, int m){
    int pr[1001];
    pr[0] = 0;
    for (int i = 1; i <= s; i++){
        pr[i] = pr[i-1]+a[i-1];
    }
    int ans = 0;
    for(int i = l; i<= s; i++){
        int sb = pr[i]-pr[i-l];
        for(int j = i+m; j<=s; j++){
            int ss = pr[j]-pr[j-m];
            ans = (ans<ss+sb)?ss+sb:ans;
        }
        for(int j = i-l;j-m>=0;j--){
            int ss = pr[j]-pr[j-m];
            ans = (ans<ss+sb)?ss+sb:ans;
        }
    }
    return ans;
}
