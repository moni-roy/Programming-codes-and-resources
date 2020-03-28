#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, d, ln, ans, a[1000007];
    cin >> n >> d;

    for(int i = 0; i < n; i++) cin >> a[i];

    ans = 0;
    a[n] = 9999999999;
    n++;

    for(int i = 0; i < n - 3; i++)
    {
        ln = lower_bound(a, a + n, a[i] + d + 1) - a;
        //cout << ln << endl;

        long long ck = ln - i - 1;
        if(ck >= 2)
        {
            if(ck == 2) ans += 1;
            else
            {
               //cout<<ck<<endl;
                ans =ans + ((ck * (ck - 1)) / 2);
            }
        }
       // cout<<"LLLL "<<ans<<endl;
    }

    cout << ans << endl;
}
