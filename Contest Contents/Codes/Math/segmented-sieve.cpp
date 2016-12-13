/*
 * Firstly, generate all primes less than √N
 */
int arr[SIZE];
///Returns number of primes between segment [a,b]
int segmentedSieve ( long long a, long long b ) {
    if ( a == 1 ) a++;
    int sqrtn = sqrt ( b );
    memset ( arr, 0, sizeof arr ); ///Make all index of arr 0.
    for ( int i = 0; i < prm.size() && prm[i] <= sqrtn; i++ ) {
        int p = prm[i];
        long long int j = p * p;
        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; ///mark them as not prime
        }
    }
    int res = 0;
    for ( long long i = a; i <= b; i++ ) {
        ///If it is not marked, then it is a prime
        if ( arr[i-a] == 0 ) res++;
    }
    return res;
}
