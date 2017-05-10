/*
 * Sample code from topcoder
 * This code for UVA-10003:Cutting Sticks
 * */
ll x[55],res[55][55],mid[55][55],k;
int main()
{
    cin>>k;
    for(int i=1;i<=k;i++) cin>>x[i];
    x[0]=0;
    x[++k]=l;
    for (int s = 0; s<=k; s++) //s - length(size) of substring
    {
        for (int L = 0; L+s<=k; L++)//L - left point
        {
            int R = L + s;          //R - right point
            if (s < 2)
            {
                res[L][R] = 0;      //DP base - nothing to break
                mid[L][R] = L;      //mid is equal to left border
                continue;
            }
            int mleft = mid[L][R-1]; //Knuth's trick: getting bounds on M
            int mright = mid[L+1][R];
            res[L][R] = 1000000000000000000LL;
            for (int M = mleft; M<=mright; M++)//iterating for M in the bounds only
            {
                ll tres = res[L][M] + res[M][R] + (x[R]-x[L]);
                if (res[L][R] > tres)         //relax current solution
                {
                    res[L][R] = tres;
                    mid[L][R] = M;
                }
            }
        }
    }
    ll Ans = res[0][k];
    return 0;
}
