#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, a[4], Ans = 1, f = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[0] + a[1] <= a[2]) f = 0;
        Ans &= f;
    }
    if (Ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
