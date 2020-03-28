#include <bits/stdc++.h>
using namespace std;
typedef long long          	ll;
typedef long long unsigned 	llu;
#define pi                  acos(-1.0)
#define gcd(a,b)            __gcd(a,b)
template <class T> inline T BMOD(T p,T e,T m)
{
    T ret=1;
    while(e)
    {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
        e>>=1;
    }
    return (T)ret;
}
template <class T> inline T MODINV(T a,T m)
{
    return BMOD(a,m-2,m);
}
template <class T> inline T isPrime(T a)
{
    for(T i=2; i<=sqrt(double(a)); i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
template <class T> inline T lcm(T a, T b)
{
    return (a/gcd(a,b))*b;
}
template <class T> inline T power(T a, T b)
{
    return (b==0)?1:a*power(a,b-1);
}
template <class T> inline string toString(T t)
{
    stringstream ss;
    ss<<t;
    return ss.str();
}
template <class T> inline long long toLong(T t)
{
    stringstream ss;
    ss<<t;
    long long ret;
    ss>>ret;
    return ret;
}
//cout << fixed << setprecision(20) << Ans << endl;
//priority_queue<piii,vpiii, greater<piii> >pq; //for dijkstra

#define MX 510

int n,mPref[MX][MX],wPref[MX][MX],L[MX],R[MX],P[MX];
int main()
{
    int ts,cs=0;
    scanf("%d",&ts);
    while(ts--)
    {
        scanf("%d", &n);
        int k;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &k);
            for( int j = 1; j <= n; j++ )
            {
                int K;
                scanf("%d", &K);
                wPref[k][K] = j;
            }
        }
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d",&k);
            for( int j = 1; j <= n; j++ )
            {
                scanf("%d", &mPref[k][j]);
            }
        }
        memset( R, -1, sizeof(R) );

        for(int i=0; i<=n; i++) P[i]=1;

        for( int i = 1; i <= n; i++ )
        {
            int man = i;
            while( man >= 1 )
            {
                int woman = mPref[man][ P[man]++ ];
//                cout<<woman<<endl;
//                getchar();
                if( R[woman] == -1 || wPref[woman][R[woman]]>wPref[woman][man])
                {
                    L[man] = woman;
                    swap( man, R[woman] );
                }
            }
        }
        for( int i = 1; i <= n; i++ ) printf("%d %d\n", i,L[i]);
    }
    return 0;
}

/*

2
4
1 4 3 1 2
2 2 1 3 4
3 1 3 4 2
4 4 3 1 2
1 3 2 4 1
2 2 3 1 4
3 3 1 2 4
4 3 2 4 1
7
1 3 4 2 1 6 7 5
2 6 4 2 3 5 1 7
3 6 3 5 7 2 4 1
4 1 6 3 2 4 7 5
5 1 6 5 3 4 7 2
6 1 7 3 4 5 6 2
7 5 6 2 4 3 7 1
1 4 5 3 7 2 6 1
2 5 6 4 7 3 2 1
3 1 6 5 4 3 7 2
4 3 5 6 7 2 4 1
5 1 7 6 4 3 5 2
6 6 3 7 5 2 4 1
7 1 7 4 2 6 5 3

*/
