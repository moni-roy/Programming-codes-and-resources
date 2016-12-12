// Cumulative Sum of Divisors of 1 to n
int CSOD(int n) {
    int sq=sqrt(n);
    int Ans=0;
    for(int i=1; i<=sq; i++) {
        int j=n/i;
        Ans+=i*(j-i);
        Ans+=(i+j)*(j-i+1)/2;
    }
    return Ans;
}
// Sum of number of Divisor of 1 to n
int SNOD( int n ) {
    int res = 0;
    int u = sqrt(n);
    for ( int i = 1; i <= u; i++ ) {
        res += ( n / i ) - i; //Step 1
    }
    res *= 2; //Step 2
    res += u; //Step 3
    return res;
}
