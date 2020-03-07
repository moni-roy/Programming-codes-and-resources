int main(){
    scanf("%d", &n);
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            scanf("%d", &mPref[i][j]);
            mPref[i][j] -= (n+1);
        }
    }
    for( int i = 0; i < n; i++ ){
        for( int j = 0; j < n; j++ ){
            scanf("%d", &k);
            wPref[i][k-1] = n - j;
        }
    }
    memset( R, -1, sizeof(R) );
    memset( P, 0, sizeof(P) );
    for( int i = 0; i < n; i++ ){
        int man = i;
        while( man >= 0 ){
            int woman = mPref[man][ P[man]++ ];
            if( R[woman] == -1 || wPref[woman][R[woman]]<wPref[woman][man]){
                L[man] = woman;
                swap( man, R[woman] );
            }
        }
    }
    for( int i = 0; i < n; i++ ) printf(" (%d %d)", i+1,L[i]+n+1);
}
